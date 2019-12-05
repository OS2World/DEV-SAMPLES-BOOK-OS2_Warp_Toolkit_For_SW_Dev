/****************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                       *
*       Prentice Hall (C) 1995                                              *
*                                                                           *
*                                                                           *
*       PROGRAM NAME: SMP6.EXE Sample 6                                     *
*                                                                           *
*       DESCRIPTION:                                                        *
*       Wordcnt function for sample 6.  Sample 6 demonstrates the use of    *
*       FWDSTAMP.EXE. Two functions, wordcnt and chrcnt, are relpaced       *
*       by forwarding to a single function, mywc, in NEW.DLL                *
****************************************************************************/

#include <stdio.h>
#include <stdio.h>
void WordCnt(FILE * fptr, char *name[])
{
        int ch;
        int count = 0;
        int lines = 0;
        int white = 1;

        fseek(fptr, 0L, SEEK_SET);

        while ( (ch = getc(fptr)) != EOF)
                switch(ch) {
                        case ' ' : white++; break;
                        case '\t': white++; break;
                        case '\n': white++; lines ++; break;
                        default  : if(white) {
                                        white = 0;
                                        count++;
                                   }
                }
        printf("File %s contains %d words and %d lines.\n",
                name, count, lines);
}

