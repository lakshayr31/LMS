#include "BooksDB.h"
#include "ctime"
#include "UserDB.h"

extern BooksDB booksDB;
extern UserDB usersDB;

extern void displayDate(tm* date);
extern int diffDays(tm* date1 , tm* date2);