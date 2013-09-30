/* 
 * File:   main.cpp
 * Author: Cristobal Guerrero
 *
 * Created on March 11, 2010, 2:27 PM
 */

#include <stdlib.h>
#include <cstdlib>
#include <iostream.h>
using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {

    float loan,temp,rate,payments,monthly,amount,interest;
    temp =1; //based off of yearly interest
    rate =.01;
    cout << "Loan Amount:           $  ";
    cin >> loan;
    cout << "Monthly Interest rate:    " << temp << "%" << endl;
    cout << "Number of Payments:    $  ";
    cin >> payments;
    //takes it to the power of N use of (1+rate)^n
    for(int i=0;i<payments;i++){temp *= (1+rate);}

    monthly = ((rate*temp)/(temp-1))*loan;
    amount = monthly*payments;
    interest = amount-loan;

    cout << "Monthly Payment:       $  " << monthly << endl
         << "Amount Paid Back:      $  " << amount << endl
         << "Interest Paid:         $  " << interest << endl << endl;

    return (EXIT_SUCCESS);
}

