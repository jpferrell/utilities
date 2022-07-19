GCC=g++
CSTD=c++11
FLAGS=-std=$(CSTD) -c
OBJDIR=obj
LIBDIR=lib
INCDIR=include
SRCDIR=src
LIBNAME=libutil

vpath %.cc src
vpath %.hh include

TESTFILE=test.cc

SOURCES=$(wildcard $(SRCDIR)/*.cc)
OBJECTS=$(subst $(SRCDIR), $(OBJDIR), $(patsubst %.cc, %.o,$(SOURCES)))
INCLUDES=$(wildcard $(INCDIR)/*.hh) 

all : $(OBJECTS)
	ar rcs $(LIBDIR)/$(LIBNAME).a $(OBJDIR)/*

$(OBJDIR)/%.o : %.cc
	$(GCC) $(FLAGS) -o $@ -I include $<

.PHONY : clean debug

debug :
	@echo $(SOURCES)
	@echo $(OBJECTS)

clean:
	rm -f test
	rm -f *~ $(SRCDIR)/*~ $(LIBDIR)/* $(OBJDIR)/* $(INCDIR)/*~
