//******************************************************************* 
//                                                                    
//  Program:  Program 1 Student Records FindMaxMin.cc
//                                                                     
//  Author:  Prof. David Chelberg
//  Email: chelberg@ohio.edu
//  ID: PXXXXXXXXX
//                                                                    
//  Course: CS4040
//                                                                    
//  Description:  This file contains the code to find the max and min
//                items in a vector of students. As well as the second
//                max and second min.
//                
// Originally written for CS4040/5040
//
// last-modified: Mon Oct 28 11:23:04 2019
//                
//*******************************************************************
//
#include "FindMaxMin.h"

//******************************************************************
//                                                                  
//  Function: FindMaxMin
//                                                                  
//  Purpose:  
//            
//                                                                  
//  Parameters:  
//               
//                                                                  
//  Calls:  
//
//  Time complexity:   
//
//  Space complexity:  
//                                                                  
//******************************************************************
void FindMaxMin(const vector<Student> &students, 
                size_t &max, size_t &max2,
                size_t &min, size_t &min2)
{
  // Your code here

  // This is just a stub. It doesn't compute the correct answer!
  if (Compare::lt(students[0],students[1])) {
    max = 1;
    max2 = 0;
  } else {
    max = 0;
    max2 = 1;
  }
  if (Compare::lt(students[2],students[3])) {
    min = 2;
    min2 = 3;
  } else {
    min = 3;
    min2 = 2;
  }
  for (size_t i=2; i<students.size(); ++i) {
    if (Compare::lt(students[max],students[i])) {
      max = i;
    }
  }
  for (size_t i=0; i<students.size(); ++i) {
    if (Compare::lt(students[i],students[min])) {
      min = i;
    }
  }
}

//******************************************************************
//                                                                  
//  Function: FindMaxMinGPA
//                                                                  
//  Purpose:  
//            
//                                                                  
//  Parameters:  
//               
//                                                                  
//  Calls:  
//
//  Time complexity:   
//
//  Space complexity:  
//                                                                  
//******************************************************************
void FindMaxMinGPA(const vector<Student> &students, 
		   size_t &max, size_t &max2,
		   size_t &min, size_t &min2)
{
  // Your code here
  // This is just a stub. It doesn't compute the correct answer!
  if (CompareGPA::lt(students[0],students[1])) {
    max = 1;
    max2 = 0;
  } else {
    max = 0;
    max2 = 1;
  }
  if (CompareGPA::lt(students[2],students[3])) {
    min = 2;
    min2 = 3;
  } else {
    min = 3;
    min2 = 2;
  }
  for (size_t i=2; i<students.size(); ++i) {
    if (CompareGPA::lt(students[max],students[i])) {
      max = i;
    }
  }
  for (size_t i=0; i<students.size(); ++i) {
    if (CompareGPA::lt(students[i],students[min])) {
      min = i;
    }
  }
}
