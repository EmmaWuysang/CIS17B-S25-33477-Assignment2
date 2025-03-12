/* 
 * File:   Book.cpp
 * Created on March 10, 2025, 2:18 AM
 */

#include "Book.h"

Book::Book(string bookT, string bookA, int bookISBN) : title(bookT), author(bookA), ISBN(bookISBN) {} // initializer list

string Book::findTitle() const{ // returns book title
    return title;
}

string Book::findAuthor() const{ // returns author
    return author;
}

int Book::findISBN() const{ // returns ISBN
    return ISBN;
}

bool Book::ifAvailable() const{ // returns a bool for availability
    return availability;
}

void Book::titleChange(const string& tempTitle){ // changing the title
    title = tempTitle;
}

void Book::authorChange(const string& tempAuth){ // changing the author
    author = tempAuth;
}

void Book::ISBNchange(const int& tempISBN){ // changing ISBN
    ISBN = tempISBN;
}

void Book::chngeAcess(bool tempAvail){ // changing availability
    availability = tempAvail;
}