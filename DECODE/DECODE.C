/********************DECODE.C Source for .OBJ file Decoder*********************
*
*  The OS/2 Warp Toolkit for Software Developers
*
*  Prentice Hall (c) 1995
*
*
* PROGRAM NAME:  DECODE.EXE
* -----------------------
* Text mode program to decode .OBJ & .LIB files created in the Tools Interface
* Standards (TIS) Relocatable Object Module Format (OMF)
*
* WHAT THIS PROGRAM DOES:
* -----------------------
* This program reads .OBJ or .LIB files and creates, xxx.REC and optionally
* xxx.DMP in the current directory. xxx.REC contains the record level
* information in both HEX and ASCII format. xxx.DMP is a complete dump
* of the file in both HEX and ASCII format. There is an options which
* send output to the screen and create the dump (.DMP) file.
*
* WHAT THIS PROGRAM DEMONSTRATES:
* -------------------------------
* This program demonstrates the makeup of .OBJ & .LIB  files created by 16 bit
* and 32 bit compilers and assemblers.
*
* WHAT DO YOU REQUIRE TO COMPILE THIS PROGRAM:
* --------------------------------------------
*
* REQUIRED FILES:
* ---------------
* DECODE.C        - Main function source
* PRTFILE.C       - PrintFile function source
* INTFILE.C       - IntFile function source
* READFILE.C      - ReadFile function source
* DECODE.H        - Header file
* DECODE.MAK      - Make file
* STRING.H        - String handling function definitions
* STDIO.H         - Constants, function defintions etc. for stream I/O
* STDLIB.H        - Function definitions for standard functions
*
* REQUIRED LIBRARIES:
* -------------------
* OS2386.LIB    - OS/2 32 bit Import Library
* DDE4SBS.LIB   - C Set/2 Single Thread Standard Library
*
* REQUIRED PROGRAMS:
* ------------------
*
* IBM C Compiler
* IBM Linker
*
* COMPILE OPTIONS:
* ----------------
*
*                 nmake -f decode.make clean (will remove unnecessary files)
*
*                 nmake -f decode.make (to build)
*
* NOTE:     Each file can be compiled separately and the .OBJs linked
*           to produce the executable.
*
* COMMAND LINE:
* -------------
*
*                decode xxx.yyy (xxx = valid .OBJ or .LIB file name)
*
*                decode xxx.yyy [/s] [/d]
*                       /s or /S produces optional screen otput
*                       /d or /D produces optional .DMP file
******************************************************************************/

/*****************************************************************************
*  Name         : main()
*
*  Description  : Check for valid arguments and file names. Opens input
*  and output files.
*
*  Parameters   : Name of a valid .OBJ or .LIB file. If screen output is
*  desired, follow with a /s, if the optional .DMP file is desired, add /d.
*
*  Returns      : None
*
*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "decode.h"                       /* App. Header File */

void main(int argc, char *argv[])
{

        /*
Variables
*/

        char   FileName[100];
        long   Bytes;
        unsigned char  *BaseAddress;
        long   BytesRead;
        long   InCount;
        short  i;
        char   Rec[15], Dump[15];
        OutFlag = DumpFlag = 0;

        /*
 Get basename of input file and create output file names
*/


        if(argv[1] != NULL){
                for(i = 0; i <= strlen(argv[1]); i++)
                        FileName[i] = toupper(argv[1][i]);
        } else{
                fprintf(stderr,"\nFormat:   DECODE xxx.yyy [/s] [/d] \n");
                return;
        };


        for (i = 0 ; argv[1][i] != '.'; i++){
                if(argv[1][i] != '\0'){
                        Dump[i] = toupper(argv[1][i]);
                        Rec[i]  = toupper(argv[1][i]);
                } else {
                        fprintf(stderr,"\nFormat:  DECODE xxx.yyy [/s] [/d]\n");
                        return;
                }
        };

        Dump[i] = '\0';
        Rec[i]  = '\0';
        strcat(Rec,".REC");
        strcat(Dump, ".DMP");


        if((InFile = fopen(FileName, "rb")) == NULL){
                fprintf(stderr, "\nInvalid File Name, re-enter a valid .OBJ or .LIB file\n");
                return;
        };

        fseek (InFile, 0L, SEEK_END);         /* Determine file size */
        InCount = ftell(InFile);
        fseek (InFile, 0L, SEEK_SET);         /* Return to beginning of file */

        /* Get storage to match file size */

        if((BaseAddress = malloc(InCount)) == NULL){
                fprintf(stderr,"Storage Allocation error");
                return;
        };

        for( i = 1; i <= (argc -1); i++){            /* Screen output desired? */
                if(!strncmp(argv[i], "/s" , sizeof(argv[i])) ||
                    (!strncmp(argv[i], "/S", sizeof(argv[i]))))
                        OutScrn =YES;

                if(!strncmp(argv[i], "/d" , sizeof(argv[i])) ||
                    (!strncmp(argv[i], "/D", sizeof(argv[i]))))
                        DumpFlag =YES;
        };


        Bytes = ReadFile(InCount, InFile, BaseAddress);   /* Read in the .OBJ */

        if (Bytes){

                if(DumpFlag){
                        if((DumpFile = fopen(Dump, "w+")) == NULL){
                                printf("Could not open %s\n", Dump);
                                return;
                        }
                }
                if((RecFile  = fopen(Rec , "w+")) == NULL){
                        printf("Could not open %s\n", Rec);
                        return;
                }

                /*
Interpret file using the pointer to the location in memory where it
was read in to
*/

                IntFile(BaseAddress);


                if(DumpFlag){
                        OutFlag = 1;                  /* OutFlag on indicates a full .OBJ dump */
                        PrintFile(InCount, BaseAddress, 0);
                        OutFlag = 0;
                };

                printf("\n\nThe file %s contains %ld bytes in %d records.\n\n",
                    FileName, Bytes, RecCount);
                printf("Examine %s and %s with a text editor for details.\n\n",
                    Rec, Dump);
                printf("(NOTE:%s will not exist unless you used the /d option.)\n\n",
                    Dump);
        };

        fclose(InFile);      /* Clean Up */
        fclose(DumpFile);
        fclose(RecFile);
        free(BaseAddress);
        return;
}
