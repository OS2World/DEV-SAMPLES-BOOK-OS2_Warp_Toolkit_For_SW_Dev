/***************************************************************************
*                                                                          *
*       The OS/2 Warp Toolkit for Software Developers                      *
*       Prentice Hall (C) 1995                                             *
*                                                                          *
*       PROGRAM NAME: SMP8.EXE Sample 8                                    *
*                                                                          *
*       DESCRIPTION:                                                       *
*       Source code for DLL16BIT.DLL.  Sample 8 demonstrates a way to      *
*       call a 16-bit function from a 32-bit program.  To build this       *
*       sample you will need both a 16 bit compiler and a 32-bit           *
*       compiler as well as the OS/2 Toolkit.  We have provided            *
*       makefiles for the Microsoft C 6.0 compiler and the IBM C Set++     *
*       compiler.  SMP8-16.MAK is the 16 bit makefile, while               *
*       SMP8-32.MAK is the 32 bit.  Since the 32-bit makefile has a        *
*       dependency on the library built by the 16-bit makefile, it         *
*       will be necessary to run SMP8-32.MAK first.                        *
***************************************************************************/

#define INCL_DOSPROCESS
#define INCL_DOS

#include <os2.h>
#include <stdlib.h>
#include "Dll16Bit.h"

/*
  The function MakeSomeNoise is declared with the type APIENTRY. This
  will force the compiler to generate a 'far' call (intersegment address)
  to the function with the pascal calling sequence.
*/

VOID  APIENTRY MakeSomeNoise( PFINPUTPARMS pParameters )
{
   ( DosBeep( (pParameters->Frequency)*4, pParameters->Duration ) );
   ( DosBeep( (pParameters->Frequency)*3, pParameters->Duration ) );
   ( DosBeep( (pParameters->Frequency)*2, pParameters->Duration ) );
}
