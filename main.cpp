#include "global.h"
#include "Book.h"
#include "BooksDB.h"
#include "User.h"
#include "UserDB.h"
#include "Student.h"
#include "Librarian.h"
#include "Professor.h"
#include "bits/stdc++.h"

using namespace std;

BooksDB booksDB;
UserDB usersDB;

int diffDays(tm* date1, tm* date2){
    int days = 0;
    if(date2->tm_mon > date1->tm_mon){
        days += 30*(date2->tm_mon - date1->tm_mon - 1);

        days += (30 - date1->tm_mday) + date2->tm_mday;
        
    }
    else if(date2->tm_mon == date1->tm_mon){
        if(date2->tm_mday > date1->tm_mday){
            days += (date2->tm_mday - date1->tm_mday);
        }
    }
    return days;
}

void displayDate(tm* date){
    cout << date->tm_mday <<  ":" <<  date->tm_mon + 1<<":" << date->tm_year + 1900 << endl;
}

void showLibrarianOptions(){

    string givenId;
    string givenPassword;

    cout << "Enter ID " << endl;

    cin >> givenId; 
    
    cout << "Enter Password " << endl;

    cin >> givenPassword;

    Librarian* lib = (Librarian*)usersDB.searchUserByIdAndPassword(givenId,givenPassword);
    if(lib == NULL){
        return;
    }
    lib->printUser();
    if(lib->getType() != "LIBRARIAN"){
        cout << "Wrong UserName and Password for the given options" << endl;
        return;
    }

    while(1)
    {
        int choice;
        cout<<"What would you like to do?"<<endl;
        cout<<"1. Add User"<<endl;
        cout<<"2. Update Existing User"<<endl;
        cout<<"3. Delete User"<<endl;
        cout<<"4. List All Users"<<endl;
        cout<<"5. Add Book"<<endl;
        cout<<"6. Update Existing Book"<<endl;
        cout<<"7. Delete Book"<<endl;
        cout<<"8. List All Books"<<endl;
        cout<<"9. Get Book Details"<<endl;
        cout<<"10. Get Book List Of User"<<endl;
        cout<<"11. Logout"<<endl;
        cin>>choice;    
        cin.ignore(100,'\n');

        if(choice == 1)
        {
            usersDB.addUser(0);
        }
        else if(choice == 2)
        {
            usersDB.updateUser();
        }
        else if(choice == 3)
        {
            usersDB.deleteUser();
        }
        else if(choice == 4)
        {
            usersDB.displayUsers();
        }
        else if(choice == 5)
        {
            booksDB.addBook();
        }
        else if(choice == 6)
        {
            booksDB.updateBook();
        }
        else if(choice == 7)
        {
            booksDB.deleteBook();
        }
        else if(choice == 8)
        {
            booksDB.displayBooks();
        }
        else if(choice == 9)
        {
            Book* book = booksDB.searchBook();
            book->printBook();
        }
        else if(choice == 10)
        {
            User* user = usersDB.searchUser();
            if(user->getType() == "STUDENT"){
                Student* student = (Student*)user;
                student->displayBooks();
            }
            else if(user->getType() == "PROFESSOR"){
                Professor* professor = (Professor*)user;
                professor->displayBooks();
            }
            else{
                cout << "This user does not issue books" << endl;
            }
        }
        else if(choice == 11)
        {
            break;
        }
        else{
            cout << "Invalid Reponse. Retry" << endl;
        }
    }
}


void showProfessorOptions(){
    string givenId;
    string givenPassword;

    cout << "Enter ID " << endl;

    cin >> givenId; 
    
    cout << "Enter Password " << endl;

    cin >> givenPassword;

    Professor* prof = (Professor*)usersDB.searchUserByIdAndPassword(givenId,givenPassword);
    if(prof == NULL){
        return;
    }
    if(prof->getType() != "PROFESSOR"){
        cout << "Wrong UserName and Password for the given options" << endl;
        return;
    }

    while(1)
    {
        int choice;
        cout<<"What would you like to do?"<<endl;
        cout<<"1. Show All Books"<<endl;
        cout<<"2. Show My Checked Out Books"<<endl;
        cout<<"3. Find Info Of A Book"<<endl;
        cout<<"4. Issue Book"<<endl;
        cout<<"5. See Fine Amount"<<endl;
        cout<<"6. Return Book"<<endl;
        cout<<"7. Logout"<<endl;
        cin>>choice;
        cin.ignore(100,'\n');

        if(choice == 1)
        {
            booksDB.displayBooks();
        }
        else if(choice == 2)
        {
            prof->displayBooks();
        }
        else if(choice == 3)
        {
            Book* book = booksDB.searchBook();
            book->printBook();
        }
        else if(choice == 4)
        {
            prof->addBook();
        }
        else if(choice == 5)
        {
            prof->calculateFineAmount();
        }
        else if(choice == 6)
        {
            prof->removeBook();
        }
        else if(choice == 7)
        {
            break;
        }
        else{
            cout << "Invalid Reponse. Retry" << endl;
        }
    }
}

void showStudentOptions(){

    string givenId;
    string givenPassword;

    cout << "Enter ID " << endl;

    cin >> givenId; 
    
    cout << "Enter Password " << endl;

    cin >> givenPassword;


    Student* student = (Student*)usersDB.searchUserByIdAndPassword(givenId,givenPassword);
    if(student == NULL){
        return;
    }
    if(student->getType() != "STUDENT"){
        cout << "Wrong UserName and Password for the given options" << endl;
        return;
    }

    while(1)
    {
        int choice;
        cout<<"What would you like to do?"<<endl;
        cout<<"1. Show All Books"<<endl;
        cout<<"2. Show My Checked Out Books"<<endl;
        cout<<"3. Find Info Of A Book"<<endl;
        cout<<"4. Issue Book"<<endl;
        cout<<"5. See Fine Amount"<<endl;
        cout<<"6. Return Book"<<endl;
        cout<<"7. Logout"<<endl;
        cin>>choice;
        cin.ignore(100,'\n');

        if(choice == 1)
        {
            booksDB.displayBooks();
        }
        else if(choice == 2)
        {
            student->displayBooks();
        }
        else if(choice == 3)
        {
            Book* book = booksDB.searchBook();
            book->printBook();
        }
        else if(choice == 4)
        {
            student->addBook();
        }
        else if(choice == 5)
        {
            student->calculateFineAmount();
        }
        else if(choice == 6)
        {
            student->removeBook();
        }
        else if(choice == 7)
        {
            break;
        }
        else{
            cout << "Invalid Reponse. Retry" << endl;
        }
    }
}


int main(){

    int choice;
    cout<<"********************* Welcome To Library Management System ********************"<<endl;
    cout << "Adding First User as Librarian" << endl;
    
    usersDB.addUser(1);
    
    while(1)
    {
        cout<<"Who are you?"<<endl;
        cout<<"1. Librarian"<<endl;
        cout<<"2. Professor"<<endl;
        cout<<"3. Student"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>choice;
        cin.ignore(100,'\n');

        if(choice == 1)
        {
            showLibrarianOptions();
        }
        else if(choice == 2)
        {
            showProfessorOptions();
        }
        else if(choice == 3)
        {
            showStudentOptions();
        }
        else if(choice == 4)
        {
            break;
        }
        else{
            cout << "Invalid Reponse. Retry" << endl;
        }
    }

    cout<<"Thank You for using our software"<<endl<<"Have a Nice Day !"<<endl;
    return 0;
    
    // cout << "Making a Books Database " << endl;
    // string temp;
    // cout << "Do you want to add a book?(Y/N)" << endl;
    // getline(cin,temp);
    
    // if(temp == "Y"){
    //     booksDB.addBook();
    // }

    // // booksDB.displayBooks();
    // // booksDB.updateBook();
    // // booksDB.deleteBook();
    // cout << "Do you want to add a book?(Y/N)" << endl;
    // getline(cin,temp);
    
    // if(temp == "Y"){
    //     booksDB.addBook();
    // }

    // booksDB.displayBooks();

    // Student student1;
    // student1.addBook();
    // student1.displayBooks();
    // student1.displayBooks();
    // student1.calculateFineAmount();

    return 0;
}