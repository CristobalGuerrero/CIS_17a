/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on April 5, 2010, 1:04 PM
 */
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
        int months=12,first_month,second_month,a[months],jan=31,
            feb=28,mar=31,apr=30,may=31,
            june=30,july=31,aug=31,sep=30,
            oct=31,nov=30,dec=31,year,year2,date;
   //population of all the months of the year loop could be done though
   //this seems like the easiest alternative
    a[0]=jan;
    a[1]=feb;
    a[2]=mar;
    a[3]=apr;
    a[4]=may;
    a[5]=june;
    a[6]=july;
    a[7]=aug;
    a[8]=sep;
    a[9]=oct;
    a[10]=nov;
    a[11]=dec;
    
    //Get the users years to compare
    cout<<"What year is it: ";
    cin >> year;
    cout <<"What month is it(1-12): ";
    cin >> first_month;
    cout << "Second year: ";
    cin >> year2;
    cout <<"What month is it(1-12): ";
    cin>>second_month;

   
    for(int i = 0;i<months;i++){
        cout<<a[i]<<endl;
        a[i+1]=a[i]+a[i+1];
        if((year%4)==0||(year%400)==0||(year%100)!=0){
            a[1]+=1;
        }
    }



    return (EXIT_SUCCESS);
}

