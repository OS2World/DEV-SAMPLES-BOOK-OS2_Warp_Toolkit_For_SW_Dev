/***************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                      *
*       Prentice Hall (C) 1995                                             *
*                                                                          *
*       PROGRAM NAME: SMP8.EXE                                             *
*                                                                          *
*       DESCRIPTION:                                                       *
*       Header file for 16-bit DLL16BIT.DLL                                *
***************************************************************************/

typedef struct
{
   USHORT Frequency;
   USHORT Duration;
   USHORT Period;
} FINPUTPARMS, FAR * PFINPUTPARMS;

/*
  The APIENTRY type will cause the compiler to generate
  a intersegment call to the function, a 'far' pointer.
*/

VOID APIENTRY MakeSomeNoise( PFINPUTPARMS );


