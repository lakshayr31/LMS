# Library Management System - CS253A C++ Assignment
## Lakshay Rastogi 180378

### Usage 
#### Compilation
```
g++ Book.cpp BooksDB.cpp Professor.cpp Student.cpp User.cpp UserDB.cpp Librarian.cpp main.cpp -o main
```

#### Running 
```
./main
```

#### Important Information

- First prompt asks the user to enter the details (name, userId and Password) for a librarian. Using which the user can then interact with the system. This is important because every time the program is run there is a new database that is initialized.

- Every book is uniquely identified by it's ISBN number. So to search/add/delete/update books, we need to know the ISBN number of the book.

- Every user is identified by it's userId. So to search/add/delete/update user information, we need to know the userId of the User.

