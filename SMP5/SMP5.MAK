#
# Simple Makefile to build SMP5.EXE using IBM C Set++ compiler.
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

EXEC   = smp5.exe
DLL    = smp5dll.dll
LIBC   = lib
LIBR   = smp5lib.lib
LIBS   = dde4sbso _doscall
IMP    = implib
CC     = icc
LINK   = link386
LFLAGS = /NOD

#
# Define Pseudotarget
#

all: $(DLL) $(EXEC)

#
# Create the DLL - SMP5DLL
#

$(DLL): wordcnt.obj $(DLL:.dll=.def)
   $(LINK) @<<$(@B).lnk
wordcnt.obj
$@
nul

$(DLL:.dll=.def)
<<nokeep
   $(IMP) $(LIBR) $(DLL:.dll=.def)

#
# Create the executable
#

$(EXEC): smp5.obj $(EXEC:.exe=.def) $(LIBR)
   $(LINK) @<<$(@B).lnk
smp5.obj
$@
nul
$(LIBR) $(LIBS) $(LFLAGS)
$(EXEC:.exe=.def)
<<nokeep

#
# Create the module definition file for SMP5DLL
#

$(DLL:.dll=.def):
   echo $@ @<<$@
;=========================================================================
; SMP5DLL.DEF - DLL Sample program dynamic linking library definition file
;=========================================================================

LIBRARY   SMP5DLL

DESCRIPTION   'OS/2 32-bit DLL - Standalone without C Run-Time Libraries'

PROTMODE

DATA      MULTIPLE READWRITE LOADONCALL

CODE      LOADONCALL

EXPORTS
    WordCnt
   _PGLOBAL_PTR
   _critlib_except                            ; ****
   _DosSelToFlat                              ; ****
   _DosFlatToSel                              ; ****
   stderr
   stdin
   stdout
   _CRT_init                                  ; ****
   fopen
   fclose
   _environ
   _EXE_Exception                             ; ****
   _Exception                                 ; ****
   _PrintErrMsg                               ; ****
   _exception_procinit                        ; ****
   _exception_dllinit                         ; ****
   _matherr                                   ; ****
   _printfieee
   _terminate                                 ; ****
   exit                                       ; ****
   free                                       ; ****
   malloc                                     ; ****
   printf
   scanf
   strdup                                     ; ****
   strpbrk                                    ; ****
   fgetc

<<keep

#
# Create the module definition file for SMP5
#

$(EXEC:.exe=.def):
   echo $@ @<<$@
;============================================
; SMP5.DEF - Executable module defintion file
;============================================

NAME     SMP5     WINDOWCOMPAT

DESCRIPTION  'OS/2 32-bit EXE - used with DLL without C Run-Time Library'

PROTMODE

<<keep

#
# Create the wordcnt object module
#

wordcnt.obj: wordcnt.c
    $(CC) -c -Ge-  wordcnt.c

#
# Create the smp5 object module
#

smp5.obj: smp5.c
    $(CC) -c  smp5.c

#
# Remove un-needed files
#

clean:
   -del *.obj *.dll *.def *.lib *.exe

