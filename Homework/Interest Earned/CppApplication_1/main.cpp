/* 
 * File:   main.cpp
 * Author: Cristobal Guerrero
 *
 * Created on March 11, 2010, 1:14 PM
 */
#include <stdlib.h>
#include <iomanip.h>
#include <cstdlib>
#include <iostream.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
    float compound,princi,rate,interest,amounts,comprate;
    
    cout << "Interest Rate:         ";
    cin >> rate;
    rate /= 100;
    cout << "Times Compounded:      ";
    cin >> compound;
    cout << "Principal:          $  ";
    cin >> princi;
    
    comprate = (1+(rate/compound));
    float newcomprate = comprate;
    for(int i=0;i<compound-1;i++){newcomprate *= comprate;}
    amounts = princi*(newcomprate);
    interest = amounts-princi;
    cout << "Interest:           $  " << interest << endl;
    cout << "Amount in Savings:  $  " << amounts << endl;

   

    return (EXIT_SUCCESS);
}



