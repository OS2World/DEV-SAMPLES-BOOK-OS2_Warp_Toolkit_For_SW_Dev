/****************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                        *
*       Prentice Hall (C) 1995                                              *
*                                                                           *
*                                                                           *
*       PROGRAM NAME: SMP4.EXE Sample 4                                     *
*                                                                           *
*       DESCRIPTION:                                                        *
*       Driver program for sample 4. Sample 4 demonstrates                  *
*       how to put a function in a DLL.  It is identical to sample 3        *
*       but this time we do not use a .LIB file to create the DLL.          *
*       This is a simple example of recursion.  The user enters the         *
*       number of recursions and the program calls the recur()              *
*       function which recursively calls itself.                            *
*                                                                           *
*       TO RUN:                                                             *
*       Start the program. You will be asked how many recusions             *
*       you want. Enter any number, but 10 should be sufficient to          *
*       see how it works.                                                   *
*                                                                           *
*       To delete unnecessary files:                                        *
*                                                                           *
*                  NMAKE -f SMP4.MAK clean                                  *
*                                                                           *
*                                                                           *
*       To BUILD:                                                           *
*                                                                           *
*                  NMAKE -f SMP4.MAK                                        *
****************************************************************************/

int level = 1;
int  limit;
void recur(int);  /* function declaration */

main()
{

        printf("\nEnter the number of recursions:\n\n");
        scanf("%ld", &limit);

        recur(limit-1);

        printf("Done\n");
}
