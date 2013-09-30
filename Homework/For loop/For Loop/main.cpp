/* 
 * File:   main.cpp
 * Author: Cristobal Guerrero
 *
 * Created on March 11, 2010, 2:58 PM
 */

#include <stdlib.h>
#include <iostream>
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    //wrtie a for loop that displays every fifth
    for(int i=0;i<=100;i++){
        if(((i%5) == 0)){cout << i << "  ";}
        if(((i%50) == 0)){cout << endl;}}
    //number starting at zero through 100
    return (EXIT_SUCCESS);
}

