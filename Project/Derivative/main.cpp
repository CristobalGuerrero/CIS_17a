/* 
 * File:   main.cpp
 * Author: Cristobal Guerrero
 *
 * Created on March 31, 2010, 1:12 PM
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
const int ZERO = 0;
/*
 * 
 */
int main() {

    int a,b,c,power,power2,power3;
    char variable;

    cout<<"Enter your variable: ";
    cin>>variable;
    cout << "Enter your a: ";
    cin>>a;
    cout<<"Enter your power: ";
    cin>>power;
    cout<< "Enter your b: ";
    cin>>b;
    cout<<"Enter your power: ";
    cin>>power2;
    cout<< "Enter your c: ";
    cin>>c;
    cout<<"Enter your power: ";
    cin>>power3;

    if(a>ZERO&&b>ZERO&&c>ZERO){
        cout<<endl<<"Your equation is: "
        <<a<<variable<<"^"<<power<<"+"
        <<b<<variable<<"^"<<power2<<"+"
        <<c<<variable<<"^"<<power3<<endl<<endl;}
    else if(a>ZERO&&b>ZERO&&c<ZERO){
        cout<<endl<<"Your equation is: "
        <<a<<variable<<"^"<<power<<"+"
        <<b<<variable<<"^"<<power2
        <<c<<variable<<"^"<<power3<<endl<<endl;}
     else if(a>ZERO&&b<ZERO&&c<ZERO){
        cout<<endl<<"Your equation is: "
        <<a<<variable<<"^"<<power
        <<b<<variable<<"^"<<power2
        <<c<<variable<<"^"<<power3<<endl<<endl;}
    







    return (0);
}

