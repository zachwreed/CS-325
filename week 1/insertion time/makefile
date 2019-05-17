# ** Zach Reed							      
# ** CS-325							      	 
# ** Makefile for insertTime				   
# *********************************************

CXX = g++		#enables g++ as compiler
CXXFLAGS =  -std=c++11	#enables c++11 standards
CXXFLAGS += -Wall	#enables warnings

#target: dependencies
#	action

# Executable output, dependencies, and action *************************** 
insertTime: insertTime.o
	g++ $(CXXFLAGS) insertTime.o -o insertTime

#tells compiler to create object without executable when modified 
insertTime.o: insertTime.cpp
	g++ $(CXXFLAGS) -c insertTime.cpp 

#Removes object files and output ****************************************
clean:
	rm *.o insertTime
