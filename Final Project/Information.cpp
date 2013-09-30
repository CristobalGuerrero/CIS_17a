#include "information.h"
#include <iostream>
using namespace std;

Information::Information(){
    Intro="\n \nThis program will be used to simulate a vending machine. "
            "\nThe user will be able to either fill the vending machine or get "
            "\nfrom a pre-existing machine that has been filled and has money values "
            "\nto each item.\n \n";
}

void Information::printinformation(){
    cout << Intro;
}
