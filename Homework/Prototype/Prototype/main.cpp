/* 
 * File:   main.cpp
 * Author: Cristobal Guerrero
 *
 * Created on March 11, 2010, 3:00 PM
 */

#include <stdlib.h>
#include <iostream>
using namespace std;
/*
 * 
 */
int timesTen(int);

int main(int argc, char** argv) {
    //write a prototype for the timesTen function
    //function passes in an integer perameter named number
    int n=10,c;
    c=timesTen(n);
    cout << c << endl;
    return (EXIT_SUCCESS);
}

int timesTen(int number){
    int b=number;
    for(int i=1;i<10;i++){number += b;}
    return number;
}