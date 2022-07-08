GCC=g++
CSTD=c++11
FLAGS=-cstd=$(CSTD) -c
OBJDIR=../obj
LIBDIR=../obj
INCDIR=../inc

SOURCES=(wildcard *.cc)

%.o : %.cc
	$(GCC) $(FLAGS) $<

.PHONY : clean

clean:
	rm -f test
