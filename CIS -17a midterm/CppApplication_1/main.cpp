/* 
 * File:   main.cpp
 * Author: Owner
 *
 * Created on April 20, 2010, 1:51 PM
 */
#include <iostream>
#include <stdlib.h>
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    int i=0,counter=0,size;
    
    char n;
    cout<<"Size: ";
    cin>>size;
    int array[size];
    while(array[counter]>=0)
    {
        if(array[counter]>=0){
        cout << "Enter number: ";
        cin>>i;}
        if(i<0)
        {
            cout<<"You put in an invalid number quit?: ";
            cin>>n;
            if(n=='q')
            {
                array[counter]=-1;
                counter--;
            }
            else if(n=='n')
            {
                i=0;
                counter--;
            }
        }
        else if(i>=0){
            array[counter]=i;
            counter++;
        }
        
    }
    for(int j=0;j<counter;j++){
        cout<<array[j]<<endl;
    }
    cout << counter<<endl;
    return (EXIT_SUCCESS);
}

