#include <bits/stdc++.h>
#include <string>

#include "BooksDB.h"
#include "Book.h"
#include "constants.h"
using namespace std;


void BooksDB::addBook(){
    Book newBook;

    string temp;
    
    cout << "Enter New Book Title : ";
    getline(cin, temp);
    cout << endl;
    newBook.setTitle(temp);

    cout << "Enter New Book Author : ";
    getline(cin, temp);
    cout << endl;
    newBook.setAuthor(temp);

    cout << "Enter New Book ISBN : ";
    getline(cin, temp);
    cout << endl;
    newBook.setISBN(temp);

    cout << "Enter New Book Publication: ";
    getline(cin, temp);
    cout << endl;
    newBook.setPublication(temp);

    cout << "Adding the following book : ";
    newBook.setCheckedOut(0);
    newBook.setIssuer("");
    newBook.printBook();

    cout << "Continue: (Y/N)";
    getline(cin,temp);
    cout << endl;

    if(temp == "Y"){
        bookList.push_back(newBook);
    }
    else {
        cout << "Not Adding Book, kindly retry.";
    }
    return;
}

void BooksDB::displayBooks(){
    cout << "Displaying all books : " << endl;
    for(auto& book : bookList){
        book.printBook();
    }
}

void BooksDB::updateBook(){

    string temp;
    cout << "Updating Book" << endl;

    cout << "Enter Book ISBN : ";
    getline(cin, temp);
    cout << endl;
    
    vector<Book>::iterator it;
    Book book;
    book.setISBN(temp);
    it = find(bookList.begin(),bookList.end(),book);
    if(it!=bookList.end()){
        cout << "Current Book Details:" << endl;
        it->printBook();
    }
    else{
        cout << "No book with this ISBN found.";
        return;
    }

    int toChange = 0;
    cout << "What to change?" << endl;
    cout << "1. Title" << endl;
    cout << "2. Author" << endl;
    cout << "3. ISBN" << endl;
    cout << "4. Publication" << endl;
    cout << "Choose the number ";
    getline(cin,temp);
    
    if(temp == "1"){
        cout << "Enter New Book Title : ";
        getline(cin, temp);
        cout << endl;
        it->setTitle(temp);
    }
    else if(temp == "2"){
        cout << "Enter New Book Author : ";
        getline(cin, temp);
        cout << endl;
        it->setAuthor(temp);
    }
    else if(temp == "3"){
        cout << "Enter New Book ISBN : ";
        getline(cin, temp);
        cout << endl;
        it->setISBN(temp);
    }
    else if(temp == "4"){
        cout << "Enter New Book Publication : ";
        getline(cin, temp);
        cout << endl;
        it->setPublication(temp);
    }
    else {
        cout << "Invalid Option Selected. Please Try Again." << endl;
    }
    
    cout << "Details of the updated book : ";
    it->printBook();
    
    return;
}

Book* BooksDB::searchBook(){

    string temp;
    cout << "Enter Book ISBN : ";
    getline(cin, temp);
    cout << endl;

    vector<Book>::iterator it;
    Book book;
    book.setISBN(temp);
    it = find(bookList.begin(),bookList.end(),book);
    if(it==bookList.end()){
        cout << "No book with this ISBN found.";
        book.setTitle("NA");
        return NULL;
    }
    return &(*it);
}

void BooksDB::deleteBook(){

    string temp;
    cout << "Enter Book ISBN : ";
    getline(cin, temp);
    cout << endl;

    vector<Book>::iterator it;
    Book book;
    book.setISBN(temp);
    it = find(bookList.begin(),bookList.end(),book);
    if(it!=bookList.end()){
        cout << "Book to be deleted : " << endl;
        it->printBook(); 
    }
    else{
        cout << "No book with this ISBN found.";
        return;
    }

    cout << "Do you want to delete this book ? (Y?N)" << endl;
    getline(cin, temp);
    cout << endl;

    if(temp == "Y"){
        bookList.erase(it);
        cout << "Deleted" << endl;
    }
    else {
        cout << "Not able to delete the book." << endl;
    }
    return;
}