# ** Zach Reed							      
# ** CS-325							      	 
# ** Makefile for merge4sort				   
# *********************************************

CXX = g++		#enables g++ as compiler
CXXFLAGS =  -std=c++11	#enables c++11 standards
CXXFLAGS += -Wall	#enables warnings

#target: dependencies
#	action

# Executable output, dependencies, and action *************************** 
merge4sort: merge4sort.o
	g++ $(CXXFLAGS) merge4sort.o -o merge4sort

#tells compiler to create object without executable when modified 
merge4sort.o: merge4sort.cpp
	g++ $(CXXFLAGS) -c merge4sort.cpp 

#Removes object files and output ****************************************
clean:
	rm *.o merge4sort
