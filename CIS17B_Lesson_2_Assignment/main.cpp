/* 
 * File:   main.cpp
 * Author: Emma Wuysang
 * Note: I'll be attempting to implement the Singleton design method! Also the random "cout<<<endl"'s are purely for aesthetics haha
 * Created on March 10, 2025 1:56 AM
 * Purpose: Develop a Simple Library
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <limits>  // For numeric_limits
#include <vector> // To hold the objects, access multiple
#include "Book.h" // Holds book attributes
#include "User.h" // Holds user attributes
#include "Library.h" // Holds Library attributes & transactions
#include "Student.h" // Header for the user derived class: student
#include "Faculty.h" // Header for the user derived class: faculty

using namespace std;

//Program Execution Begins Here ! :D
int main() {
    
    // Variables
    int slctn;      // selection tool for menu
    int slctnIn;    // selection tool for inside options
    string bookT;   // books title
    string bookA;   // books author
    int bookISBN;   // books isbn
    int user;       // for when adding a user
    string userNm;  // user's name
    int userDgts;   // users randomly assigned digits
    string tempTitl;    // temporary book title
    
    // Instances
    Library* runningLib = Library::existingLib();
    
    
    // Beginning & Menu
    while(slctn!=4){ // while they don't choose to exit basically
        cout<<"Welcome to the Library: \n";
        slctnIn = 0; // reset inside selection
        
 
        // menu for library intro program
        cout << "1. Manage Books\n"
        << "2. Manage Users\n"
        << "3. Manage Transactions\n"
        << "4. Exit\n"
        << "Enter your choice: ";
        cin>>slctn; // selection
        cout<<"\n";
        
        if (cin.fail()){ // USER INPUT HANDLING.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That was not a proper number. OPTIONS (1-4) \n";
        }
        
        switch (slctn){
            case 1: // MANAGE BOOKS
                // menu for when user decides to manage books
                while(slctnIn!=4){
                    cout << "Manage Books: \n";
                    cout << "1. Add a Book\n"
                    << "2. Edit a Book\n"
                    << "3. Remove a Book\n"
                    << "4. Go Back\n\n"
                    << "Enter your choice: ";
                    cin>>slctnIn; // selection
                    cout<<endl;
                    
                    if (cin.fail()){ // USER INPUT HANDLING.
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    
                    switch (slctnIn){ // goes by user's option
                        case 1: // adding a book
                            
                            // THE TITLE
                            cout<<"Enter the Title (0 to cancel): ";
                            cin.ignore(); 
                            getline(cin, bookT); // allows for spaces
                            if(bookT == "0"){ // note: I did get a bit lazy and chose the break pathway..
                                break; // breaks out of case if zero
                            }
                            
                            // THE AUTHOR
                            cout<<"Enter the Author (0 to cancel): ";
                            cin.clear();
                            getline(cin, bookA);
                            if(bookA == "0"){
                                break; // breaks out of case if zero
                            }
                            
                            // THE ISBN 
                            cout<<"Enter the ISBN (0 to cancel): ";
                            cin>>bookISBN;
                            cout<<endl;
                            if(bookISBN == 0){
                                cout<<"You either threw a non-numerical value or decided to cancel, no changes were made.\n";
                                break; // breaks out of case if zero
                            }
                            else{
                                runningLib->addBk(new Book(bookT, bookA, bookISBN));
                                cout<<"Book was successfully added to the library\n\n";
                            }
                            break;
                            
                            
                        case 2: // edit a book
                            runningLib->displayLib();
                            runningLib->editBk();
                            break;
                            
                            
                            
                        case 3: // remove a book 
                            runningLib->displayLib();
                            runningLib->removeBk();
                            break;
                            
                            
                            
                        case 4: // exit
                            break;
                        default: cout << "\nOh no! You choose an invalid choice, please try again. \n\n";
                        
                    }
                }
                break; // end of case 1 in main switch case
     
                
            case 2: // ADD A BOOK
                while(slctnIn!=4){
                    // menu for when user decides to manage users
                    cout << "Manage Users: \n";
                    cout << "1. Add a User\n"
                    << "2. Edit a User\n"
                    << "3. Remove a User\n"
                    << "4. Go Back\n\n"
                    << "Enter your choice: ";
                    cin>>slctnIn; // selection
                    cout<<endl;
                    
                    if (cin.fail()){ // USER INPUT HANDLING.
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    switch (slctnIn){ // goes by user's option
                        
                        // OPTION 1 in MANAGE USERS: SECTION
                        case 1: // Adds user, either student or faculty
                            
                            cout<<"Enter 1 for student or 2 for faculty (0 to cancel): ";
                            cin>>user;
                            cout<<endl;
                            while(cin.fail() || (user != 1 && user != 2 && user != 0)){ // basic input handling
                                cin.clear(); // clears input
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discards the invalid input
                                cout<<"ERROR: Only valid options are  1 or 2\n";
                                cout<<"Enter 1 for student or 2 for faculty (0 to cancel): ";
                                cin>>user;
                                cout<<endl;
                            }
                            cin.ignore();
                            
                            if (user!=0){
                                cout<<"Enter name (0 to cancel): "; 
                                getline(cin,userNm);
                                cout<<endl;
                                if (user!=0){ // if user decides to cancel when inputting their name 
                                    userDgts = rand()%900+100; // id from 100-900

                                    if(user==1){ // if user picks student
                                        runningLib->addNUser(new Student(userNm, userDgts)); // adding a new user from the student class
                                        cout<<"Details: \n"
                                            <<"Name: "<<userNm<<endl
                                            <<"UserID: "<<userDgts<<endl;
                                        cout<<"SYSTEM UPDATE: Successfully added Student user under ID "<<userDgts<<".\n\n";
                                    }
                                    else if(user==2){ // if user picks faculty
                                        runningLib->addNUser(new Faculty(userNm, userDgts)); // adding a new user from the faculty class
                                        cout<<"Details: \n"
                                            <<"Name: "<<userNm<<endl
                                            <<"UserID: "<<userDgts<<endl;
                                        cout<<"SYSTEM UPDATE: Successfully added Faculty user under ID "<<userDgts<<".\n\n";
                                    }
                                }
                            }
                        break;
                        
                        case 2: // Ability to edit a user
                            runningLib->displayUsrs();
                            runningLib->editUsrs();
                        break;
                            
                        case 3: // Ability to remove the user
                        runningLib->displayUsrs();
                        runningLib->removeUsr();
                        break;
                        
                        case 4: // Exiting
                        break;
                        
                        default: cout << "Oh no! You choose an invalid choice, please try again. \n\n";
                    }
                }
                break; // end of case 2
                
            
            // SECTION FOR MANAGING TRANSACTIONS
            case 3: 
                while(slctnIn!=5){ 
                    // menu for when user decides to manage transactions
                    cout << "Manage Transactions: \n";
                    cout << "1. Check Out A Book\n"
                    << "2. Check In A Book\n"
                    << "3. List All Books\n"
                    << "4. List All Users\n"
                    << "5. Go Back\n\n"
                    << "Enter your choice: ";
                    cin>>slctnIn; // selection
                    cout<<endl;
                    
                    if (cin.fail()){ // USER INPUT HANDLING.
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    switch (slctnIn){ // goes by user's option
                        case 1: 
                            runningLib->checkB(); // checking out a book
                            break;
                        case 2: 
                            runningLib->checkinB(); // checking back in a book
                            break;
                            
                        case 3: 
                            runningLib->displayLib(); // displaying the library filled with the books, etc
                            break;
                        case 4: 
                            runningLib->displayUsrs(); // displaying the users and what books they have rented
                            break;
                        
                        case 5: break;
                        default: cout << "Oh no! You choose an invalid choice, please try again. \n\n";
                    }
                }
                break; // end of case 3
                
                
            case 4: // EXIT
                cout<<"Thank you for using the Library System!\n";
                break; // end of case 4

            default: cout << "Oh no! You choose an invalid choice, please try again. \n\n"; // if the user enters a non-numerical value.
        }
    }
    
    //Exit the program
    return 0;
}