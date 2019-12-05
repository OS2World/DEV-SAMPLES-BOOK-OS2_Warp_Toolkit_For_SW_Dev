/******************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                         *
*       Prentice Hall (C) 1995                                                *
*                                                                             *
*       PROGRAM NAME: SMP2.EXE Sample 2                                       *
*                                                                             *
*       DESCRIPTION:                                                          *
*       Driver program for sample 2.  Sample 2 demonstrates                   *
*       how to put a function in a library.  This is a simple example of      *
*       recursion.  The user enters the number of recursions and the          *
*       program calls the recur() function which recursively calls            *
*       itself.                                                               *
*                                                                             *
*       TO RUN:                                                               *
*       Start the program. You will be asked how many recusions               *
*       you want. Enter any number, but 10 should be sufficient to            *
*       see how it works.                                                     *
*                                                                             *
*                                                                             *
*       To delete unnecessary files:                                          *
*                                                                             *
*                  NMAKE -f SMP2.MAK clean                                    *
*                                                                             *
*       To BUILD:                                                             *
*                                                                             *
*                  NMAKE -f SMP2.MAK                                          *
******************************************************************************/

int  limit;
void recur(int);  /* function declaration */

void main(void)
{

        printf("\nEnter the number of recursions:\n\n");
        scanf("%d", &limit);

        recur(limit -1);

        printf("Done\n");
}
