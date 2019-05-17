# ** Zach Reed							      
# ** CS-325							      	 
# ** Makefile for activity.cpp				   
# *********************************************

CXX = g++		#enables g++ as compiler
CXXFLAGS =  -std=c++11	#enables c++11 standards
CXXFLAGS += -Wall	#enables warnings

#target: dependencies
#	action

# Executable output, dependencies, and action *************************** 
activity: activity.o
	g++ $(CXXFLAGS) activity.o -o activity

#tells compiler to create object without executable when modified 
activity.o: activity.cpp
	g++ $(CXXFLAGS) -c activity.cpp 

#Removes object files and output ****************************************
clean:
	rm *.o activity
