/****************************************************************************
*       PROGRAM NAME: DEXODE.EXE                                            *
*                                                                           *
*       DESCRIPTION: Header File for DECODE.EXE                             *
*                                                                           *
*                                                                           *
*  The OS/2 Warp Toolkit for Software Developers
*       Prentice Hall (C) 1995                                              *
*                                                                           *
****************************************************************************/
void   PrintFile(short count, unsigned char *BaseAddress, unsigned long offset);
long   ReadFile( long int InCount, FILE *InFile, unsigned char *BaseAddress);
void   IntFile(unsigned char *BaseAddress);

short  OutFlag, OutScrn, DumpFlag, LibFlag;
short  RecCount, Show;
FILE  *InFile, *DumpFile, *RecFile;
char   InLib;

#define NO        0x00
#define YES       0x01
#define THEADR    0x80
#define LHEADR    0x82
#define COMENT    0x88
#define MODEND16  0x8A
#define MODEND    0x8B
#define EXTDEF    0x8C
#define PUBDEF16  0x90
#define PUBDEF    0x91
#define LINNUM16  0x94
#define LINNUM    0x95
#define LNAMES    0x96
#define SEGDEF16  0x98
#define SEGDEF    0x99
#define GRPDEF    0x9A
#define FIXUPP16  0x9C
#define FIXUPP    0x9D
#define LEDATA16  0xA0
#define LEDATA    0xA1
#define LIDATA16  0xA2
#define LIDATA    0xA3
#define COMDEF    0xB0
#define BAKPAT16  0xB2
#define BAKPAT    0xB3
#define LEXTDEF16 0xB4
#define LEXTDEF   0xB5
#define LPUBDEF16 0xB6
#define LPUBDEF   0xB7
#define LCOMDEF   0xB8
#define COMDAT16  0xC2
#define COMDAT    0xC3
#define LINSYM16  0xC4
#define LINSYM    0xC5
#define ALIAS     0xC6
#define NBKPAT16  0xC8
#define NBKPAT    0xC9
#define LIBSTT    0xF0
#define LIBSTP    0xF1
#define ALL       0xFF
#define NONE      0x00
