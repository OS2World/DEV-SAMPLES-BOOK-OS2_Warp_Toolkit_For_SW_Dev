#
# Simple Makefile to build SMP6.EXE using IBM C Set++ compiler.
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

EXEC   = smp6.exe
DLL    = smp6dll.dll
NEWDLL = new.dll
FWDDLL = my.def
LIBR   = smp6lib.lib
LIBS   = dde4sbso  _doscall
IMP    = implib
CC     = icc
LINK   = link386
LFLAGS = /nod

#
# Define Pseudotarget
#

all: $(DLL) $(NEWDLL) $(EXEC) $(FWDDLL)

#
# Create SMP6DLL.DLL
#

$(DLL): wordcnt.obj charcnt.obj $(DLL:.dll=.def)
   $(LINK) @<<$(@B).lnk
wordcnt.obj + charcnt.obj
$@
nul

$(DLL:.dll=.def)
<<nokeep
   $(IMP) $(LIBR) $(DLL:.dll=.def)

#
# Create NEW.DLL
#

$(NEWDLL): mywc.obj $(NEWDLL:.dll=.def)
   $(LINK) @<<$(@B).lnk
mywc.obj
$@
nul
/noe
$(NEWDLL:.dll=.def)
<<nokeep

#
# Create the executable
#

$(EXEC): smp6.obj $(EXEC:.exe=.def) $(LIBR)
   $(LINK) @<<$(@B).lnk
smp6.obj
$@
nul
$(LIBR) $(LIBS) $(LFLAGS)
$(EXEC:.exe=.def)
<<nokeep

#
# Create the module definition file for SMP6DLL
#

$(DLL:.dll=.def):
   echo $@ @<<$@
;=========================================================================
; SMP6DLL.DEF - DLL Sample program dynamic linking library definition file
;=========================================================================

LIBRARY   SMP6DLL

DESCRIPTION  'OS/2 32-bit DLL - used in forward stamp'

PROTMODE

DATA      MULTIPLE READWRITE LOADONCALL

CODE      LOADONCALL

EXPORTS
    CharCnt
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
# Create the module definition file for NEW.DLL
#

$(NEWDLL:.dll=.def):
   echo $@ @<<$@
;=====================================================================
; NEW.DEF - DLL Sample program dynamic linking library definition file
;=====================================================================

LIBRARY      NEW

DESCRIPTION  'OS/2 32-bit DLL - will be forwarded to DLL'

PROTMODE

IMPORTS
   SMP6DLL.Printf
   SMP6DLL._printfieee
   SMP6DLL.fgetc
   SMP6DLL.Fclose
   SMP6DLL._DosSelToFlat
   SMP6DLL._DosFlatToSel

EXPORTS
     Mywc

<<keep

#
# Create the module definition file for SMP6
#

$(EXEC:.exe=.def):
   echo $@ @<<$@
;============================================
; SMP6.DEF - Executable module defintion file
;============================================

NAME     SMP6     WINDOWCOMPAT

DESCRIPTION  'OS/2 32-bit EXE - used in forward stamp'

PROTMODE

<<keep

#
# Create the module definition file for MY.DEF
#

$(FWDDLL):
   echo $@ @<<$@
;===========================================
; MY.DEF - DLL Forward Stamp definition file
;===========================================

LIBRARY    SMP6DLL

DESCRIPTION  'OS/2 32-bit DEF - Used in forwarding'

IMPORTS

    WORDCNT  = NEW.MYWC
    CHARCNT =  NEW.MYWC

EXPORTS

     WORDCNT
     CHARCNT


<<keep

#
# Create the wordcnt object module
#

wordcnt.obj: wordcnt.c
    $(CC) -c -Ge-  wordcnt.c

#
# Create the smp6 object module
#

smp6.obj: smp6.c
    $(CC) -c  smp6.c

#
# Create the charcnt object module
#

charcnt.obj: charcnt.c
    $(CC) -c -Ge- charcnt.c

#
# Create the mywc object module
#

mywc.obj: mywc.c
    $(CC) -c -Ge- mywc.c

#
# Remove un-needed files
#

clean:
   -del *.obj *.dll *.def *.lib *.exe

