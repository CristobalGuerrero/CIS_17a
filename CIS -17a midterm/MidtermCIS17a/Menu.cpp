//Mark E. Lehr
//April 5th, 2010
//Example Menu to be used for the midterm,
//final, and homework

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Banking{
    double balance;
    double deposit;
    double withdraw;
    int account;
    char question;
};



void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();


    int main(int argv,char *argc[])
    {
	int inN;
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;
          default:   def(inN);}
        }while(inN<8);
        return 1;
    }

    void Menu()
    {
           cout<<"Type 1 for problem 1"<<endl;
           cout<<"Type 2 for problem 2"<<endl;
           cout<<"Type 3 for problem 3"<<endl;
           cout<<"Type 4 for problem 4"<<endl;
           cout<<"Type 5 for problem 5"<<endl;
           cout<<"Type 6 for problem 6"<<endl;
           cout<<"Type 7 for problem 7"<<endl;
           cout<<"Type 8 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
		   cin>>inN;
           return inN;
    }
    void problem1()
    {
           cout<<"In problem # 1"<<endl<<endl;
           Banking Banking;
    double temp;
    Banking.deposit=0;
    Banking.withdraw=0;
    int counter=1;
    Banking.balance=100;

    cout << "Input your 5 digit account number: ";
    cin >> Banking.account;

    if((Banking.account/100000)>0){
    //Checks to see the correct input for the banking account
    while(counter<2){
        cout << "Your account number input is too large try again: ";
        cin >> Banking.account;
        if((Banking.account/100000)>0){
            counter++;
        }
        else if((Banking.account/100000)==0){
            counter=2;
        }
    }}

    if((Banking.account/100000)==0){
    //Accounting for all the deposits made
    cout<<"Do you have any deposits to be made? ";
    cin>>Banking.question;
    if(Banking.question=='y'||Banking.question=='Y'){
        temp=1;
        counter=1;
    while(temp>=0){
        Banking.deposit+=temp;
        cout << "Deposit #"<<counter<<": ";
        cin >> temp;
        counter++;
    }}

    //Accounting for all the checks written
    cout<<"Do you have any checks made? ";
    cin >> Banking.question;
    if(Banking.question=='y'||Banking.question=='Y'){
        temp=0;
        counter=1;
    while(temp>=0){
        Banking.withdraw+=temp;
        cout << "Written Check #"<<counter<<": ";
        cin >> temp;
        counter++;
    }}

    Banking.balance+=Banking.deposit-Banking.withdraw;
    if(Banking.balance<0){
        cout<<"An additional $12.00 will be removed from your account due to an overdrawl"<<endl;
        Banking.balance-=12.00;
    }
    cout<<"Your Bank account number is: "<<Banking.account<<endl
        <<"Your Current Balance is: $"<<Banking.balance<<endl
        <<"Have a nice day!";
    }
    else{
        cout << "There are too many input errors try again later."<<endl;
    }}
    
    void problem2()
    {
           cout<<"In problem # 2"<<endl<<endl;
    }
    void problem3()
    {
           cout<<"In problem # 3"<<endl<<endl;
    }
    void problem4()
    {
           cout<<"In problem # 4"<<endl<<endl;
    }
    void problem5()
    {
           cout<<"In problem # 5"<<endl<<endl;
    }
    void problem6()
    {
           cout<<"In problem # 6"<<endl<<endl;
    }
    void problem7()
    {
	   cout<<"In problem # 7"<<endl<<endl;
    }
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }


