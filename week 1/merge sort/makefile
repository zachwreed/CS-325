# ** Zach Reed							      
# ** CS-325							      	 
# ** Makefile for mergesortsort				   
# *********************************************

CXX = g++		#enables g++ as compiler
CXXFLAGS = -std=c++0x	#enables c++11 standards
CXXFLAGS += -Wall	#enables warnings

#target: dependencies
#	action

# Executable output, dependencies, and action *************************** 
mergesort: mergesort.o
	g++ mergesort.o -o mergesort

#tells compiler to create object without executable when modified 
mergesort.o: mergesort.cpp
	g++ -c mergesort.cpp 

#Removes object files and output ****************************************
clean:
	rm *.o mergesort
