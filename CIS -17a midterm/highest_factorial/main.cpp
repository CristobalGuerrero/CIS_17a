/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on April 7, 2010, 10:28 AM
 */
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    int num=1;
    float num2=1;
    double num3=1;
    short num4=1;
    long num5=1;
    int n,i,f,d,s,l;

    //for the normal ints
    for(n=1;n<=20;n++){
            num*=n;
            if(num<=0){
                i=n-1;
                n=20;}}
        cout << "factorial for int: "<<i<<endl;

    //for the floats
    for(n=1;n<=50;n++){
        num2*=n;
         if(num2<=0){
                f=n-1;
                n=50;}
        else if(n==50){f=n;}}
        cout << "factorial for float: "<<f<<endl;

     //for the doubles
     for(n=1;n<=100;n++){
        num3*=n;
        if(num3<=0){
                d=n-1;
                n=100;}
        else if(n==100){d=n;}}
        cout << "factorial for double: "<<d<<endl;

      //for the short ints
      for(n=1;n<=20;n++){
        num4*=n;
         if(num4<=0){
                s=n-1;
                n=20;}}
        cout << "factorial for short int: "<<s<<endl;

       //for the long ints
       for(n=1;n<=20;n++){
        num5*=n;
         if(num5<=0){
                l=n-1;
                n=20;}}
        cout << "factorial for long int: "<<l<<endl
             << "Doubles are the data type that can hold the highest value"<<endl;

    return (EXIT_SUCCESS);
}

