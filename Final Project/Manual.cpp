/* 
 * File:   Manual.cpp
 * Author: Owner
 * 
 * Created on June 4, 2010, 2:36 PM
 */

#include "Manual.h"
#include <iostream>
using namespace std;

Manual::Manual() {
}

Manual::Manual(const Manual& orig) {
    manualsize=0;
}

//Sets the size for the array
void Manual::setsize(int size){
    manualsize = size;
}

//sets the index
void Manual::setindex(int choice){
    index = choice;
}

//Prints everything that is in the current built array
void Manual::printarray(int size){
    cout.setf(ios::fixed);
    cout.precision(2);
    manualmachine=new string[size];
    manualcost=new double[size];
    cout<<"This is the array size: "<<manualsize<<endl;
    manualmachine=manualsoda();
    manualcost=manualmoney();

    cout<<"Here is the machine that you have filled and created: \n";
    for(int i=0;i<manualsize;i++){
        cout<<"$"<<manualcost[i]<<"  "<<manualmachine[i]<<endl;
    }
}

double Manual::getmoney(){
    return manualcost[index-1];
}

void Manual::vendprintcost(){
     cout<<"The total for the "<<manualmachine[index-1]
            <<" chosen is: $"<<getmoney()<<endl;
}

//This fills the vending machine with money
string * Manual::manualsoda(){

        getline(cin,manualmachine[0]);
    for(int i=0;i<manualsize;i++){
        cout<<"Enter in a name of a soda: ";
        getline(cin,manualmachine[i]);
    }
    return manualmachine;
}

string  Manual::getsoda(){
    return manualmachine[index-1];
}

//This will be the manual fill for the 
double * Manual::manualmoney(){
    
    for(int i=0;i<manualsize;i++){
        cout<<"Enter in price for "<<manualmachine[i]<<": $";
        cin>>manualcost[i];
    }
    return manualcost;
}

//Sets the money in the certain index
void Manual::setmoney(){
    manualcost[index-1];
}

//Sets the beverage name in the index
void Manual::setsoda(){
    manualmachine[index-1];
}

Manual::~Manual() {
    //delete manualcost;
    //delete manualmachine;
    manualsize = 0;
}

