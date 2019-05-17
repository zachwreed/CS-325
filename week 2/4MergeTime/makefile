# ** Zach Reed							      
# ** CS-325							      	 
# ** Makefile for merge4Time				   
# *********************************************

CXX = g++		#enables g++ as compiler
CXXFLAGS =  -std=c++11	#enables c++11 standards
CXXFLAGS += -Wall	#enables warnings

#target: dependencies
#	action

# Executable output, dependencies, and action *************************** 
merge4Time: merge4Time.o
	g++ $(CXXFLAGS) merge4Time.o -o merge4Time

#tells compiler to create object without executable when modified 
merge4Time.o: merge4Time.cpp
	g++ $(CXXFLAGS) -c merge4Time.cpp 

#Removes object files and output ****************************************
clean:
	rm *.o merge4Time
