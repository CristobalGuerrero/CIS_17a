/* 
 * File:   main.cpp
 * Author: Cristobal Guerrero
 *
 * Created on March 11, 2010, 2:56 PM
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Write an if statement tht assigns a .20 to
    //commisiion when sales is greater then or equal to 10k
    float commision;
    int pay=10000;
    for(int i=0;i<30000;i+=100)
    if((i%pay)==0){commision += .2;}
    cout << commision << endl;
    return (EXIT_SUCCESS);
}

