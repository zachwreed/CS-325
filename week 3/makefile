# ** Zach Reed							      
# ** CS-325							      	 
# ** Makefile for shopping.cpp				   
# *********************************************

CXX = g++		#enables g++ as compiler
CXXFLAGS =  -std=c++11	#enables c++11 standards
CXXFLAGS += -Wall	#enables warnings

#target: dependencies
#	action

# Executable output, dependencies, and action *************************** 
shopping: shopping.o
	g++ $(CXXFLAGS) shopping.o -o shopping

#tells compiler to create object without executable when modified 
shopping.o: shopping.cpp
	g++ $(CXXFLAGS) -c shopping.cpp 

#Removes object files and output ****************************************
clean:
	rm *.o shopping
