/* 
 * File:   Library.h
 * Created on March 10, 2025, 2:19 AM
 * 
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "User.h"

using namespace std;

class Library {
private:
    static Library* existL; // develops use of Singleton design pattern
    vector<Book*> books; // vectors that hold books
    vector<User*> users; // vector that holds the users
    
public:
    static Library* existingLib(); // implementing Singleton design pattern
    void addBk(Book* book); // adding books function
    void displayLib(); // displaying books function
    void editBk(); // edit the books function
    void removeBk(); // remove any books function
    void addNUser(User* nUser); // adding a user function (faculty/student)
    void displayUsrs(); // displaying the on-file users
    void editUsrs(); // edit users on-file
    void removeUsr(); // remove any users on-file
    void checkB(); // starts check out book process
    void checkinB(); // check in process for books
};




#endif /* LIBRARY_H */

