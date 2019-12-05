/****************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                      *
*       Prentice Hall (C) 1995                                              *
*                                                                           *
*                                                                           *
*       PROGRAM NAME: SMP7.EXE Sample 7                                     *
*                                                                           *
*       DESCRIPTION:                                                        *
*       Source code for DLL32BIT.DLL.  Sample 7 demonstrates a way to       *
*       call a 32-bit function from a 16-bit program.  To build this        *
*       sample you will need both a 16 bit compiler and a 32-bit            *
*       compiler as well as the OS/2 Toolkit.  We have provided             *
*       makefiles for the Microsoft C 6.0 compiler and the IBM C Set++      *
*       compiler.  SMP7-16.MAK is the 16 bit makefile, while                *
*       SMP7-32.MAK is the 32 bit.  Since the 16-bit makefile has a         *
*       dependency on the library built by the 32-bit makefile, it          *
*       will be necessary to run SMP7-32.MAK first.                         *
****************************************************************************/

#define INCL_DOSPROCESS

#include <os2.h>
#include "Dll32Bit.h"

//  The function MakeSomeNoise is declared in the standard fashion.

APIRET EXPENTRY MakeSomeNoise( PFINPUTPARMS pParameters )
{
    DosBeep( (pParameters->Frequency)*2, pParameters->Duration);
    DosBeep( (pParameters->Frequency)*3, pParameters->Duration);
    DosBeep( (pParameters->Frequency)*4, pParameters->Duration);
}
