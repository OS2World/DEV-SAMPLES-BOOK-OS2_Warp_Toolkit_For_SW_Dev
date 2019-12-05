#
# Simple Makefile to build FILTER and SMP8.EXE using IBM C Set/++ compiler.
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

EXEC   = smp8.exe
D16BIT = dll16bit.lib
FDLL   = filter.dll
CC     = icc
IMP    = implib
LIBS   = os2386
LINK   = link386
CFLAGS = -c -ss -w3
LFLAGS = /de

#
# Define Pseudotarget
#

all: $(FDLL) $(EXEC)

#
# Create the DLL - FILTER
#

$(FDLL): $(FDLL:.dll=.obj) $(FDLL:.dll=.def) $(D16BIT)
   $(LINK) @<<$(@B).lnk
$*.obj
$@
nul
$(LIBS) $(D16BIT)
$(FDLL:.dll=.def)
<<nokeep
   $(IMP) $(FDLL:.dll=.lib) $(FDLL:.dll=.def)

#
# Create the executable
#

$(EXEC): $(EXEC:.exe=.obj) $(EXEC:.exe=.def)
   $(LINK) @<<$(@B).lnk
$*.obj
$@
nul
$(LIBS)
$(EXEC:.exe=.def)
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

DESCRIPTION    'OS/2 32-bit DLL - used with a 16-bit DLL'

PROTMODE

DATA           SHARED

CODE           LOADONCALL

HEAPSIZE       8192

EXPORTS        CallMakeSomeNoise @1

IMPORTS        Dll16Bit.MakeSomeNoise

<<keep

#
# Create the module definition file for DLL32BIT
#

$(EXEC:.exe=.def):
   echo $@ @<<$@
;=============================================
; SMP8.DEF - Executable module definition file
;=============================================


NAME            SMP8      WINDOWCOMPAT

DESCRIPTION     'OS/2 32-bit EXE - will call a 16-bit DLL'

DATA            MULTIPLE

CODE            MOVEABLE

HEAPSIZE        1024

STACKSIZE       24576

IMPORTS         Filter.CallMakeSomeNoise ; Ordinals are used in the call
                                         ; to DosQueryProcAddr()

<<keep

#
# Create the filter object module
#

$(FDLL:.dll=.obj): $(FDLL:.dll=.c) $(FDLL:.dll=.h)
    $(CC) $(CFLAGS) $(FDLL:.dll=.c)

#
# Create the dll32bit object module
#

$(EXEC:.exe=.obj): $(EXEC:.exe=.c) $(EXEC:.exe=.h)
    $(CC) $(CFLAGS) $(EXEC:.exe=.c)

#
# Display message about 16-bit library
#

$(D16BIT):
  @echo ÿ
  @echo You will need to create the 'dll16bit' library using another
  @echo compiler. Currently the library is out of date.
  @echo ÿ


#
# Remove un-needed files
#

clean:
   -del *.obj *.dll *.def *.lib *.exe


