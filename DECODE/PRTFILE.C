/****************************************************************************
*
*  The OS/2 Warp Toolkit for Software Developers
*
*  Prentice Hall (c) 1995
*
*  Name         : PrintFile()
*
*  Description  : This function outputs the information to the output
*                 files. It additionally will output to the screen if the
*                 /s option is set.
*
*
*  Paramters    :
*
*               count           - Number of Bytes to be printed
*              *BaseAddress     - Pointer to the memory record
*               OffSet          - Offest from the beginning of the record
*
*  Return       : None
*
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "decode.h"

void PrintFile(short count, unsigned char *BaseAddress, unsigned long OffSet)
{

        FILE *OutFile;
        short i;

        i = 0;

        if(OutFlag)                     /* OutFlag determines which output file */
                OutFile = DumpFile;
        else
                OutFile = RecFile;


        if(ferror(OutFile)){
                printf("Write Failure on %s, ending program.\n",OutFile);
                exit(EXIT_FAILURE);
        }

        for (i = 0 ; i < count; i++){
                if( i % 16 ==0){
                        if(OutScrn)
                                printf("\n%06lu  ", (OffSet+i));
                        fprintf(OutFile,"\n%06lu  ", (OffSet+i));
                        if(ferror(OutFile)){
                                printf("Write Failure on %s, ending program.\n",
                                    OutFile);
                                exit(EXIT_FAILURE);
                        }
                }

                if(OutScrn)
                        printf("%02x ", *(BaseAddress+i));
                fprintf(OutFile,"%02x ", *(BaseAddress+i));
                if(ferror(OutFile)){
                        printf("Write Failure on %s, ending program.\n",
                            OutFile);
                        exit(EXIT_FAILURE);
                }
        }

        if(OutScrn)
                printf("\n");
        fprintf(OutFile,"\n");
        if(ferror(OutFile)){
                printf("Write Failure on %s, ending program.\n",OutFile);
                exit(EXIT_FAILURE);
        }

        /* The following is almost exactly like the beginning of the function except
that it produces the ASCII printout. Each character is checked to see if it
is printable, if not, a ".." is printed. This will make the output much easier
to scan for strings.*/



        for (i =0 ; i < count; i++){
                if ( i % 16 == 0){
                        if(OutScrn)
                                printf("\n%06lu ", OffSet + i);
                        fprintf(OutFile, "\n%06lu  ", OffSet + i);
                        if(ferror(OutFile)){
                                printf("Write Failure on %s, ending program.\n",
                                    OutFile);
                                exit(EXIT_FAILURE);
                        }
                }
                if(isprint(*(BaseAddress+i))){
                        if(OutScrn)
                                printf("%02c ", *(BaseAddress+i));
                        fprintf(OutFile,"%02c ", *(BaseAddress+i));
                        if(ferror(OutFile)){
                                printf("Write Failure on %s, ending program.\n",
                                    OutFile);
                                exit(EXIT_FAILURE);
                        }

                } else{

                        if(OutScrn)
                                printf(".. ");
                        fprintf(OutFile, ".. ");
                        if(ferror(OutFile)){
                                printf("Write Failure on %s, ending program.\n",
                                    OutFile);
                                exit(EXIT_FAILURE);
                        }
                }
        }



        if(!OutFlag){                   /* Record separator */
                if(OutScrn)

                        printf("\n\n--------------------------------------------------------\n\n");

                fprintf(OutFile,"\n\n-------------------------------------------------------\n\n");
        }
}
