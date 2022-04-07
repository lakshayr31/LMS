#include "Student.h"
#include "global.h"

using namespace std;

void Student::setFineAmount(int amount){
    fineAmount = amount;
}
void Student::setNumOfBooks(int count){
    numOfBooks = count;
}

int Student::getFineAmount(){
    return fineAmount;
}

int Student::getNumOfBooks(){
    return numOfBooks;
}

void Student::addBook(){
    cout << "Enter the ISBN of the book to be added to the student" << endl;
    
    Book* book = booksDB.searchBook();
    if(book == NULL){
        cout << "Book cannot be added." << endl;
        return;
    }
    if(book->getCheckedOut() == true){
        cout << "Book already checked out to somebody else." << endl;
        return;
    }
    if(numOfBooks > 5){
         cout << "Already checked out 5 books, cannot issue more." << endl;
         return;
    }
    
    borrowedBooks.push_back(book);
    book->setCheckedOut(1);
    book->setIssuer(id);
    book->setDueDate("STUDENT");
    cout << "Book added." << endl;

    return;
}
void Student::removeBook(){
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
    book->setCheckedOut(0);
    book->setIssuer("");
    borrowedBooks.erase(borrowedBooks.begin() + stoi(temp) - 1);

    cout << "Removed Book" << endl;

    return;
}

void Student::displayBooks(){
    cout << "All the Book Checked Out by the student are" << endl;
    if(borrowedBooks.size() == 0){
        cout << "No books issued." << endl;
        return;
    }
    for(auto& book:borrowedBooks){
        book->printBook();
    }
    return;
}

void Student::calculateFineAmount(){
    cout << "Calculating Fine Amount : " << endl;
    cout << "Existing Fine : "<< fineAmount << endl;
    int amount = 0;

    time_t t = time(0);
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
        if(diffDays(&dueDate,&currTime) > 0){
            days += diffDays(&dueDate,&currTime);
        } 
    }

    if(days == 0){
        cout << "No fine to be imposed." << endl;
        return;
    }
    cout << "The number of days are " << days << endl;
    cout << "The amount is " << days*5 << endl;
    setFineAmount(days*5);

    return;
}


