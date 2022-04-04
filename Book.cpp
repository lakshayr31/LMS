#include"constants.h"
#include <bits/stdc++.h>
#include"ctime"
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
}
 
void Book::setDueDate(tm newDueDate){
    dueDate = newDueDate;
}

void Book::showDueDate(){
    cout << dueDate.tm_mday << ":" << dueDate.tm_mon << ":" << dueDate.tm_year << endl; 
}

void Book::printBook(){
    cout << "Title : " << title << endl;
    cout << "Author : " << author << endl;
    cout << "ISBN : " << isbn << endl;
    cout << "Publication : " << publication << endl;
}

bool Book::operator== (const Book &secondBook){
    return this->isbn == secondBook.isbn;
}