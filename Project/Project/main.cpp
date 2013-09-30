/*
 * File:   Project 1
 * Author: Cristobal Guerrero
 *
 * Created on April 22, 2010, 12:11 PM
 */

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
 *  This program is meant to simulate a vending machine being filled or already filled
 *  The user will be able to put in products into the vending machine and have a setinel
 *  value that will be implemented so that when the user puts in a negative amount
 *  or a product with a negative interger taken in as a string the vending machine will then
 *  be filled and then be able to be tested to see if the machine is in full working order
 */

struct Vending{
    int sarray;
    string response;
    string *machine;
    double *cost;
};

void fvending();                            //This will fill the vending machine
void testvending();                         //This will test if the vending machine was filled correctly
double validateentry(string,double);        //This will validate the users input for currency as a boolean
string *autovendfill(int);                  //This is an auto fill for the vending machine if the user picks to test
void vendprint(string *,double *,int);      //This will print the array with the size and the contents
string *manualfill(int);                    //This is for the manual fill for the users
double *autofillmoney(int);                 //This is for auto fill for the cost
double arraysearch(double*,int);            //This is to search and return the cost of the soda
void vendprintcost(string *,double *,int);  //This prints out cost and the item as well that is currently being purchased
double *manualcostfill(string *,int);       //This is for the manual fill of the vending machine

int main() {

    Vending vend;
    string currency="s";
    double total=0,total2=0,csoda;
    int soda;
    vend.sarray=6;
    vend.response="yes";
    

    cout.setf(ios::fixed);
    cout.precision(2);

    while(vend.response!="no")
    {
    cout << "\nHello owner would you like to test or fill the vending machine? ";
    cin >> vend.response;
        if(vend.response=="Test"||vend.response=="test"||vend.response=="t"||vend.response=="T")
        {

            cout << "\n\nHere is a list of items to choose from "
                    "please punch in \nthe code for whatever you "
                    "want to purchase: \n"<<endl;

            vend.machine=autovendfill(vend.sarray);
            vend.cost=autofillmoney(vend.sarray);
            vendprint(vend.machine,vend.cost,vend.sarray);
            cout<<"What soda would you like: ";
            cin>>soda;
            soda--;
            csoda=arraysearch(vend.cost,soda);
  
            while(total<csoda)
            {
                cout << "\nPlease insert bills or coins until you want to quit inserting: $";
                cin >> currency;
                total+=validateentry(currency,total2);
                total2=0;
                vendprintcost(vend.machine,vend.cost,soda);
                cout <<"Your current total is : $"<<total<<endl
                     <<"Your remaining amount is: $"<<(csoda-total)<<endl;
            }
        cout<<"Your change is: $"<<(total-csoda)<<endl
            <<"Enjoy your soda!!!"<<endl<<"Would you like another soda? ";
        cin>>vend.response;
         if(vend.response!="quit"||vend.response!="no")
          {
              delete []vend.cost;
              delete []vend.machine;
          }
        }

        else if(vend.response=="Fill"||vend.response=="fill"||vend.response=="F"||vend.response=="f")
        {
            cout<<"In this section you can fill the vending machine with drinks\n"
                <<"Please enter how many soda's will be in the machine: ";
            cin>>vend.sarray;

            vend.machine=manualfill(vend.sarray);
            vend.cost=manualcostfill(vend.machine,vend.sarray);
        
            cout<<endl<<"Now to test your vending machine"<<endl;
            cout<<"What soda would you like: ";
            cin>>soda;
            soda--;
            csoda=arraysearch(vend.cost,soda);

            while(total<csoda)
            {
              cout << "\nPlease insert bills or coins until you want to quit inserting: $";
              cin >> currency;
              total+=validateentry(currency,total2);
              total2=0;
              vendprintcost(vend.machine,vend.cost,soda);
              cout <<"Your current total is : $"<<total<<endl
                   <<"Your remaining amount is: $"<<(csoda-total)<<endl;
         }
         cout<<"Your change is: $"<<(total-csoda)<<endl
               <<"Enjoy your soda!!!"<<endl<<"Would you like another soda? ";
         cin>>vend.response;
          if(vend.response!="quit"||vend.response!="no")
          {
              delete []vend.cost;
              delete []vend.machine;
          }

        }
    
        else if(vend.response!="no")
        {
            cout<<"An incorrect input was placed "<<endl;
        }
    }

    
    return 0;
}

double validateentry(string currency,double total)
{

    if(currency=="5.00"||currency=="5"||currency=="5.0"||currency=="five"){
        total+=5;
    }
    else if(currency=="1.00"||currency=="1"||currency=="1.0"||currency=="dollar"){
        total+=1;
    }
    else if(currency==".25"||currency==".250"||currency=="0.25"||currency=="quarter"){
        total+=.25;
    }
    else if(currency==".1"||currency==".10"||currency=="0.1"||currency=="dime"){
        total+=.1;
    }
    else if(currency==".05"||currency==".050"||currency=="0.05"||currency=="nickel"){
        total+=.05;
    }
    else{
        cout << "You put in an invalid coin or bill please try again"<<endl;
    }
    return total;

}


string *autovendfill(int size)
{
    string *vend=new string[size];
    vend[0]="Coca-Cola";
    vend[1]="Diet Coke";
    vend[2]="Sprite";
    vend[3]="Doctor Pepper";
    vend[4]="Root Beer";
    vend[5]="Fanta";
    return vend;
}

double *autofillmoney(int size)
{
    double *cost=new double[size];
    cost[0]=1.50;
    cost[1]=1.25;
    cost[2]=1.00;
    cost[3]=2.00;
    cost[4]=2.25;
    cost[5]=1.75;
    return cost;
}

string *manualfill(int size)
{

    string *vend=new string[size];
    for(int i=0;i<size;i++){
        cout<<"Enter in a name of a soda: ";
        cin>>vend[i];
        for(int j=0;j<=i;j++){
            cout<<"Item "<<(j+1)<<": "<<vend[j]<<endl;
        }
    }
    return vend;
}

double *manualcostfill(string *a,int sarray)
{    
    double *cost=new double[sarray];
    for(int i=0;i<sarray;i++){
        cout<<"Enter in price for "<<a[i]<<": $";
        cin>>cost[i];
        for(int j=0;j<=i;j++){
            cout<<a[j]<<": "<<cost[j]<<endl;
        }
    }
    return cost;
    
}

double arraysearch(double *cost,int soda)
{
    double csoda=cost[soda];
    return csoda;
}

void vendprint(string *a,double *b,int sarray)
{
    for(int i=0;i<sarray;i++){
        cout << "Item "<<(i+1)<<":   $"<<b[i]<<"   "<<a[i]<<endl;
    }
}

void vendprintcost(string *a,double *b,int sarray)
{
        cout <<"$"<<b[sarray]<<"   "<<a[sarray]<<endl;
}