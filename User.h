#ifndef USER_H
#define USER_H
#include <bits/stdc++.h>

class User {
    private :
        std::string name;
        std::string password;
    public :
        std::string id;

        void setName(std::string name);
        void setPassword(std::string password);
        void setId(std::string Id);

        std::string getName();
        std::string getId();
};
#endif