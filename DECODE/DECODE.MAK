#
# Simple Makefile to build DECODE.EXE using IBM C Set++ compiler.
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

EXEC = decode.exe
CC   = icc
LINK = link386

#
# Define inference Rules
#

.c.obj:
   $(CC) -c $*.c

#
# Create marco for objects
#

OBJS = decode.obj prtfile.obj readfile.obj intfile.obj

#
# Define Pseudotarget
#

all: $(EXEC)

#
# Create the executable
#

$(EXEC): $(OBJS) $(EXEC:.exe=.def)
    $(LINK) @<<$(@B)
$(OBJS)
$@
nul
os2386
$(EXEC:.exe=.def)
<<nokeep

#
# Create the module definition file for DECODE
#

$(EXEC:.exe=.def):
   @echo $@ @<<$@
;===============================================
; DECODE.DEF - Executable module definition file
;===============================================

NAME            DECODE        WINDOWCOMPAT

DESCRIPTION     'Decoder Tool'

PROTMODE

<<keep

#
# Create the object module - decode
#

decode.obj: decode.c

#
# Create the object module - readfile
#

readfile.obj: readfile.c

#
# Create the object module - intfile
#

intfile.obj: intfile.c

#
# Create the object module - prtfile
#

prtfile.obj: prtfile.c


#
# Remove un-needed files
#

clean:
   -del *.obj *.def  *.exe


