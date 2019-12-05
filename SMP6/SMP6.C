/****************************************************************************
*                                                                           *
*       The OS/2 Warp Toolkit for Software Developers                       *
*       Prentice Hall (C) 1995                                              *
*                                                                           *
*       PROGRAM NAME: SMP6.EXE Sample 6                                     *
*                                                                           *
*       DESCRIPTION:                                                        *
*       Driver program for sample 6.  Sample 6 demonstrates the use of      *
*       FWDSTAMP.EXE.  Two functions, wordcnt and chrcnt, are replaced      *
*       by forwarding to a single function, mywc, in NEW.DLL                *
*                                                                           *
*       TO RUN:                                                             *
*       Start the program and pass it one or more text file names.          *
*       The first time, wordcnt and charcnt will be called and output       *
*       to the screen.                                                      *
*                                                                           *
*       When you understand what is happening, run the OS/2 command         *
*       file REPL.CMD.  It will run the commands necessary for the          *
*       replacement of the 2 functions with the single mywc function.       *
*       It will also output to the screen as it progresses.  For the        *
*       CMD file, we read smp6.c before the FWDSTAMP and again after        *
*       FWDSTAMP.  You should be able to see that mywc has replaced         *
*       the other two functions.                                            *
*                                                                           *
*       To get back to where you were, before running REPL.CMD, run         *
*       the BACK.CMD file.  It will replace the forward stamped DLL         *
*       with the original.                                                  *
*                                                                           *
*       To delete unnecessary files:                                        *
*                                                                           *
*                  NMAKE -f SMP6.MAK clean                                  *
*                                                                           *
*       To BUILD:                                                           *
*                                                                           *
*                  NMAKE -f SMP6.MAK                                        *
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
        FILE *fptr[10];
        short i;

        if (argc < 2) {              /* Check # of command line args */
                printf("Enter: smp6 filename(s) \n");
                exit(-1);
        }

        for(i = 1; i <= argc; i++){

            if( (fptr[i] = fopen(argv[i], "r") ) == NULL) {   /* Open file */
                    printf("can't open file");
                    exit(-1);
            }
        printf("\nCalling WordCnt\n");
        WordCnt(fptr[i], argv[i]);
        printf("\nCalling CharCnt\n");
        CharCnt(fptr[i], argv[i]);
        fclose (fptr[i]);
        }

}
