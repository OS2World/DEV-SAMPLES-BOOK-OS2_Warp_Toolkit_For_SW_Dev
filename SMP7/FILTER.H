/****************************************************************************
*       The OS/2 Warp Toolkit for Software Developers                      *
*       Prentice Hall (C) 1995                                              *
*                                                                           *
*       PROGRAM NAME: SMP7.EXE                                              *
*                                                                           *
*       DESCRIPTION:                                                        *
*                                                                           *
*       Header file for FILTER.DLL.  The data structure that is             *
*       defined for the procedure that contains main() is redefined         *
*       here so that the linker can resolve the differences between         *
*       the two memory models.  The procedure 'CallMakeSomeNoise' is        *
*       defined here using the key words '_Far16" and '_Pascal', this       *
*       will cause the compiler to generate a 16-bit entry to the           *
*       function.                                                           *
****************************************************************************/

#pragma pack(2)

typedef struct
{
   USHORT Frequency;
   USHORT Duration;
   USHORT Period;
} FINPUTPARMS, * _Seg16 PFINPUTPARMS;

#pragma pack()

#pragma checkout(suspend)

USHORT _Far16 _Pascal CallMakeSomeNoise( PFINPUTPARMS );

#pragma checkout(resume)

