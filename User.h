#ifndef USER_H
#define USER_H
#include <bits/stdc++.h>


class User {
    private :
        std::string name;
        std::string password;
        std::string type;
    public :
        std::string id;

        void setName(std::string name);
        void setPassword(std::string password);
        void setId(std::string Id);
        void setType(std::string t);
        void printUser();
        
        std::string getName();
        std::string getId();
        std::string getType();
        std::string getPassword();
        bool operator== (const User &secondUser);
};
#endif