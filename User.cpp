#include "User.h"

using namespace std;

void User::setName(string givenName){
    name = givenName;
}
void User::setPassword(string givenPassword){
    password = givenPassword;
}
void User::setId(string Id){
    id = Id;
}

string User::getName(){
    return name;
}
string User::getId(){
    return id;
}

