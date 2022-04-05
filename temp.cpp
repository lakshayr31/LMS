#include <bits/stdc++.h>
#include "ctime"

using namespace std;
int main(){
    time_t t = time(0);
    tm* currTime = localtime(&t);
    cout << currTime->tm_mday <<  ":" <<  currTime->tm_mon + 1<<":" << currTime->tm_year + 1900 << endl;
    t += 30*24*60*60;
    currTime = localtime(&t);
    cout << currTime->tm_mday <<  ":" <<  currTime->tm_mon + 1<<":" << currTime->tm_year + 1900 << endl;

}