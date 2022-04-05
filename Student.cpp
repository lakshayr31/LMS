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
    }
    if(numOfBooks > 5){
         cout << "Already checked out 5 books, cannot issue more." << endl;
    }
    
    borrowedBooks.push_back(*book);
    book->setCheckedOut(true);
    book->setIssuer(id);
    book->setDueDate();
    cout << "Book added." << endl;

    return;
}
void Student::removeBook(){
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
    Book* book = &(*(borrowedBooks.begin() + stoi(temp) - 1));
    book->setCheckedOut(false);
    book->setIssuer("");
    borrowedBooks.erase(borrowedBooks.begin() + stoi(temp) - 1);

    cout << "Removed Book" << endl;

    return;
}

void Student::displayBooks(){
    cout << "All the Book Checked Out by the student are" << endl;
    for(auto& book:borrowedBooks){
        book.printBook();
    }
    return;
}

void Student::calculateFineAmount(){
    cout << "Calculating Fine Amount : " << endl;
    cout << "Existing Fine : "<< fineAmount << endl;
    int amount = 0;

    time_t t = time(0);
    tm* currTime = localtime(&t);

    int days = 0;

    for(auto& book : borrowedBooks){
        tm dueDate = book.getDueDate();
        cout << "Inside Borrowed Books " << endl;
        displayDate(&dueDate);
        if(t > mktime(&dueDate)){
            days += diffInDays(currTime, &dueDate);
        }
    }
    cout << "The days are " << days << endl;
    setFineAmount(days*2);
    return;
}


