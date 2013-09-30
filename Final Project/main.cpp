/* 
 * File:   main.cpp
 * Author: Owner
 *
 * Created on June 3, 2010, 10:58 PM
 */

#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include "Auto.h"
#include "information.h"
#include "Manual.h"
#include "Validate.h"
using namespace std;
/*
 * 
 */

int main() {
    Auto test;
    Manual tester;
    Information inform;
    Validate verify;
    //Decision desc;
    string choice="false",soda;
    int autosize = 6, manualsize, index;
    double money=0,vend=0,total=0,total2=0;
    inform.printinformation();

    while(choice == "false")
    {
        cout<<"Hello user would you like to test or do a manual fill for the machine \n"
                "Please enter a choice: ";
        cin>>choice;
        choice = verify.Automanual(choice);
    }

    //Minor separation between lines of the paragraphs shown
    cout<<"\n \n \n";

    while(choice=="Auto")
    {
    if(choice == "Auto")
    {
        //This get will retrieve the size of the filled array
        cout<<"There are "<<test.getsize()<<" items in the machine already \n"
            <<"The items are as listed with prices: \n";
        //Prints the already filled array in the file
        test.printarray();
        cout<<endl<<endl<<"Which Soda would you like please enter a number \n1-6: ";
        cin>>choice;
        //verifys using a string to see if the correct index was chosen
        index = verify.Sodachoice(choice);
        test.setindex(index);
        total = test.getmoney();
        test.vendprintcost();
        cout<<endl<<endl;
        while(money<total)
        {
        //ask the user for their input for money
        money = verify.Moneyverify(money);
        test.vendprintcost();
        if((total-money)>0)
        {
        cout<<"Your remaining total is: $"<<(total-money)
            <<"\n \n";
        }
        }
        cout<<"Your change is: $"<<(money-total)<<endl<<endl;
        choice = test.getsoda();
        cout<<"Enjoy your "<<choice
            <<" would you like another soda? ";
        cin>>choice;
        cout<<endl<<endl<<endl;

        //Checks if the user wants another soda
        if(choice=="quit"||choice=="Quit"||choice=="exit"
           ||choice=="Exit"||choice=="-1"||choice=="no"||choice=="No")
        {
            return 0;//ends the program
        }
        else if(choice=="another"||choice=="Another"||choice=="Yes"
                ||choice=="yes"||choice=="1")
        {
            money=0;//resets all the values
            total=0;
            choice="Auto";
        }
    }
    }

     while(choice=="Manual")
    {
    if(choice == "Manual")
    {
        //This is where the user will set the size of the array
        cout<<"This is where we will set the amount of products in the machine\n "
                "How many items would you like to place in the machine. \n"
                "The limit is 7 items: ";
        cin>>autosize;
        tester.setsize(autosize);
        tester.printarray(autosize);
        cout<<endl<<endl<<"Which Soda would you like\n please "
                "enter a number 1-"<<autosize<<": ";
        cin>>choice;
        //verifys using a string to see if the correct index was chosen
        index = verify.Sodachoice(choice);
        tester.setindex(index);
        total = tester.getmoney();
        tester.vendprintcost();
         cout<<endl<<endl;
        while(money<total)
        {
        //ask the user for their input for money
        money = verify.Moneyverify(money);
        tester.vendprintcost();
        if((total-money)>0)
        {
        cout<<"Your remaining total is: $"<<(total-money)
            <<"\n \n";
        }
        }
        cout<<"Your change is: $"<<(money-total)<<endl<<endl;
        choice=tester.getsoda();
        cout<<"Enjoy your "<<choice
            <<" would you like another soda? ";
        cin>>choice;
        cout<<endl<<endl<<endl;

        //Checks if the user wants another soda
        if(choice=="quit"||choice=="Quit"||choice=="exit"
           ||choice=="Exit"||choice=="-1"||choice=="no"||choice=="No")
        {
            return 0;//ends the program
        }
        else if(choice=="another"||choice=="Another"||choice=="Yes"
                ||choice=="yes"||choice=="1")
        {
            money=0;//resets all the values
            total=0;
            choice="Manual";
        }
    }
     }
    return 0;
}


