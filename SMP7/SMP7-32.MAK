#
# Simple Makefile to build FILTER and DLL32BIT using IBM C Set/++ compiler.
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

FDLL   = filter.dll
D32BIT = dll32bit.dll
CC     = icc
IMP    = implib
LINK   = link386
CFLAGS = -c -ss -W3
LFLAGS = /de

#
# Define Pseudotarget
#

all: $(FDLL) $(D32BIT)

#
# Create the DLL - FILTER
#

$(FDLL): $(FDLL:.dll=.obj) $(FDLL:.dll=.def)
   $(LINK) @<<$(@B).lnk
$*.obj
$@
nul
os2386
$(FDLL:.dll=.def)
<<nokeep
   $(IMP) $(FDLL:.dll=.lib) $(FDLL:.dll=.def)

#
# Create the DLL - DLL32BIT
#

$(D32BIT): $(D32BIT:.dll=.obj) $(D32BIT:.dll=.def)
   $(LINK) @<<$(@B).lnk
$*.obj
$@
nul
os2386
$(D32BIT:.dll=.def)
<<nokeep

#
# Create the module definition file for FILTER
#

$(FDLL:.dll=.def):
   echo $@ @<<$@
;========================================================================
; FILTER.DEF - DLL Sample program dynamic linking library definition file
;========================================================================

LIBRARY        Filter

DESCRIPTION    'OS/2 32-bit DLL - will be a filter for a 16-bit program'

PROTMODE

DATA           SHARED

CODE           LOADONCALL

HEAPSIZE       8192

EXPORTS        CallMakeSomeNoise @1

IMPORTS        Dll32Bit.MakeSomeNoise

<<keep

#
# Create the module definition file for DLL32BIT
#

$(D32BIT:.dll=.def):
   echo $@ @<<$@
;==========================================================================
; DLL32BIT.DEF - DLL Sample program dynamic linking library definition file
;==========================================================================

LIBRARY        DLL32BIT   ;INITINSTANCE

DESCRIPTION    'OS/2 32 bit DLL - used in from a 16-bit program'

PROTMODE

DATA           SHARED

CODE           LOADONCALL

HEAPSIZE       8192

EXPORTS        MakeSomeNoise @1

<<keep

#
# Create the filter object module
#

$(FDLL:.dll=.obj): $(FDLL:.dll=.c) $(FDLL:.dll=.h)
    $(CC) $(CFLAGS) $(FDLL:.dll=.c)

#
# Create the dll32bit object module
#

$(D32BIT:.dll=.obj): $(D32BIT:.dll=.c) $(D32BIT:.dll=.h)
    $(CC) $(CFLAGS) $(D32BIT:.dll=.c)

#
# Remove un-needed files
#

clean:
   -del *.obj *.dll *.def *.lib *.exe


