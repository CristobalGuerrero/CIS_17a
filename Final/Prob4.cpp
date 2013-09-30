/* 
 * File:   Prob4.cpp
 * Author: Owner
 * 
 * Created on June 11, 2010, 7:47 PM
 */

#include "Prob4.h"
#include <iostream>
using namespace std;

Prob4::Prob4(float balance){
    if(balance>0){Balance = balance;}
    else if(balance==0){Balance=0;}
    FreqWithDraw = 0;
    FreqDeposit = 0;
}   

void  Prob4::Transaction(float trans){
    if(trans>0){FreqDeposit++;Balance+=trans;}
    else if(trans==0){Balance = Balance;}
    else{
        if(Balance>trans){
            FreqWithDraw++;
            Balance-=trans;
        }
        else{
            cout<<"You cannot withdraw that much it exceeds your current balance!\n";
        }
    }
}

float Prob4::Total(float savint,int time){
    float total=Balance;
    float total2=(1+savint);
    for(int i=1;i<time;i++){
        total2*=(1+savint);

    }
    total*=total2;
    return total;
}

float Prob4::TotalRecursive(float savint,int time){
    float total=Balance;
    float total2=(1+savint);
    for(int i=1;i<time;i++){
        total2*=(1+savint);
        
    }
    total*=total2;
    return total;
}

void  Prob4::toString(){
    
    cout<<"Your current balance is: $"<<Balance
        <<"\nYou have "<<FreqWithDraw<<" withdraws.\n"
        <<"You have "<<FreqDeposit<<" deposits.\n";
}

Prob4::~Prob4(){
    Balance = 0;
    FreqWithDraw = 0;
    FreqDeposit = 0;
}

