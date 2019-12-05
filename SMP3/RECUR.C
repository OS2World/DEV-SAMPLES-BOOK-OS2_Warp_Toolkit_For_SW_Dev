/*****************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                        *
*       Prentice Hall (C) 1995                                               *
*                                                                            *
*       PROGRAM NAME: SMP3.EXE Sample 3                                      *
*                                                                            *
*       DESCRIPTION:                                                         *
*       Recur function for sample 3. Sample 3 demonstrates                   *
*       how to put a function in a DLL.  This is a simple example of         *
*       recursion.  The user enters the number of recursions and the         *
*       program calls the recur() function which recursively calls           *
*       itself.                                                              *
*****************************************************************************/

short level = 1;

void recur(int n)
{
printf("Down recursion level %d, n = %d is pushed on stack at %u\n",
        level++,n,&n);

 if (n)
 recur(n-1);

 printf("Up recursion level %ld, n = %ld is popped from stack at %u\n",
        --level,n,&n);
        return;

}
