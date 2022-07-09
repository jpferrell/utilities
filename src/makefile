GCC=g++
CSTD=c++11
FLAGS=-std=$(CSTD) -c
OBJDIR=../obj
LIBDIR=../lib
INCDIR=../inc
LIBNAME=libutil

TESTFILE=test.cc

SOURCES=$(wildcard *.cc)
OBJECTS=$(patsubst %.cc, %.o,$(SOURCES))
INCLUDES=$(wildcard *.hh) 

all : create-directories move-includes $(OBJECTS)
	ar rcs $(LIBDIR)/$(LIBNAME).a $(OBJDIR)/*

%.o : %.cc
	$(GCC) $(FLAGS) $<
	mv $@ $(OBJDIR)/

move-includes:
	cp $(INCLUDES) $(INCDIR)/

create-directories : 
	mkdir $(OBJDIR)
	mkdir $(LIBDIR)
	mkdir $(INCDIR)

.PHONY : clean

clean:
	rm -f test
	rm -r $(OBJDIR) $(LIBDIR) $(INCDIR)
