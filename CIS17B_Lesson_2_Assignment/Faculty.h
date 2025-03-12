/* 
 * File:   Faculty.h
 * Created on March 10, 2025, 10:42 PM
 */

#ifndef FACULTY_H
#define FACULTY_H
#include "User.h"

#include <string>
#include <iostream>
using namespace std;

class Faculty : public User { // derived class
public:
    Faculty(string userN, int uIdnty) : User(userN, uIdnty) {} // initializer list deriving from user
    string usrTyp() const override{return "Faculty";} // delivering the user type
};

#endif /* FACULTY_H */

