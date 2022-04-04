#include "Student.h"

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

// void Student::addBook();
// void Student::removeBook();
// void Student::displayBooks();