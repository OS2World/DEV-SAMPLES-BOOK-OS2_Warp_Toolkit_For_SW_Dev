/*****************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                        *
*       Prentice Hall (C) 1995                                               *
*                                                                            *
*                                                                            *
*       PROGRAM NAME: SMP3.EXE Sample 3                                      *
*                                                                            *
*       DESCRIPTION:                                                         *
*                                                                            *
*       Driver program for sample 3. Sample 3 demonstrates                   *
*       how to put a function in a DLL.  This is a simple example of         *
*       recursion.  The user enters the number of recursions and the         *
*       program calls the recur() function which recursively calls           *
*       itself.                                                              *
*                                                                            *
*       TO RUN:                                                              *
*       Start the program. You will be asked how many recusions              *
*       you want. Enter any number, but 10 should be sufficient to           *
*       see how it works.                                                    *
*                                                                            *
*       To delete unnecessary files:                                         *
*                                                                            *
*                  NMAKE -f SMP3.MAK clean                                   *
*                                                                            *
*       To BUILD:                                                            *
*                                                                            *
*                  NMAKE -f SMP3.MAK                                         *
*****************************************************************************/

void recur(int);
int  limit;

main()
{

        printf("\nEnter the number of recursions:\n\n");
        scanf("%ld", &limit);

        recur(limit-1);

        printf("Done\n");
}
