/***************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                       *
*       Prentice Hall (C) 1995                                             *
*                                                                          *
*       PROGRAM NAME: SMP6.EXE Sample 6                                    *
*                                                                          *
*       DESCRIPTION:                                                       *
*       Mywc function for sample 6.  Sample 6 demonstrates the use of      *
*       FWDSTAMP.EXE. Two functions, wordcnt and chrcnt, are replaced      *
*       by forwarding to a single function, mywc, in NEW.DLL               *
***************************************************************************/

#include <stdio.h>
int Mywc(FILE *fptr, char *name[1])
{
        int ch;
        unsigned long words = 0;
        unsigned long lines = 0;
        int white = 1;
        unsigned long chars = 0;

        fseek(fptr, 0L, SEEK_SET);

        while ( (ch = getc(fptr)) != EOF){
                chars += 1;
                switch(ch) {
                case ' ' :
                        white++;
                        break;
                case '\t':
                        white++;
                        break;
                case '\n':
                        white++;
                        lines++;
                        break;
                default  :
                        if(white) {
                                white = 0;
                                words++;
                        }
                }
        }
        printf("LINES\tWORDS\tCHARACTERS\n");
        printf("%lu\t%lu\t%lu\t\t<------ %s \n", lines, words, chars, name);
}
