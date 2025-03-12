/* 
 * File:   User.h
 * Created on March 10, 2025, 2:19 AM
 */

#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

class User { // parent class to faculty and student
private: // private variables only used by the class's member functions
    string name;
    int userID;
    vector<Book*> borrowedBks; // vector for the borrowed books
        
public:
    User(string userN, int uIdnty): name(userN), userID(uIdnty) {} // initializer constructor (user name and user identity)
    vector<Book*> getBorrowedBooks() const { return borrowedBks; } // return the container for the borrowed books
    string findName() const; // returning the user's name
    int findID() const; // returning the user's ID
    void nameChange(const string& tempNme); // changing the user's name
    void borrowedItm(Book* book); // when a user wants to borrow a book
    void deliverItm(Book* book); // when a user wants to return the book
    virtual string usrTyp() const = 0; // virtual pure function
    virtual ~User() {} // destructor for cleanup
}; 

#endif /* USER_H */

