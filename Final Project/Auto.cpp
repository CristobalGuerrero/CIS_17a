/* 
 * File:   Auto.cpp
 * Author: Owner
 * 
 * Created on June 3, 2010, 11:28 PM
 */

#include "Auto.h"
#include <iostream>
#include <iomanip>
using namespace std;

////////////////////////////////////////////////////
////            Constructor                    /////
////////////////////////////////////////////////////
Auto::Auto(){
    autosize=6;
    automachine=new string[autosize];
    autocost=new double[autosize];
}

//Size reset just in case there is a need to
//reset the size more then likely will be implemented
void Auto::setsize(int size){
    autosize = size;
}

//Sets the index that will be used for the returns for the money and and name
//of the beverage
void Auto::setindex(int choice){
    index = choice;
}

//Retrieves the size for the array that is auto filled this will
//be implimented to tell what the size of the array is or what is the
//size in the vending machine
int Auto::getsize(){
    return autosize;
}

//Retrieves the cost for the item in the array and then will be used to calculate
//the remaining cost by looping
double Auto::getmoney(){
    return autocost[index-1];
}

//This retrieves the auto filled machine for the soda names
//This will be used to set the array in the main.cpp file
string * Auto::machinefilled(){
    automachine[0]="Coca-Cola";
    automachine[1]="Diet Coke";
    automachine[2]="Sprite";
    automachine[3]="Doctor Pepper";
    automachine[4]="Root Beer";
    automachine[5]="Fanta";
  return automachine;
}

double * Auto::moneyfilled(){
    autocost[0]=1.50;
    autocost[1]=1.25;
    autocost[2]=1.00;
    autocost[3]=2.00;
    autocost[4]=2.25;
    autocost[5]=1.75;
    return autocost;
}

//Sets the money in the certain index
void Auto::setmoney(){
    autocost[index-1];
}

//Sets the beverage name in the index
void Auto::setsoda(){
    automachine[index-1];
}

//Gets the soda in the given index
string Auto::getsoda(){
    return automachine[index-1];
}

//Prints everything that is in the current built array
void Auto::printarray(){
    cout.setf(ios::fixed);
    cout.precision(2);
    automachine=machinefilled();
    autocost=moneyfilled();
    for(int i=0;i<autosize;i++){
        cout<<"$"<<autocost[i]<<"  "<<automachine[i]<<endl;
    }
}

void Auto::vendprintcost(){
     cout<<"The total for the "<<getsoda()
            <<" chosen is: $"<<getmoney()<<endl;
}
////////////////////////////////////////////////
/////           Destructor                 /////
////////////////////////////////////////////////
Auto::~Auto(){
    delete automachine;
    delete autocost;
    autosize=0;
}