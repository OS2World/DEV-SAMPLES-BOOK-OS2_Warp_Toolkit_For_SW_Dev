/***************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                      *
*       Prentice Hall (C) 1995                                             *
*                                                                          *
*       PROGRAM NAME: SMP8.EXE                                             *
*                                                                          *
*       DESCRIPTION: Header File for SMP8.EXE                              *
***************************************************************************/

void main( void );

/*
    This data structure is passed to both the 32-bit DLL and the 16-bit
    DLL.  For a comparison of how to declare the pointers for both memory
    models, compare this declaration to the one found in the file
    dll16bit.h.  Remember the DLLs are being compiled by different
    compilers.
*/

typedef struct
{
   USHORT Frequency;
   USHORT Duration;
   USHORT Period;
} FINPUTPARMS, * PFINPUTPARMS;

