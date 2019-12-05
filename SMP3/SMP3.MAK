#
# Simple Makefile to build SMP3.EXE using IBM C Set++ compiler.
#
# The OS/2 Warp Toolkit for Software Developers
# Copyright (c) 1995. Prentice Hall.
#

#
# Define Suffix Rules
#

.SUFFIXES:
.SUFFIXES: .c .obj .dll .exe

#
# Define Macro Information
#

EXEC   = smp3.exe
DLL    = smp3dll.dll
LIBR   = smp3lib.lib
LIBS   = dde4sbso
IMP    = implib
CC     = icc
LINK   = link386
LFLAGS = /noe

#
# Define Pseudotarget
#

all: $(DLL) $(EXEC)

#
# Create the DLL - SMP3DLL
#

$(DLL): recur.obj $(DLL:.dll=.def)
   $(LINK) @<<$(@B).lnk
recur.obj
$@
nul
$(LFLAGS)
$(DLL:.dll=.def)
<<nokeep
   $(IMP) $(LIBR) $(DLL:.dll=.def)

#
# Create the executable
#

$(EXEC): smp3.obj $(EXEC:.exe=.def) $(LIBR)
   $(LINK) @<<$(@B).lnk
smp3.obj
$@
nul
$(LIBR) $(LIBS) $(LFLAGS)
$(EXEC:.exe=.def)
<<nokeep

#
# Create the module definition file for SMP3DLL
#

$(DLL:.dll=.def):
   echo $@ @<<$@
;=========================================================================
; SMP3DLL.DEF - DLL Sample program dynamic linking library definition file
;=========================================================================

LIBRARY    SMP3DLL

DESCRIPTION  'OS/2 32-bit DLL - Simple DLL'

PROTMODE

EXPORTS
   recur

<<keep

#
# Create the module definition file for SMP3
#

$(EXEC:.exe=.def):
   echo $@ @<<$@
;=============================================
; SMP3.DEF - Executable module definition file
;=============================================

NAME       SMP3     WINDOWCOMPAT

DESCRIPTION  'OS/2 32-bit EXE - calls a DLL'

PROTMODE

<<keep

#
# Create the recur object module
#

recur.obj: recur.c
    $(CC) -c -Ge- recur.c

#
# Create the smp3 object module
#

smp3.obj: smp3.c
    $(CC) -c -Ge+ smp3.c

#
# Remove un-needed files
#

clean:
   -del *.obj *.dll *.def *.lib *.exe


