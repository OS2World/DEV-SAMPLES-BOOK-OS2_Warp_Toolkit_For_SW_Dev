/***************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                       *
*       Prentice Hall (C) 1995                                             *
*                                                                          *
*       PROGRAM NAME: SMP6.EXE Sample 6                                    *
*                                                                          *
*       DESCRIPTION:                                                       *
*       Charcnt function for sample 6.  Sample 6 demonstrates the use of   *
*       FWDSTAMP.EXE. Two functions, wordcnt and chrcnt, are replaced      *
*       by forwarding to a single function, mywc, in NEW.DLL               *
***************************************************************************/

#include <stdio.h>

void CharCnt(FILE *fptr, char *name[])
{
        int count = 0;
        fseek(fptr, 0L, SEEK_SET);
        while (getc(fptr) != EOF)
                count++;
        printf("File %s contains %d characters.\n" ,name, count);
}
