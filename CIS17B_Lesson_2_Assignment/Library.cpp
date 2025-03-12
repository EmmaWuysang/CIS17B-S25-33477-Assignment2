/* 
 * File:   Library.cpp
 * Created on March 10, 2025, 2:19 AM
 */

#include "Library.h"
#include <iostream>
#include <string>
#include <limits>  // For numeric_limits
#include "User.h"

Library* Library::existL = nullptr; // handles if library exists or not

Library* Library::existingLib(){
        if (!existL){
            existL = new Library();
        }
        return existL;
};

void Library::displayLib(){ // to display what is inside the library
    if (books.empty()){ // if empty, it notifies user
        cout<<"The Library is currently empty.\n";
        return;
    }
    else{
        
        cout<<"Current Books Available in Library\n"; // uses a range loop to display the books
        cout<<"\n________________________________________\n";
        for(int i = 0; i<(books.size()); i++){
            // each variable accessed by member function
            cout << "Option ("<< i+1 << ") Title : " << books[i]->findTitle() 
            << "\nWritten by: " << books[i]->findAuthor()
            << "\nISBN: " << books[i]->findISBN()
            << "\nAvailable? " << (books[i]->ifAvailable() == 1? "true" : "false") << "\n"; // ternary operator for the bool a.k.a availability
            cout<<"________________________________________\n";
            
        }
    }      
}


void Library::editBk(){ // edit book information
    if (books.empty()){
        return; // returns if no books
    }
    
    cout<<"Enter the number correlated to the option of the book.\n"; 
    int bookIndex = -1; // holds the book index
    cin>>bookIndex;  

    bookIndex = bookIndex-1;

    // temporary values to alter the private variables
    int tempVal = 0;
    string tempTitle = "", tempAuth = "";
    Book* selectedBook = books[bookIndex];

    if (bookIndex<books.size() && books.size()!=0){ // if your index is within the indices
        cout<<"\nEnter new Title: \n"; // changing book title
        cin.ignore();
        getline(cin,tempTitle);
        selectedBook->titleChange(tempTitle);
        cout<<endl;

        cout<<"Enter new Author: \n"; // changing to new author
        cin.clear();
        getline(cin, tempAuth);
        selectedBook->authorChange(tempAuth);
        cout<<endl;

        cout<<"Enter new ISBN: \n"; // changing the isbn
        cin>>tempVal;
        selectedBook->ISBNchange(tempVal);
        cout<<endl;
    }
    else{
        cout<<"\nInvalid selection, heading back to main menu!\n";
    }

}

void Library::addBk(Book* book){ // adding a book
    books.push_back(book); // push into book vector
    
}

void Library::removeBk(){ // removing a book
    if (books.empty()){
        return; // returns if no books
    }
    int bookIndex;
    cout<<"Please choose which book you would prefer to remove: (numerical value)\n";
    cin>>bookIndex;
    if (cin.fail()){ // USER INPUT HANDLING.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "That was not a number option \n";
    }
 
    if (bookIndex > 0 && bookIndex <= books.size()){
        books.erase(books.begin() + bookIndex - 1); // this should erase the unwanted value by index in the vector
        cout<<"\nBook was removed successfully!\n";
    }
    else{
        cout<<"Invalid number, going back to main menu...\n";
    }
}


void Library::addNUser(User* nUser){ // adding a new user, similar to adding a book
    users.push_back(nUser);
}

void Library::displayUsrs(){ // displaying the users on file
    if (users.empty()){ // if ther are no users
        cout<<"There are currently no registered users.\n\n";
        return;
    }
    else{
        
        cout<<"Current Users on file are: "; // uses member functions from user to display details
        cout<<"\n________________________________________\n";
        for(int i = 0; i<(users.size()); i++){
            cout << "\nUser Name: " << users[i]->findName()
            << "\nUser ID: " << users[i]->findID()
            << "\nUser Type: " << users[i]->usrTyp();
            
            vector<Book*> borrowedBks = users[i]->getBorrowedBooks();   // all the borrowed books to the user
            
            if(!borrowedBks.empty()){ //states which books are borrowed by users
                cout << "\nBooks Rented by User: \n";
                for(Book* book:borrowedBks){
                    cout<<"\n-> Book: " << book->findTitle() 
                        << "\n Author: " << book->findAuthor()
                        << "\n ISBN: " << book->findISBN() <<endl;
                }
            }
            else{
                cout<<"\nThere are no Books Rented by (most recent/selected) user. \n";
            }
            cout<<"\n________________________________________\n";
        }  
    }      
}

void Library::editUsrs(){ // edit details of the user
    if (users.empty()){
        return;
    }
    cout<<"Enter the option number correlated to the user on file.\n";
    int usrIndex = -1;
    cin>>usrIndex;  

    // temporary values to alter the private variables
    int tempVal = 0;
    string tempNme = "", tempID = "";
    User* selectedUser = users[usrIndex];

    while(cin.fail() || usrIndex < 1 || usrIndex > users.size()){ // INPUT HANDLING
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discards false value
        cout<<"That was an invalid option. Please enter a number between 1 and " << users.size() <<endl;
        cin>>usrIndex;
    }
    usrIndex -= 1;
    
    cout<<"\nEnter new Name: \n"; // ability to change the name
    cin.ignore();
    getline(cin,tempNme);
    users[usrIndex]->nameChange(tempNme);
    cout<<endl;
    cout<<"SYSTEM UPDATE: Successfully changed name of user option "<<usrIndex<<".\n";


}


void Library::removeUsr(){ // removing a user from the user-list
    if (users.empty()){
        return;
    }
    int usrIndex;
    cout<<"Please choose which user you would prefer to remove: (numerical value)\n";
    cin>>usrIndex;
    if (cin.fail()){ // USER INPUT HANDLING.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "That was not a number option \n";
    }
 
    if (usrIndex > 0 && usrIndex <= users.size()){
        users.erase(users.begin() + usrIndex - 1); // this should erase the unwanted value by index in the vector
        cout<<"\nUser was removed successfully!\n";
    }
    else{
        cout<<"Invalid number, going back to main menu...\n";
    }
}

void Library::checkB(){ // checkout books
    // mini variables that will be used in this function
    string tempTitl;
    int ID;
    
    // what book name the user w ants
    cout << "Check Out A Book\n";
    cout << "Book Title (or 0 to cancel): ";
    cin.ignore();
    getline(cin, tempTitl);
    cout<<endl;
    
    if(tempTitl == "0"){
        cout<<"Returning back to main menu.\n";
        return;
    }
    
    Book* chosenBk = nullptr; // holds a pointer to the books
    for(Book* book: books){
        if(book->findTitle() == tempTitl){ // compares the titles to the user inputted one
            chosenBk = book;
        }
    }
    
    if(!chosenBk){ // if chosen book is not found
        cout<< "!! Error: No book with the title, " << tempTitl << ", exists !!\n\n";
        return;
    }
    
    if(!chosenBk->ifAvailable()){ // if the book is available by the bool
        cout << "!! Error: The book with the title, " << tempTitl << ", is currently unavailable at the moment !!\n\n";
        return; // book is no available
    }
    
    cout <<"User ID (or 0 to cancel):"; // mirrored same process as the books
    cin>>ID;
    
    if(ID == 0){
        cout<<"Checkout was cancelled. \n";
        return; // exits before checkout
    }
    
    User* chosenUsr = nullptr;
    for(User* user: users){
        if(user->findID() == ID){ // compares the generated IDs
            chosenUsr = user;
        }
    }
    
    if(!chosenUsr){
        cout << "!! Error: No user with ID " << ID << " exists !!\n";
        return;
    }
    
    // book checkout area after dealing with possible cases
    chosenUsr->borrowedItm(chosenBk); // borrows the specific book
    chosenBk->chngeAcess(false); // changes the availability of the book
    
    // user notification of their action
    cout << "The book \"" << chosenBk->findTitle() << "\" has been checked out by user "
         << chosenUsr->findName() << ".\n\n";
    
}

void Library::checkinB(){ // same process as checking out a book, just reversed
    // variables used in this function
    string tempTitl;
    int ID;
    cout << "Check In A Book\n";
    cout << "Book Title (or 0 to cancel): ";
    cin.ignore();
    getline(cin, tempTitl);
    cout<<endl;
    
    if(tempTitl == "0"){
        cout<<"Returning back to main menu.\n";
        return;
    }
    
    Book* chosenBk = nullptr;
    for(Book* book: books){
        if(book->findTitle() == tempTitl){ // comparison
            chosenBk = book;
        }
    }
    
    if(!chosenBk){ // if chosen book is not found
        cout<< "!! Error: No book with the title, " << tempTitl << ", exists !!\n\n";
        return;
    }
    
    if(chosenBk->ifAvailable()){
        cout << "!! Error: The book with the title, " << tempTitl << ", is already available at the moment !!\n\n";
        return; // book is already available
    }
    
    cout <<"User ID (or 0 to cancel):";
    cin>>ID;
    
    if(ID == 0){
        cout<<"Checkout was cancelled. \n";
        return; // exits before checkout
    }
    
    User* chosenUsr = nullptr;
    for(User* user: users){
        if(user->findID() == ID){ // comparison
            chosenUsr = user;
        }
    }
    
    if(!chosenUsr){
        cout << "!! Error: No user with ID " << ID << " exists !!\n";
        return;
    }
    
    // book checkout area after dealing with possible cases
    chosenUsr->deliverItm(chosenBk); // returning the item
    chosenBk->chngeAcess(true); // changing the availability back to open
    
    // notifying the user
    cout << "The book " << chosenBk->findTitle() << " has been checked in by user "
         << chosenUsr->findName() << ".\n\n";
    
}