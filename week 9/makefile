# ** Zach Reed
# ** CS-325
# ** Makefile for binpack.cpp
# *********************************************

CXX = g++		#enables g++ as compiler
CXXFLAGS =  -std=c++11	#enables c++11 standards
CXXFLAGS += -Wall	#enables warnings

#target: dependencies
#	action

# Executable output, dependencies, and action ***************************
binpack: binpack.o
	g++ $(CXXFLAGS) binpack.o -o binpack

#tells compiler to create object without executable when modified
binpack.o: binpack.cpp
	g++ $(CXXFLAGS) -c binpack.cpp

#Removes object files and output ****************************************
clean:
	rm *.o binpack
