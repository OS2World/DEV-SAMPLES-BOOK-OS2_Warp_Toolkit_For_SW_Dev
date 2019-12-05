/***************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                      *
*       Prentice Hall (C) 1995                                             *
*                                                                          *
*       PROGRAM NAME: SMP8.EXE                                             *
*                                                                          *
*       DESCRIPTION:                                                       *
*                                                                          *
*       Header file for FILTER.DLL.  The data structure that is            *
*       defined for the procedure that contains main() is redefined        *
*       here so that the linker can resolve the differences between        *
*       the two memory models.  The procedure 'CallMakeSomeNoise' is       *
*       defined here.                                                      *
***************************************************************************/

#include "smp8.h"

USHORT EXPENTRY CallMakeSomeNoise( PFINPUTPARMS );

extern USHORT _Far16 _Pascal MakeSomeNoise( PFINPUTPARMS );

