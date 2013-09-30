/* 
 * File:   Validate.cpp
 * Author: Owner
 * 
 * Created on June 5, 2010, 8:13 PM
 */

#include "Validate.h"
#include <sstream>
#include <iostream>
using namespace std;

Validate::Validate() {
}

Validate::Validate(const Validate& orig) {
}

string Validate::Moneyquestion(double total){
    if(total==0){
    cout<<"Please enter a value such as a dollar/1.00/nickel/.05/etc...\n"
        <<"Please Insert a coin or bill: ";
    cin>>value;
    }
    else if(total != 0){
        cout<<"Please Insert a coin or bill: ";
        cin>>value;
    }
    return value;
}

double Validate::Moneyverify(double total){
    int sentinel = 0;
    while(sentinel!=-1)
    {
    verify = Moneyquestion(total);
     if(verify=="5.00"||verify=="5"||verify=="5.0"||verify=="five"){
        total+=5;
        sentinel = -1;
    }
    else if(verify=="1.00"||verify=="1"||verify=="1.0"||verify=="dollar"){
        total+=1;
        sentinel = -1;
    }
    else if(verify==".25"||verify==".250"||verify=="0.25"||verify=="quarter"){
        total+=.25;
        sentinel = -1;
    }
    else if(verify==".1"||verify==".10"||verify=="0.1"||verify=="dime"){
        total+=.1;
        sentinel = -1;
    }
    else if(verify==".05"||verify==".050"||verify=="0.05"||verify=="nickel"){
        total+=.05;
        sentinel = -1;
    }
    else if(verify==".01"||verify==".010"||verify=="0.01"||verify=="penny"){
        total+=.01;
        sentinel = -1;
    }
    else{
        cout << "You put in an invalid coin or bill please try again"<<endl;
        sentinel = 0;
    }
    }
    return total;

}

void Validate::Automanualset(string choice){
    decision = choice;
}

string Validate::Automanual(string choice){
    Automanualset(choice);
    if(decision=="auto" || decision=="Auto" || decision=="1"){
        return "Auto";
    }
    else if(decision=="Manual" || decision=="manual"
            || decision=="2" || decision=="fill" || decision=="Fill"){
        return "Manual";
    }
    else{
        cout<<"You entered in something invalid.\n";
        return "false";
    }
}

int Validate::Sodachoice(string soda){
    if(soda=="1"){
        return 1;
    }
    else if(soda=="2"){
        return 2;
    }
    else if(soda=="3"){
        return 3;
    }
    else if(soda=="4"){
        return 4;
    }
    else if(soda=="5"){
        return 5;
    }
    else if(soda=="6"){
        return 6;
    }
    else if(soda=="7"){
        return 7;
    }
    else{
        cout<<"This is not a valid soda. Please enter a real soda."
                <<endl;
        return -1;
    }
}

Validate::~Validate() {
}

