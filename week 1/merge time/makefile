# ** Zach Reed							      
# ** CS-325							      	 
# ** Makefile for mergeTime				   
# *********************************************

CXX = g++		#enables g++ as compiler
CXXFLAGS =  -std=c++11	#enables c++11 standards
CXXFLAGS += -Wall	#enables warnings

#target: dependencies
#	action

# Executable output, dependencies, and action *************************** 
mergeTime: mergeTime.o
	g++ $(CXXFLAGS) mergeTime.o -o mergeTime

#tells compiler to create object without executable when modified 
mergeTime.o: mergeTime.cpp
	g++ $(CXXFLAGS) -c mergeTime.cpp 

#Removes object files and output ****************************************
clean:
	rm *.o mergeTime
