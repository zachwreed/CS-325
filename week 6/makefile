# ** Zach Reed							      
# ** CS-325							      	 
# ** Makefile for wrestler.cpp				   
# *********************************************

CXX = g++		#enables g++ as compiler
CXXFLAGS =  -std=c++11	#enables c++11 standards
CXXFLAGS += -Wall	#enables warnings

#target: dependencies
#	action

# Executable output, dependencies, and action *************************** 
wrestler: wrestler.o
	g++ $(CXXFLAGS) wrestler.o -o wrestler

#tells compiler to create object without executable when modified 
wrestler.o: wrestler.cpp
	g++ $(CXXFLAGS) -c wrestler.cpp 

#Removes object files and output ****************************************
clean:
	rm *.o wrestler
