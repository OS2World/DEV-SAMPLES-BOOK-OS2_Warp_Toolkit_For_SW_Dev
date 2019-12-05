/*****************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                        *
*       Prentice Hall (C) 1995                                               *
*                                                                            *
*                                                                            *
*       PROGRAM NAME: SMP4.EXE Sample 4                                      *
*                                                                            *
*       DESCRIPTION:                                                         *
*       Recur function for sample 4.  Sample 4 demonstrates                  *
*       how to put a function in a DLL.  It is identical to sample 3         *
*       but this time we do not use a .LIB file to create the DLL.           *
*       This is a simple example of recursion.  The user enters the          *
*       number of recursions and the program calls the recur()               *
*       function which recursively calls itself.                             *
*****************************************************************************/

int level = 1 ;

void recur(int n)
{
 printf("Down recursion level %ld, n = %ld is pushed on stack at %u\n",
        level++,n,&n);

 if (n)
 recur(n-1);

 printf("Up recursion level %ld, n = %ld is popped from stack at %u\n",
        --level,n,&n);
        return;
}
