//******************************************************************* 
//                                                                    
//  Program:  Program 1 Student Records 
//                                                                     
//  Author:  Prof. David Chelberg
//  Email: chelberg@ohio.edu
//  ID: PXXXXXXXXX
//                                                                    
//  Course: CS4040
//                                                                    
//  Description:  This file contains code to test a solution to this
//                homework problem.
//
//                This file is provided for your benefit.  It
//                illustrates a potential implementation of a main
//                program that tests your algorithm for this problem.
//
//                It also illustrates one way to compute the time your
//                program takes to complete its task in real-world
//                seconds, which can be used to compare two potential
//                implementations to see which one might be faster.
//                
// Originally written for CS4040/5040
//
// last-modified: Mon Oct 28 11:07:32 2019
//                
//*******************************************************************

// NOTE: The code in this file does NOT conform completely to the
// style guidelines for this class, so would not get full points if
// submitted as is.

#include <vector>
#include <cstdlib>
#include <iostream>
#include <sys/time.h>
#include "student.h"
#include "FindMaxMin.h"
using std::vector;
using std::cout;
using std::endl;

/*! Name: timeval2Sec
    
    Description: Computes the number of seconds from a timeval in 
                 microseconds.
      
    Side effects: None.

    \param T The timeval in microseconds.

    \return double The number of seconds in the timeval.
*/
double timeval2sec(const timeval& T) {
  // Constant for time unit conversion
  const double USEC_TO_SEC = 1000000.0;

  return ((double) T.tv_sec + (double) (T.tv_usec / USEC_TO_SEC));
}

/*! Name: timeofday
  
    Description: Computes the time of day in seconds.
    
    Side effects: Gets the time of day and stores it in T.

    \return timeval2sec(T) The time of day in seconds.
*/
double timeofday() {
  timeval T;
  gettimeofday(&T, NULL);
  return (timeval2sec(T));
}
  
// Sample generateStudents, needs more comments.
//
// One way you can implement this is to randomly generate student
// records
//
// Hint: to ensure no two students have the same name, and SSN, you
// could make the SSN be equal to the index i (see below).
vector<Student> generateStudents(size_t num)
{
  timeval T;
  gettimeofday(&T, NULL);
  // Sets the random number seed to the number of microseconds in the
  // current time.
  srand48(T.tv_usec);
  vector <Student> testing;
  for (size_t i = 0; i<num; ++i) {
    Student a;
    a.SSN=std::to_string(i);
    a.gpa=drand48();
    // etc.
    // You should have code to generate random names and the other
    // fields as well. They don't have to make sense, but need to be
    // different from each other.
    testing.push_back(a);
  }
  return(testing);
}

// Sample Main, needs more comments.
int main ()
{
  vector<Student> Students;

  // Note the following value is just for illustration, you should
  // test your code on many different sized inputs.
  const size_t NUM_STUDENTS=1000000;

  // Is this in the right place for this statement?
  double start=timeofday();

  // Test first function.
  Students = generateStudents(NUM_STUDENTS);

  Compare::clear();
  size_t min1, min2, max1,max2;
  FindMaxMin(Students, max1, max2, min1, min2);

  cout << "FindMaxMin took " << timeofday() - start << " seconds" 
       << " on input of size " << NUM_STUDENTS << endl;

  cout << "FindMaxMin took " << Compare::get_count() << " comparisons" 
       << " on input of size " << NUM_STUDENTS << endl;

  cout << "Min1 at " << min1<<" min2 at " << min2 << " max1 at " << max1 << " max2 at " << max2 << endl;
  cout << "Min1\n" << Students[min1] << endl;
  cout << "Min2\n" << Students[min2] << endl;
  cout << "Max1\n" << Students[max1] << endl;
  cout << "Max2\n" << Students[max2] << endl;

  // Now test second function.
  start=timeofday();

  CompareGPA::clear();
  FindMaxMinGPA(Students, max1, max2, min1, min2);

  cout << "FindMaxMinGPA took " << timeofday() - start << " seconds" 
       << " on input of size " << NUM_STUDENTS << endl;

  cout << "FindMaxMinGPA took " << CompareGPA::get_count() << " comparisons" 
       << " on input of size " << NUM_STUDENTS << endl;

  cout << "Min1 at " << min1<<" min2 at " << min2 << " max1 at " << max1 << " max2 at " << max2 << endl;
  cout << "Min1 = " << Students[min1] << endl;
  cout << "Min2 = " << Students[min2] << endl;
  cout << "Max1 = " << Students[max1] << endl;
  cout << "Max2 = " << Students[max2] << endl;

  return(EXIT_SUCCESS);
}
