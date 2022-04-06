#include <bits/stdc++.h>
#include <string>

#include "UserDB.h"
#include "User.h"
#include "constants.h"
#include "global.h"
#include "Librarian.h"
#include "Student.h"
#include "Professor.h"
using namespace std;

vector<User*>::iterator findUser(vector<User*>::iterator begin, vector<User*>::iterator end, User* user){
    for(vector<User*>::iterator it = begin; it!=end; it++){
        User* currUser = *it;
        // cout << "1. " << currUser->getId() << endl;
        // cout << "2. " << user->getId() << endl; 
        if(currUser->getId().compare(user->getId()) == 0){
            return it;
        }
    }
    return end;
}

void UserDB::addUser(int check){

    string temp;
    int sel;
    if(check != 1){
        cout << "Adding New User " << endl;
        cout << "Select Type Of New User : " << endl;
        cout << "1.Librarian" << endl;
        cout << "2.Professor" << endl;
        cout << "3.Student" << endl;
        cout << "Select Number : " << endl;
        cin >> sel;
        cin.ignore(100,'\n');
    }
    else{
        sel = 1;
    }

    if(sel == 1){
        if(check == 1){
            while(1){
                Librarian* user = new Librarian();
                user->setType("LIBRARIAN");
                
                
                cout << "Enter New User Name : ";
                getline(cin, temp);
                cout << endl;
                user->setName(temp);

                while(1){
                    cout << "Enter New User ID : ";
                    getline(cin, temp);
                    cout << endl;
                    user->setId(temp);

                    vector<User*>::iterator it;
                    it = findUser(userList.begin(),userList.end(),user);
                    if(it!=userList.end()){
                        cout << "User with this Id already present, try again." << endl;
                    }
                    else{
                        break;
                    }
                }

                cout << "Enter New User Password : ";
                getline(cin, temp);
                cout << endl;
                user->setPassword(temp);

                cout << "Adding the following user : " << endl;
                user->printUser();
                cout << "Confirm (Y/N) : ";
                getline(cin, temp);
                cout << endl;
                if(temp == "Y"){
                    userList.push_back(user);
                    break;
                } 
                else {
                    cout << "Could not add. Please retry." << endl;
                } 
            }
        }
        else {
            Librarian* user = new Librarian();
            user->setType("LIBRARIAN");
            
            
            cout << "Enter New User Name : ";
            getline(cin, temp);
            cout << endl;
            user->setName(temp);

            while(1){
                cout << "Enter New User ID : ";
                getline(cin, temp);
                cout << endl;
                user->setId(temp);

                vector<User*>::iterator it;
                it = findUser(userList.begin(),userList.end(),user);
                if(it!=userList.end()){
                    cout << "User with this Id already present, try again." << endl;
                }
                else{
                    break;
                }
            }
            

            cout << "Enter New User Password : ";
            getline(cin, temp);
            cout << endl;
            user->setPassword(temp);

            cout << "Adding the following user : " << endl;
            user->printUser();
            cout << "Confirm (Y/N) : ";
            getline(cin, temp);
            cout << endl;
            if(temp == "Y"){
                userList.push_back(user);
            } 
            else {
                cout << "Could not add. Please retry." << endl;
            }
        }   
    }
    else if(sel == 2){
        Professor* user = new Professor();
        user->setType("PROFESSOR");
        cout << "Enter New User Name : ";
        getline(cin, temp);
        cout << endl;
        user->setName(temp);

        while(1){
            cout << "Enter New User ID : ";
            getline(cin, temp);
            cout << endl;
            user->setId(temp);

            vector<User*>::iterator it;
            it = findUser(userList.begin(),userList.end(),user);
            if(it!=userList.end()){
                cout << "User with this Id already present, try again." << endl;
            }
            else{
                break;
            }
        }

        cout << "Enter New User Password : ";
        getline(cin, temp);
        cout << endl;
        user->setPassword(temp);

        cout << "Adding the following user : " << endl;
        user->printUser();
        cout << "Confirm (Y/N) : ";
        getline(cin, temp);
        cout << endl;
        if(temp == "Y"){
            userList.push_back(user);
        } 
        else {
            cout << "Could not add. Please retry." << endl;
        }
        
    } else if(sel == 3){
        
        Student* user = new Student();
        user->setType("STUDENT");

        cout << "Enter New User Name : ";
        getline(cin, temp);
        cout << endl;
        user->setName(temp);

        while(1){
            cout << "Enter New User ID : ";
            getline(cin, temp);
            cout << endl;
            user->setId(temp);

            vector<User*>::iterator it;
            it = findUser(userList.begin(),userList.end(),user);
            if(it!=userList.end()){
                cout << "User with this Id already present, try again." << endl;
            }
            else{
                break;
            }
        }

        cout << "Enter New User Password : ";
        getline(cin, temp);
        cout << endl;
        user->setPassword(temp);

        cout << "Adding the following user : " << endl;
        user->printUser();
        cout << "Confirm (Y/N) : ";
        getline(cin, temp);
        cout << endl;
        if(temp == "Y"){
            userList.push_back(user);
        } 
        else {
            cout << "Could not add. Please retry." << endl;
        }
    }
    else {
        cout << "Invalid Number Selected. Please retry.";
    }
    return;
}

void UserDB::displayUsers(){
    for (auto &user : userList){
        user->printUser();
        cout << endl;
    }
}

User* UserDB::searchUser(){

    string temp;
    cout << "Enter User Id : ";
    getline(cin, temp);
    cout << endl;

    vector<User*>::iterator it;
    User* user = new User();
    user->setId(temp);
    it = findUser(userList.begin(),userList.end(),user);
    if(it!=userList.end()){
        User* tempUser = *it;
        tempUser->printUser();
    }
    else{
        cout << "No user with this ID found.";
        return NULL;
    }
    return *it;
}

User* UserDB::searchUserByIdAndPassword(string givenId,string givenPassword){

    vector<User*>::iterator it;
    User* user = new User();
    user->setId(givenId);

    it = findUser(userList.begin(),userList.end(),user);
    User* tempUser;
    if(it!=userList.end()){
        tempUser = *it;
    }
    else{
        cout << "No user with this ID found.";
        return NULL;
    }
    // cout << "Comparision of Passwords " << tempUser->getPassword().compare(givenPassword) << endl;
    if(tempUser->getPassword().compare(givenPassword) != 0){
        // cout << tempUser->getPassword() << endl;
        cout << "Wrong UserName Or Password" << endl;
        return NULL;
    }
    return *it;
}

void UserDB::updateUser(){
    string temp;
    cout << "Updating User" << endl;

    cout << "Enter User ID : ";
    getline(cin, temp);
    cout << endl;
    
    vector<User*>::iterator it;
    User* user = new User();
    user->setId(temp);
    it = findUser(userList.begin(),userList.end(),user);
    if(it!=userList.end()){
        User* tempUser = *it;
        tempUser->printUser();
    }
    else{
        cout << "No user with this ID found.";
        return;
    }
    User* tempUser = *it;

    int toChange = 0;
    cout << "What to change?" << endl;
    cout << "1. Name" << endl;
    cout << "2. ID" << endl;
    cout << "3. Password" << endl;
    cout << "Choose the number ";
    getline(cin,temp);
    
    if(temp == "1"){
        cout << "Enter New Name : ";
        getline(cin, temp);
        cout << endl;
        tempUser->setName(temp);
    }
    else if(temp == "2"){
        cout << "Enter New ID : ";
        getline(cin, temp);
        cout << endl;
        tempUser->setId(temp);
    }
    else if(temp == "3"){
        cout << "Enter New Password : ";
        getline(cin, temp);
        cout << endl;
        tempUser->setPassword(temp);
    }
    else {
        cout << "Invalid Option Selected. Please Try Again." << endl;
    }
    
    cout << "Details of the updated user : ";
    tempUser->printUser();
    
    return;   
}

void UserDB::deleteUser(){

    string temp;
    cout << "Enter User Id : ";
    getline(cin, temp);
    cout << endl;

    vector<User*>::iterator it;
    User* user = new User();
    user->setId(temp);
    it = findUser(userList.begin(),userList.end(),user);
    if(it!=userList.end()){
        User* tempUser = *it;
        tempUser->printUser();
    }
    else{
        cout << "No user with this ID found.";
        return;
    }

    cout << "Do you want to delete this user ? (Y?N)" << endl;
    getline(cin, temp);
    cout << endl;

    if(temp == "Y"){
        userList.erase(it);
        cout << "Deleted" << endl;
    }
    else {
        cout << "Not able to delete the book." << endl;
    }
    return;
}