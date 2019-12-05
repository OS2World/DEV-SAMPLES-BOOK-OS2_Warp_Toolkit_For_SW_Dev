
/******************************************************************************
*
*  The OS/2 Warp Toolkit for Software Developers
*
*  Prentice Hall (c) 1995
*
* Name          : ReadFile()
*
* Description   : This function reads the file into memory. It
*                 checks for a valid read and returns the number of
*                 bytes actually read.
*
* Parameters    :
*               InCount         - Number of bytes to read as determined in main
*              *InFile          - The Input File Pointer
*              *BaseAddress     - Where the data is to be stored
*
* Return        :
*               BytesRead       - Number of bytes read
*
******************************************************************************/
#include <stdio.h>
#include "decode.h"

char ScanType[15];
long ReadFile( long int InCount, FILE *InFile, unsigned char *BaseAddress)
{

        long   BytesRead;
        int    i;

        BytesRead = fread(BaseAddress, sizeof(char), InCount, InFile);

        if(BytesRead == 0){
                printf("Read Fail on Input file\n");
                BytesRead = 0;
        }

        /* Check to see if this is valid .OBJ or .LIB file */

        if((*BaseAddress != 0x80) && (*BaseAddress != 0xF0)){
                printf("\nNot a valid .OBJ or .LIB file\n");
                BytesRead = 0;
                return BytesRead;
        }
        if(*BaseAddress == 0xF0){

                printf("Since this is a .LIB file, please enter the type of record you\n\
wish to scan for. Press enter for no records. Selecting \"ALL\" may cause\n\
the program to run for a long time.\n\n");

                printf("Choices are:\n\n"
                      "\nTHEADR   <Gives Source/.OBJ module names>"
                      "\nCOMENT   <Can help determine which DLL/Ordinal>"
                      "\nALL      <Outputs all records, can take time>"
                      "\n<Enter>  <Default- No output files produced>\n\n\n");

                gets(ScanType);
                for (i = 0 ; i <= strlen(ScanType); i++)
                        ScanType[i] = toupper(ScanType[i]);


                if (!strcmp("THEADR", ScanType)) Show =    0x80;
                else if (!strcmp("COMENT", ScanType)) Show =    0x88;
                else if (!strcmp("ALL",    ScanType)) Show =    0xFF;
                else Show = NO;
        }


        printf("\n\n\n");
        return BytesRead;
}
