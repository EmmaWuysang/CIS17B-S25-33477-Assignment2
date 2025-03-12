/* 
 * File:   User.cpp
 * Created on March 10, 2025, 2:19 AM
 */

#include "User.h"


string User::findName() const{ // returns user's name
    return name;
}

int User::findID() const{ // returns the user's unique ID
    return userID;
}

void User::nameChange(const string& tempNme){ // user's name change
    name = tempNme;
}

void User::borrowedItm(Book* book){ // renting the book
    if (book->ifAvailable()){
        borrowedBks.push_back(book); // pushes back into the vector for the borrowed books
        book->chngeAcess(false);
        cout<<"SYSTEM UPDATE: The book was successfully rented out! \n";
    }
    else{
        cout<<"SYSTEM UPDATE: The book was not available! Not successfully rented. \n";
    }
}

void User::deliverItm(Book* book){ // removes the book from the borrowed list
    for(int i =0; i< borrowedBks.size(); i++){
        if(borrowedBks[i]==book){
            borrowedBks.erase(borrowedBks.begin() + i);  // erases the indexed book from the borrowed books
        }
    }
}
