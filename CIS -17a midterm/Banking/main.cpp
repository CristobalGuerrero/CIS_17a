/* 
 * File:   main.cpp
 * Author: Owner
 *
 * Created on April 11, 2010, 11:04 PM
 */

#include <stdlib.h>
#include <iostream>
#include <boost/regex.hpp>
using namespace std;
using namespace boost;

struct Banking{
    double balance;
    double deposit;
    double withdraw;
    int account;
    char question;
};
/*
 * 
 */
int main(int argc, char** argv) {
    //check for 5 digit pin if its greater then 0 then there is an error
    //int random=654321;
    //random/=100000;
    Banking Banking;
    int valid;
    double temp;
    Banking.deposit=0;
    Banking.withdraw=0;
    int counter=1;
    Banking.balance=100;

    cout << "Input your 5 digit account number: ";
    cin >> Banking.account;
    regex valid(^\(Banking.account)*[0-9]{5}\(Banking.account)*$);
    sregex_token_iterator my_iter((Banking.account),valid);

    if(my_iter==0){
    //Checks to see the correct input for the banking account
    while(counter<2){
        cout << "Your account number input is too large try again: ";
        cin >> Banking.account;
        if(my_iter==0){
            counter++;
        }
        else if(my_iter>=1){
            counter=2;
        }
    }}

    if(my_iter>=1){
    //Accounting for all the deposits made
    cout<<"Do you have any deposits to be made? ";
    cin>>Banking.question;
    if(Banking.question=='y'||Banking.question=='Y'){
        temp=1;
        counter=1;
    while(temp>=0){
        Banking.deposit+=temp;
        cout << "Deposit #"<<counter<<": ";
        cin >> temp;
        counter++;
    }}
    
    //Accounting for all the checks written
    cout<<"Do you have any checks made? ";
    cin >> Banking.question;
    if(Banking.question=='y'||Banking.question=='Y'){
        temp=0;
        counter=1;
    while(temp>=0){
        Banking.withdraw+=temp;
        cout << "Written Check #"<<counter<<": ";
        cin >> temp;
        counter++;
    }}
    
    Banking.balance+=Banking.deposit-Banking.withdraw;
    if(Banking.balance<0){
        cout<<"An additional $12.00 will be removed from your account due to an overdrawl"<<endl;
        Banking.balance-=12.00;
    }
    cout<<"Your Bank account number is: "<<Banking.account<<endl
        <<"Your Current Balance is: $"<<Banking.balance<<endl
        <<"Have a nice day!";
    }
    else{
        cout << "There are too many input errors try again later."<<endl;
    }
   
    
    return (EXIT_SUCCESS);
}

