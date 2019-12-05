/***************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                      *
*       Prentice Hall (C) 1995                                             *
*                                                                          *
*       PROGRAM NAME: SMP8.EXE Sample 8                                    *
*                                                                          *
*       DESCRIPTION:                                                       *
*       Source code for FILTER.DLL.  Sample 8 demonstrates a way to        *
*       call a 16-bit function from a 32-bit program.  To build this       *
*       sample you will need both a 16 bit compiler and a 32-bit           *
*       compiler as well as the OS/2 Toolkit.  We have provided            *
*       makefiles for the Microsoft C 6.0 compiler and the IBM C Set++     *
*       compiler.  SMP8-16.MAK is the 16 bit makefile, while               *
*       SMP8-32.MAK is the 32 bit.  Since the 32-bit makefile has a        *
*       dependency on the library built by the 16-bit makefile, it         *
*       will be necessary to run SMP8-16.MAK first.                        *
***************************************************************************/

#define INCL_DOSPROCESS
#define INCL_DOSDATETIME

#include <os2.h>
#include "Filter.h"

USHORT EXPENTRY CallMakeSomeNoise( PFINPUTPARMS pParameters )
{
   DosBeep( pParameters->Frequency, pParameters->Duration );
   DosSleep( pParameters->Period );

   /*
    Call the function in the 16-Bit DLL by name.
    This is possible because we created an import library for
    the dll when it was compiled. The address conversions are
    resolved by the linker with the help of the external definition
    of this function as _Far16 _Pascal in FILTER.H
   */

   return( MakeSomeNoise( pParameters ) );
}
