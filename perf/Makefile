# Makefile 
# Marc Moreno Maza 
# Décembre 2002

SHELL = bash

# Files location
TOPDIR = $(PWD)
PSDIR = $(TOPDIR)/ps
SRCDIR = $(TOPDIR)/src
BINDIR = $(TOPDIR)/bin
PERFDIR = $(TOPDIR)/perf

# Compilers, commands  and options
CC = gcc
CCO = -O2 -o 
PP = a2ps
PPO = -q -o
MV = mv
MV0 = -f 
PERF = perf 
PERFO = stat -e cycles -e cache-misses 

# All files that require building
SRCS = copy1 copy2 copymatrix1 copymatrix2 dotproduct1 dotproduct2 lower1 lower2 MatTran1 MatTran2

# Targets
BINTARS = $(SRCS:%=%.out)
PSTARGS = $(SRCS:%=%.ps)
PERFTARGS = $(SRCS:%=%.perf)
TESTARGS = $(SRCS:%=%.tst)

all:  clean bin perf

bin: $(BINTARS)

perf: bin $(PERFTARGS) 

ps: $(PSTARGS)

tst: $(TESTARGS)

clean: 
	@(cd $(BINDIR); rm -f *)
	@(cd $(BINDIR); rm -f $(SRCS))
	@(cd $(SRCDIR); rm -f $(SRCS))
	@(cd $(SRCDIR); rm -f *~)
	@(cd $(PSDIR); rm -f *)
	@(cd $(PERFDIR); rm -f *)
	@(cd $(TOPDIR); rm -f *~)

%.ps: 
	@($(PP) $(PPO) $(PSDIR)/`basename $*`.ps $(SRCDIR)/`basename $*`.c)

%.out:
	@($(CC) $(CCO) $(BINDIR)/$*  $(SRCDIR)/$*.c)

%.tst:
	($(CC) $(CCO) $(BINDIR)/tmpbin $(SRCDIR)/$*.c)
	(cd $(BINDIR); ./tmpbin;) 
	(rm -f $(BINDIR)/tmpbin)

%.perf: $(BINDIR)/$*
	@(rm -f $(PERFDIR)/$*.perf)
	@($(PERF) $(PERFO) $(BINDIR)/$* >& $(PERFDIR)/$*.perf)


.DEFAULT : 
	@ echo "------------------------------------------------------------"
	@($(CC) $(CCO) $(BINDIR)/tmpbin $(SRCDIR)/$<.c)
	@(cd $(BINDIR); $(PERF) $(PERFO) ./tmpbin;) 
	@($(MV) $(MVO) $(BINDIR)/tmpbin $(BINDIR)/$<)
	@ echo "------------------------------------------------------------"
