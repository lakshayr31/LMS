#ifndef USERDB_H
#define USERDB_H

#include <bits/stdc++.h>
#include <string.h>

#include "User.h"

class UserDB{
    private:
        std::vector <User*> userList;
    public:
        void addUser(int check);
        void displayUsers();
        void updateUser();
        void deleteUser();
        User* searchUser();
        User* searchUserByIdAndPassword(std::string givenId, std::string givenPassword);
        
};

#endif