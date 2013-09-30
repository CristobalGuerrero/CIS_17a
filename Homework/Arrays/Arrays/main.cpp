/* 
 * File:   main.cpp
 * Author: Cristobal Guerrero
 *
 * Created on March 11, 2010, 3:02 PM
 */

#include <stdlib.h>
#include <iostream>
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
   //what is the following output of the program
    int value[5], count;
    for(count=0;count<5;count++)
        value[count]=count+1;
    for(count=0;count<5;count++)
        cout<<value[count]<<endl;
    //1,2,3,4,5 is displayed on each individual line
    return (EXIT_SUCCESS);
}

