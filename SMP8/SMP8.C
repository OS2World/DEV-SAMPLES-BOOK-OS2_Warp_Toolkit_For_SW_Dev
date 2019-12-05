/***************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                      *
*       Prentice Hall (C) 1995                                             *
*                                                                          *
*       PROGRAM NAME: SMP8.EXE Sample 8                                    *
*                                                                          *
*       DESCRIPTION:                                                       *
*       Driver program for sample 8.  Sample 8 demonstrates a way to       *
*       call a 16-bit function from a 32-bit program.  To build this       *
*       sample you will need both a 16 bit compiler and a 32-bit           *
*       compiler as well as the OS/2 Toolkit.  We have provided            *
*       makefiles for the Microsoft C 6.0 compiler and the IBM C Set++     *
*       compiler.  SMP8-16.MAK is the 16 bit makefile, while               *
*       SMP8-32.MAK is the 32 bit.  Since the 32-bit makefile has a        *
*       dependency on the library built by the 16-bit makefile, it         *
*       will be necessary to run SMP8-16.MAK first.                        *
*                                                                          *
*       TO RUN:                                                            *
*       Start the program. You should hear beeps as the functions in the   *
*       16 bit DLL are called.                                             *
*                                                                          *
*       To delete unnecessary files:                                       *
*                                                                          *
*                  NMAKE -f SMP8-16.MAK clean                              *
*                  NMAKE -f SMP8-32.MAK clean                              *
*                                                                          *
*                                                                          *
*       To BUILD:                                                          *
*                                                                          *
*                  NMAKE -f SMP8-16.MAK  (must be done first)              *
*                  NMAKE -f SMP8-32MAK                                     *
***************************************************************************/

#define INCL_DOSMODULEMGR

#include <os2.h>
#include <stdio.h>
#include "smp8.h"

void main( void )
{
   APIRET      rc;
   CHAR        szDllName[] = "Filter";
   CHAR        szFailBuff[100];
   HMODULE     hDllMod;
   FINPUTPARMS Parameters;
   PFN         pfnCallMakeSomeNoise;

   Parameters.Frequency = 400L;
   Parameters.Duration = 100L;
   Parameters.Period = 300L;

   if (! ( rc = DosLoadModule( szFailBuff, sizeof(szFailBuff), szDllName,
                               &hDllMod ) ) )
   {
      if (! ( rc = DosQueryProcAddr( hDllMod, 1L, NULL, &pfnCallMakeSomeNoise ) ) )
      {
         ( *pfnCallMakeSomeNoise ) ( &Parameters );
      }
      else
      {
         printf( "Could not locate function address, rc =  %d", rc );
      }
      DosFreeModule ( hDllMod );
   }
   else
   {
      printf( "Could not load module, rc =  %d", rc );
   }
} // main()
