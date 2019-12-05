#
# Simple Makefile to build DLL16BIT.DLL using Microsoft C 6.0 compiler.
#
# The OS/2 Warp Toolkit for Software Developers
# Copyright (c) 1995. Prentice Hall.
#

#
# Define Suffix Rules
#

.SUFFIXES:
.SUFFIXES: .c .obj .dll

#
# Define Macro Information
#

DLL    = dll16bit.dll
CC     = cl
LINK   = link
LIBS   = os2 llibcmt
IMP    = implib
CFLAGS = -c -G2s -W4 -Md -Alf
LFLAGS = /nod

#
# Define Pseudotarget
#

all: $(DLL)

#
# Create the DLL - DLL16BIT
#

$(DLL): $(DLL:.dll=.obj) $(DLL:.dll=.def)
   $(LINK) @<<$(@B).lnk
$*.obj
$@
nul
$(LIBS) $(LFLAGS)
$(DLL:.dll=.def)
<<nokeep
   $(IMP) $(DLL:.dll=.lib) $@

#
# Create the module definition file for DLL16BIT
#

$(DLL:.dll=.def):
   echo $@ @<<$(@B).def
;==========================================================================
; DLL16BIT.DEF - DLL Sample program dynamic linking library definition file
;==========================================================================

LIBRARY        Dll16Bit

DESCRIPTION    'OS/2 16-bit DLL Sample'

PROTMODE

DATA           SHARED

CODE           LOADONCALL

HEAPSIZE       8192

EXPORTS        MAKESOMENOISE @1

<<keep

#
# Create the dll16bit object module
#

$(DLL:.dll=.obj): $(DLL:.dll=.c) $(DLL:.dll=.h)
    $(CC) $(CFLAGS) $(DLL:.dll=.c)

#
# Remove un-needed files
#

clean:
   -del *.obj *.dll *.def *.lib

