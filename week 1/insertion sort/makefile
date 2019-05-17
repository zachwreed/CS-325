# ** Zach Reed							      
# ** CS-325							      	 
# ** Makefile for insertsort				   
# *********************************************

CXX = g++		#enables g++ as compiler
CXXFLAGS = -std=c++0x	#enables c++11 standards
CXXFLAGS += -Wall	#enables warnings

#target: dependencies
#	action

# Executable output, dependencies, and action *************************** 
insertsort: insertsort.o
	g++ insertsort.o -o insertsort

#tells compiler to create object without executable when modified 
insertsort.o: insertsort.cpp
	g++ -c insertsort.cpp 

#Removes object files and output ****************************************
clean:
	rm *.o insertsort
