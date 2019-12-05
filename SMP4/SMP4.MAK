#
# Simple Makefile to build SMP4.EXE using IBM C Set++ compiler.
#
# The OS2 Warp Toolkit for Software Developers
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

EXEC   = smp4.exe
DLL    = smp4dll.dll
LIBR   = smp4lib.lib
CC     = icc
LINK   = link386
LFLAGS = /noe

#
# Define Pseudotarget
#

all: $(DLL) $(EXEC)

#
# Create the DLL - SMP4DLL
#

$(DLL): recur.obj $(DLL:.dll=.def)
   $(LINK) @<<$(@B).lnk
recur.obj
$@
nul
$(LFLAGS)
$(DLL:.dll=.def)
<<nokeep

#
# Create the executable
#

$(EXEC): smp4.obj $(EXEC:.exe=.def)
   $(LINK) @<<$(@B).lnk
smp4.obj
$@
nul
$(LFLAGS)
$(EXEC:.exe=.def)
<<nokeep

#
# Create the module definition file for SMP4DLL
#

$(DLL:.dll=.def):
   echo $@ @<<$@
;=========================================================================
; SMP4DLL.DEF - DLL Sample program dynamic linking library definition file
;=========================================================================

LIBRARY    SMP4DLL

DESCRIPTION   'OS/2 32-bit DLL - will be used without import library'

PROTMODE

EXPORTS
   recur

<<keep

#
# Create the module definition file for SMP4
#

$(EXEC:.exe=.def):
   echo $@ @<<$@
;=============================================
; SMP4.DEF - Executable module definition file
;=============================================

NAME       SMP4    WINDOWCOMPAT

DESCRIPTION   'OS/2 32-bit EXE - calls a 32-bit without import library'

PROTMODE

DATA       MULTIPLE READWRITE LOADONCALL

CODE       LOADONCALL

IMPORTS    SMP4DLL.Recur

<<keep

#
# Create the recur object module
#

recur.obj: recur.c
    $(CC) -c -Ge- recur.c

#
# Create the smp4 object module
#

smp4.obj: smp4.c
    $(CC) -c -Ge+  smp4.c

#
# Remove un-needed files
#

clean:
   -del *.obj *.dll *.def *.exe

