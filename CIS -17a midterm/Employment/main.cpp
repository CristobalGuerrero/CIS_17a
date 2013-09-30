/* 
 * File:   main.cpp
 * Author: Owner
 *
 * Created on April 11, 2010, 10:17 AM
 */

#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;
struct Payroll{
   string ename;
   double hours;
   double pay;
   string *array;
   double *payarray;
   int sz;
};
double normpay(double,double);
double xpay(double,double);
double txpay(double,double);
void printarrays(string,double);
/*
 * 
 */
int main(int argc, char** argv) {
    Payroll check;
    int i = 0;
    double hour=0,pays=0;
    check.sz=50;
    check.array=new string[check.sz];

    while(hour>=0||pays>=0){
        cout<< "Employee's name: ";
        cin >> check.array[i];
        cout<< "Hours worked: ";
        cin >> hour;
        check.hours=hour;
        cout<<"Workers pay: ";
        cin >> pays;
        check.pay=pays;

        if(check.hours<=20){
            check.pay=normpay(check.pay,check.hours);
        }
        else if(check.hours>20&&check.hours<=40){
            check.pay=xpay(check.pay,check.hours);
        }
        else{
            check.pay=txpay(check.pay,check.hours);
        }
        check.payarray[i]=check.pay;
        i++;
    }
    for(int n=0;n<i;n++){   
        cout << check.array[n] << " made a total of: " <<check.payarray[n]<<endl;
    }
    delete []check.payarray;
    delete []check.array;
    return (EXIT_SUCCESS);
}

double normpay(double a,double b){
    return a*b;
}

double xpay(double pay,double hours){
     double pay2=pay*2;
            pay*=20;
            hours-=20;
            pay2*=hours;
     return pay+=pay2;
}

double txpay(double pay,double hours){
     double pay2=pay*2;
     double pay3=pay*3;
            pay*=20;
            pay2*=20;
            hours-=40;
            pay3*=hours;
    return (pay+pay2+pay3);
}

