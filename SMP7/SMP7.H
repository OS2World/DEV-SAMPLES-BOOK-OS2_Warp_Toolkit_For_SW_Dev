/***************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                      *
*       Prentice Hall (C) 1995                                             *
*                                                                          *
*       PROGRAM NAME: SMP7.EXE                                             *
*                                                                          *
*       DESCRIPTION: Header File for SMP7.EXE                              *
***************************************************************************/

int main( void );

/*
   This data structure is passed to the 32-bit FILTER.DLL from
   main. The DLL is compiled to create a 16-bit entry point. For a
   comparison of how to declare the pointers for both memory models,
   compare this declaration to the one found in the file Filter.h.
*/

typedef struct
{
   USHORT Frequency;
   USHORT Duration;
   USHORT Period;
} FINPUTPARMS, FAR * PFINPUTPARMS;

/*
  This declaration is necessary for the linker to resolve the differences
  between the 16-bit addresses of main() and the function in the 32-bit
  DLL that will be called by main().
*/

extern USHORT APIENTRY CallMakeSomeNoise( PFINPUTPARMS );
