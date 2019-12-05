#
# Simple Makefile to build SMP7.EXE using Microsoft C 6.0 compiler.
#
# The OS/2 Warp Toolkit for Software Developers
# Copyright (c) 1995. Prentice Hall.
#

#
# Define Suffix Rules
#

.SUFFIXES:
.SUFFIXES: .c .obj .exe

#
# Define Macro Information
#

EXEC   = smp7.exe
FILTER = filter.lib
CC     = cl
LINK   = link
LIBS   = os2 llibcmt
CFLAGS = -c -G2s -W4
LFLAGS = /align:16 /nod

#
# Define Pseudotarget
#

all: $(EXEC)

#
# Create the executable
#

$(EXEC): $(EXEC:.exe=.obj) $(EXEC:.exe=.def) $(FILTER)
   $(LINK) @<<$(@B).lnk
$*.obj
$@
nul
$(LIBS) $(FILTER) $(LFLAGS)
$(EXEC:.exe=.def)
<<nokeep


#
# Create the module definition file for SMP7
#

$(EXEC:.exe=.def):
   echo $@ @<<$(@B).def
;=============================================
; SMP7.DEF - Executable module definition file
;=============================================

NAME            SMP7     WINDOWCOMPAT

DESCRIPTION     'OS/2 16-bit EXE - used in calling 32-bit DLL'

DATA            MULTIPLE

CODE            MOVEABLE

HEAPSIZE        4096

STACKSIZE       8192

IMPORTS         Filter.CallMakeSomeNoise

<<keep

#
# Create the smp7 object module
#

$(EXEC:.exe=.obj): $(EXEC:.exe=.c) $(EXEC:.exe=.h)
    $(CC) $(CFLAGS) $(EXEC:.exe=.c)

#
# Display message about 16-bit library
#

$(FILTER):
  @echo ÿ
  @echo You will need to create the 'filter' library using another
  @echo compiler. Currently the library is out of date.
  @echo ÿ

#
# Remove un-needed files
#

clean:
   -del *.obj *.dll *.def *.lib *.exe


