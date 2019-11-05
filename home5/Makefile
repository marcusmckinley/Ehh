#******************************************************************* 
#                                                                    
#  Program:  Makefile for Program 1 Student Records 
#                                                                     
#  Author:  Prof. David Chelberg
#  Email: chelberg@ohio.edu
#  ID: PXXXXXXXXX
#                                                                    
#  Course: CS4040
#                                                                    
#  Description:  This file contains a makefile to test code written for prog1
#                
# Originally written for CS4040/5040
#
# last-modified: Mon Oct 28 10:48:21 2019
#                
#*******************************************************************
#
testing: testing.cc student.o FindMaxMin.o 
	g++ -O4 testing.cc student.o FindMaxMin.o -o testing

student.o: student.h student.cc
	g++ -c -O4 student.cc

FindMaxMin.o: FindMaxMin.h FindMaxMin.cc student.h
	g++ -c -O4 FindMaxMin.cc

clean:
	rm testing student.o FindMaxMin.o
