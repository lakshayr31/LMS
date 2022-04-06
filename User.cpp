#include "User.h"
#include "global.h"
#include"constants.h"
#include <bits/stdc++.h>
#include "ctime"

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

void User::setType(string t){
    type = t;
}

void User::printUser(){
    cout << "Name : " << name << endl;
    cout << "ID : " << id << endl;
    cout << "Type : " << type << endl;
}

string User::getName(){
    return name;
}
string User::getId(){
    return id;
}
string User::getPassword(){
    return password;
}
string User::getType(){
    return type;
}

bool User::operator== (const User &secondUser){
    return this->id == secondUser.id;
}
