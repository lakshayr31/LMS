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
    if(book->getCheckedOut() == 1){
        cout << "Book already checked out to somebody else." << endl;
        return;
    }
    
    borrowedBooks.push_back(book);
    book->setCheckedOut(1);
    book->setIssuer(id);
    book->setDueDate("PROFESSOR");
    cout << "Book added." << endl;

    return;
}
void Professor::removeBook(){
    cout << "Choose from the list of the books to be removed." << endl;
    
    for(int i = 0;i<borrowedBooks.size();i++){
        cout << i+1 << " " << endl;
        borrowedBooks[i]->printBook();
    }
    cout << "Choose the number : " << endl; 
    string temp;
    getline(cin,temp);
    if(stoi(temp) > borrowedBooks.size()){
        cout << "Invalid number given. Aborting." << endl;
        return;
    }
    Book* book = *(borrowedBooks.begin() + stoi(temp) - 1);
    book->setCheckedOut(false);
    book->setIssuer("");
    borrowedBooks.erase(borrowedBooks.begin() + stoi(temp) - 1);
    cout << "Removed Book" << endl;
    return;
}

void Professor::displayBooks(){
    cout << "All the Book Checked Out by the professor are" << endl;
    if(borrowedBooks.size() == 0){
        cout << "No books issued." << endl;
        return;
    }
    for(auto& book:borrowedBooks){
        book->printBook();
    }
    return;
}

void Professor::calculateFineAmount(){
    cout << "Calculating Fine Amount : " << endl;
    cout << "Existing Fine : "<< fineAmount << endl;
    int amount = 0;

    time_t t;
    time(&t);
    tm currTime = *(localtime(&t));

    int days = 0;

    for(auto& book : borrowedBooks){
        tm dueDate = book->getDueDate();
        cout << (currTime.tm_year + 1900) << '-' 
            << (currTime.tm_mon + 1) << '-'
            <<  currTime.tm_mday
            << "\n";
        cout << (dueDate.tm_year + 1900) << '-' 
            << (dueDate.tm_mon + 1) << '-'
            <<  dueDate.tm_mday
            << "\n";
        // if(difftime(mktime(&dueDate),t) > 0){
        if(difftime(mktime(&currTime),mktime(&dueDate)) > 0){
            days += calculateDays(mktime(&currTime),mktime(&dueDate));
        } else {
            cout  << "Time Did not enter" << endl;
        }
    }
    cout << "The days are " << days << endl;
    setFineAmount(days*5);
    return;
}
