GCC=g++
CPP=c++11
FLAGS=-std=$(CPP) -o
LIBPATH=../lib
INCPATH=../inc


argparse :
	$(GCC) $(FLAGS) argparse.exe  -L$(LIBPATH)/ -I$(INCPATH)/ argParseExample.cc -lutil

.PHONY : clean

clean :
	rm *.exe
