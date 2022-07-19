GCC=g++
CPP=c++11
FLAGS=-std=$(CPP) -o
LIBPATH=../lib
INCPATH=../include

SOURCES = $(wildcard *.cc)
EXECUTIBLES = $(patsubst %.cc, %.exe, $(SOURCES))

all : $(EXECUTIBLES)

%.exe : %.cc
	$(GCC) $(FLAGS) $@  -L$(LIBPATH)/ -I$(INCPATH)/ $< -lutil

.PHONY : clean

clean :
	rm -f *.exe *~
