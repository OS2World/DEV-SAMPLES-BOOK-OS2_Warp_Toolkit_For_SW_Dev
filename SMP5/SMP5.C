/****************************************************************************
*       The OS/2 Warp Toolkit for Software Developers.                      *
*       Prentice Hall (C) 1995                                              *
*                                                                           *
*                                                                           *
*       PROGRAM NAME: SMP5.EXE Sample 5                                     *
*                                                                           *
*       DESCRIPTION:                                                        *
*       Driver program for sample 5.  Sample 5 shows how to build           *
*       a stand alone DLL. By including C functions in our DLL              *
*       we create a smaller, faster running executable.                     *
*                                                                           *
*       TO RUN:                                                             *
*       Start the program and pass it the name of one or more text files.   *
*       This program will count the number of words and lines in the file   *
*       and output to the screen.                                           *
*                                                                           *
*       To delete unnecessary files:                                        *
*                                                                           *
*                  NMAKE -f SMP5.MAK clean                                  *
*                                                                           *
*       To BUILD:                                                           *
*                                                                           *
*                  NMAKE -f SMP5.MAK                                        *
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
        FILE *fptr;
        int ch;
        unsigned long words = 0;
        unsigned long lines = 0;
        int white = 1;
        unsigned long chars = 0;

        if (argc != 2) {              /* Check # of command line args */
                printf("Enter: smp5 filename \n");
                exit(-1);
        }

        if( (fptr = fopen(argv[1], "r") ) == NULL) {   /* Open file */
                printf("can't open file");
                exit(-1);
        }
        WordCnt(fptr, argv[1]);
}
