/* 
 * File:   Book.h
 * Created on March 10, 2025, 2:18 AM
 */

#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string title; // name of the book
    string author; // author of said book
    int ISBN; // ISBN for book
    bool availability = true; // determines whether or not the book can be borrowed
    
public:
    Book(string bookT, string bookA, int bookISBN); 
    // retrieves the information
    string findTitle() const;
    string findAuthor() const;
    int findISBN() const;
    bool ifAvailable() const;
    
    // alternating-switching the values
    void titleChange(const string& tempTitle);
    void authorChange(const string& tempAuth);
    void ISBNchange(const int& tempISBN);
    void chngeAcess(bool tempAvail); 
    
};

#endif /* BOOK_H */

