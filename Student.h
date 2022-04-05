#ifndef STUDENT_H
#define STUDENT_H

#include <bits/stdc++.h>

#include "User.h"
#include "Book.h"

class Student : public User {
    private :
        int fineAmount;
        int numOfBooks;
        std::vector<Book> borrowedBooks;
    public :
        void setFineAmount(int amount);
        void setNumOfBooks(int count);
        int getFineAmount();
        int getNumOfBooks();
        void addBook();
        void removeBook();
        void displayBooks();
        void calculateFineAmount();
};
#endif