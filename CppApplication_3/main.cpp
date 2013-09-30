/* 
 * File:   main.cpp
 * Author: Owner
 *
 * Created on May 17, 2010, 2:23 PM
 */

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    string one;
    char temp,temp2;
    int start=0;
    
    
    cout << "Enter a Message: ";
    cin>>one;
    int end=one.length()-1;
    int middle=end/2;
    for(int i=0;i<=one.length()/2;i++)
    {
        temp=one[start];
        one[start]=one[end];
        one[end]=temp;
        start++;
        end--;
    }
    cout<<one<<endl;
    return (EXIT_SUCCESS);
}

