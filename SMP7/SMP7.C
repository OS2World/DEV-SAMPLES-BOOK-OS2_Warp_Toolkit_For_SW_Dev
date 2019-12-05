/***************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                      *
*       Prentice Hall (C) 1995                                             *
*                                                                          *
*       PROGRAM NAME: SMP7.EXE Sample 7                                    *
*                                                                          *
*       DESCRIPTION:                                                       *
*                                                                          *
*       Driver program for sample 7.  Sample 7 demonstrates a way to       *
*       call a 32-bit function from a 16-bit program.  To build this       *
*       sample you will need both a 16 bit compiler and a 32-bit           *
*       compiler as well as the OS/2 Toolkit.  We have provided            *
*       makefiles for the Microsoft C 6.0 compiler and the IBM C Set++     *
*       compiler.  SMP7-16.MAK is the 16 bit makefile, while               *
*       SMP7-32.MAK is the 32 bit.  Since the 16-bit makefile has a        *
*       dependency on the library built by the 32-bit makefile, it         *
*       will be necessary to run SMP7-32.MAK first.                        *
*                                                                          *
*                                                                          *
*       TO RUN:                                                            *
*                                                                          *
*       Start the program. You should hear beeps as the functions in the   *
*       32 bit DLL are called.                                             *
*                                                                          *
*       To delete unnecessary files:                                       *
*                                                                          *
*                  NMAKE -f SMP7-32.MAK clean                              *
*                  NMAKE -f SMP7-16.MAK clean                              *
*                                                                          *
*       To BUILD:                                                          *
*                                                                          *
*                  NMAKE -f SMP7-32.MAK  (must be done first)              *
*                  NMAKE -f SMP7-16.MAK                                    *
***************************************************************************/


#define INCL_DOSMODULEMGR
#define INCL_DOSPROCESS

#include <os2.h>
#include "smp7.h"

int main( void )
{
   FINPUTPARMS Parameters;

   Parameters.Frequency = 400;
   Parameters.Duration = 100;
   Parameters.Period = 300;

   /*
    Call a function in FILTER.DLL at a 16-bit entry point.  The 16-bit
    entry was created by defining CallMakeSomeNoise as _FAR16 _Pascal.
    CallMakeSomeNoise, in turn, loads a 32-bit DLL, locates the 32-bit
    MakeSomeNoise function and calls it passing our Parameter structure.
   */

   return( (INT)CallMakeSomeNoise(&Parameters) );

} /* main() */
