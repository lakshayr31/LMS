#include "global.h"
#include"constants.h"
#include <bits/stdc++.h>
#include "ctime"
#include "Book.h"

using namespace std;

string Book::getTitle(){
    return title;
}

string Book::getAuthor(){
    return author;
}

string Book::getISBN(){
    return isbn;
}

string Book::getPublication(){
    return publication;
}

tm Book::getDueDate(){
    return dueDate;
}

bool Book::getCheckedOut(){
    return checkedOut;
} 

string Book::getIssuer(){
    return issuer;
}

void Book::setTitle(string newTitle){
    title = newTitle;
}

void Book::setAuthor(string newAuthor){
    author = newAuthor;
}

void Book::setISBN(string newISBN){
    isbn = newISBN;
}

void Book::setPublication(string newPublication){
    publication = newPublication;
}

void Book::setCheckedOut(bool status){
    checkedOut = status;
}

void Book::setIssuer(string newIssuer){
    issuer = newIssuer;
    cout << "Issued to Id : " << newIssuer << endl;
}
 
void Book::setDueDate(string issuer){
    time_t t = time(0);
    tm* currTime = localtime(&t);
    if(issuer == "STUDENT") t += (-30)*(24*60*60);
    else if(issuer == "PROFESSOR") t += (-60)*(24*60*60);

    currTime = localtime(&t);
    cout << "New Due Date Set to " << endl;
    tm* nextDate = localtime(&t);
    
    dueDate.tm_mday = nextDate->tm_mday;
    dueDate.tm_mon = nextDate->tm_mon;
    dueDate.tm_year = nextDate->tm_year;

    displayDate(&dueDate);

    return;
}


void Book::showDueDate(){
    cout << dueDate.tm_mday << ":" << dueDate.tm_mon << ":" << dueDate.tm_year << endl; 
}

void Book::printBook(){
    cout << "Title : " << title << endl;
    cout << "Author : " << author << endl;
    cout << "ISBN : " << isbn << endl;
    cout << "Publication : " << publication << endl;
    cout << "Checked Out : " << checkedOut << endl;
    if(checkedOut == 1){
        cout << "Issued To ID : " << issuer << endl;
    }
    return;
}

bool Book::operator== (const Book &secondBook){
    return this->isbn == secondBook.isbn;
}