/* 
 * File:   Student.h
 * Created on March 10, 2025, 10:42 PM
 */

#ifndef STUDENT_H
#define STUDENT_H
#include "User.h"

#include <string>
#include <iostream>
using namespace std;

class Student : public User{
public:
   Student(string userN, int uIdnty) : User(userN, uIdnty) {} // initializer list deriving from user
   string usrTyp() const override{return "Student";} // delivering the user type
};

#endif /* STUDENT_H */

