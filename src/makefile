GCC=g++
CSTD=c++11
FLAGS=-std=$(CSTD) -c
OBJDIR=../obj
LIBDIR=../lib
INCDIR=../inc
LIBNAME=libutil

TESTFILE=test.cc

SOURCES=$(filter-out test.cpp, $(wildcard *.cc))
OBJECTS=$(patsubst %.cc, %.o,$(SOURCES))

all : create-directories $(OBJECTS)
	ar rcs $(LIBDIR)/$(LIBNAME).a $(OBJDIR)/*

%.o : %.cc
	$(GCC) $(FLAGS) $<
	mv $@ $(OBJDIR)/

create-directories : 
	mkdir $(OBJDIR)
	mkdir $(LIBDIR)
	mkdir $(INCDIR)

.PHONY : clean

clean:
	rm -f test
	rm -r $(OBJDIR) $(LIBDIR) $(INCDIR)
