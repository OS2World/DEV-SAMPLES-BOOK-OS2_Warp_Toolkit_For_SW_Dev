/****************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                      *
*       Prentice Hall (C) 1995                                              *
*                                                                           *
*       PROGRAM NAME: SMP7.EXE Sample 7                                     *
*                                                                           *
*       DESCRIPTION:                                                        *
*                                                                           *
*       Source code for FILTER.DLL.  Sample 7 demonstrates a way to         *
*       call a 32-bit function from a 16-bit program.  To build this        *
*       sample you will need both a 16 bit compiler and a 32-bit            *
*       compiler as well as the OS/2 Toolkit.  We have provided             *
*       makefiles for the Microsoft C 6.0 compiler and the IBM C Set++      *
*       compiler.  SMP7-16.MAK is the 16 bit makefile, while                *
*       SMP7-32.MAK is the 32 bit.  Since the 16-bit makefile has a         *
*       dependency on the library built by the 32-bit makefile, it          *
*       will be necessary to run SMP7-32.MAK first.                         *
****************************************************************************/

#define INCL_DOSMODULEMGR
#define INCL_DOSPROCESS
#define INCL_DOSDATETIME

#include <os2.h>
#include <stdio.h>
#include "Filter.h"

USHORT _Far16 _Pascal CallMakeSomeNoise( PFINPUTPARMS pParameters )
{
   APIRET      rc;
   CHAR        szDllName[] = "DLL32BIT";
   CHAR        szFailBuff[100];
   HMODULE     hDllMod;
   PFN         pfnMakeSomeNoise;

   DosBeep( pParameters->Frequency, pParameters->Duration );
   DosSleep( pParameters->Period );

   if (! ( rc = DosLoadModule( szFailBuff, sizeof(szFailBuff), szDllName,
                               &hDllMod ) ) )
   {
      if (! ( rc = DosQueryProcAddr( hDllMod, 1L, NULL, &pfnMakeSomeNoise ) ) )
      {
         return ( (USHORT)( *pfnMakeSomeNoise ) ( pParameters ) );
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
} // Filter()
