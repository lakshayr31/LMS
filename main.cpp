#include "Book.h"
#include "BooksDB.h"
#include "bits/stdc++.h"

using namespace std;

int main(){
    cout << "Making a Books Database " << endl;
    BooksDB booksDB;
    string temp;
    cout << "Do you want to add a book?(Y/N)" << endl;
    getline(cin,temp);
    
    if(temp == "Y"){
        booksDB.addBook();
    }

    // booksDB.displayBooks();
    cout << "Trying to find a book";
    booksDB.searchBook();
    booksDB.updateBook();
    booksDB.deleteBook();
    booksDB.displayBooks();
    return 0;
}