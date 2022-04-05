#include "Professor.h"
#include "global.h"

using namespace std;

void Professor::setFineAmount(int amount){
    fineAmount = amount;
}
void Professor::setNumOfBooks(int count){
    numOfBooks = count;
}

int Professor::getFineAmount(){
    return fineAmount;
}

int Professor::getNumOfBooks(){
    return numOfBooks;
}

void Professor::addBook(){
    cout << "Enter the ISBN of the book to be added to the professor" << endl;
    
    Book* book = booksDB.searchBook();
    if(book == NULL){
        cout << "Book cannot be added." << endl;
        return;
    }
    if(book->getCheckedOut() == true){
        cout << "Book already checked out to somebody else." << endl;
    }
    
    borrowedBooks.push_back(*book);
    cout << "Book added." << endl;

    return;
}
void Professor::removeBook(){
    cout << "Choose from the list of the books to be removed." << endl;
    
    for(int i = 0;i<borrowedBooks.size();i++){
        cout << i+1 << " " << endl;
        borrowedBooks[i].printBook();
    }
    cout << "Choose the number : " << endl; 
    string temp;
    getline(cin,temp);
    if(stoi(temp) > 5){
        cout << "Invalid number given. Aborting." << endl;
        return;
    }
    borrowedBooks.erase(borrowedBooks.begin() + stoi(temp) - 1);
    cout << "Removed Book" << endl;
    return;
}

void Professor::displayBooks(){
    cout << "All the Book Checked Out by the professor are" << endl;
    for(auto& book:borrowedBooks){
        book.printBook();
    }
    return;
}