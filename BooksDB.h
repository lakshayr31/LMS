#ifndef BOOKSDB_H
#define BOOKSDB_H

#include <bits/stdc++.h>
#include <string.h>
#include "Book.h"


class BooksDB {
    private:
        std:: vector <Book> bookList;
    public:
        void addBook();
        void displayBooks();
        void updateBook();
        void deleteBook();
        Book* searchBook();
};

#endif