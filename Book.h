#ifndef BOOK_H
#define BOOK_H

#include <bits/stdc++.h>
#include "ctime"

class Book {
    private:
        std::string title;
        std::string author;
        std::string publication; 
        std::tm dueDate;
        bool checkedOut;
        std::string issuer;
    
    public:

        std::string isbn;

        std::string getTitle();
        std::string getAuthor();
        std::string getISBN();
        std::string getPublication();
        std::tm getDueDate();
        bool getCheckedOut();
        std::string getIssuer();

        void setTitle(std::string title);
        void setAuthor(std::string author);
        void setISBN(std::string isbn);
        void setPublication(std::string publication);
        void setDueDate(std::string issuer);
        void setCheckedOut(bool checkOut);
        void setIssuer(std::string issuer);
        void showDueDate();
        void printBook();
        bool operator== (const Book &secondBook);
}; 

#endif