#
# Simple Makefile to build SMP2.EXE using IBM C Set++ compiler.
#
# The OS/2 Warp Toolkit for Software Developers
# Copyright (c) 1995. Prentice Hall.
#

#
# Define Suffix Rules
#

.SUFFIXES:
.SUFFIXES: .c .obj .lib .exe

#
# Define Macro Information
#

EXEC = smp2.exe
LIBC = lib
LIBR = smp2lib.lib
CC   = icc
LINK = link386


#
# Define inference Rules
#

.c.obj:
   $(CC) -c $*.c

#
# Define Pseudotarget
#

all: $(LIBR) $(EXEC)

#
# Create the library
#

$(LIBR): recur.obj
   ( if exist $(LIBR) del $(LIBR) )
   $(LIBC) @<<$(@B).rsp
$(LIBR)
y
+recur.obj
$(LIBR:.lib=.out)
<<nokeep

#
# Create the executable
#

$(EXEC): $(EXEC:.exe=.obj) $(EXEC:.exe=.def) $(LIBR)
    $(LINK) @<<$(@B)
$(EXEC:.exe=.obj)
$@
nul
$(LIBR)
$(EXEC:.exe=.def)
<<nokeep

#
# Create the module definition file for SMP2
#

$(EXEC:.exe=.def):
   @echo $@ @<<$@
;=================================================
; SMP2.DEF - Library Sample Module Definition File
;=================================================

NAME    SMP2    WINDOWCOMPAT

DESCRIPTION  'OS/2 32-bit EXE - using libraries'

PROTMODE

<<keep

#
# Remove un-needed files
#

clean:
   -del *.obj *.lib *.def *.out *.exe

