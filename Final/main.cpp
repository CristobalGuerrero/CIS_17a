/* 
 * File:   main.cpp
 * Author: Owner
 *
 * Created on June 11, 2010, 1:21 PM
 */

#include <stdlib.h>
#include <fstream>
#include "Prob1Random.h"
#include "Prob4.h"
#include "Employee.h"
#include <iostream>
using namespace std;
template<class T>
class Prob2Sort
{
	private:
		char *index;                                 //Index that is utilized in the sort
	public:
		Prob2Sort(){index=NULL;};                   //Constructor
		~Prob2Sort(){delete []index;};              //Destructor
		T * sortArray(const T*,int,bool){};           //Sorts a single column array
		T * sortArray(const T* a,int b,int c,int d,bool e){   //Sorts a 2 dimensional array
                    index = new char[b*c];
    int temp = b*c;
    for(int i=0;i<temp;i++){
        index[i]=a[i];}
    if(e)
    for (d;d<temp-1;d+=15){
        for (int j=d+15;j<temp;j+=15){
            if(index[d]>index[j]){
                index[d]=index[d]^index[j];
                index[j]=index[d]^index[j];
                index[d]=index[d]^index[j];}}}
    else
    {
       for (d;d<temp-1;d+=15){
        for (int j=d+15;j<temp;j+=15){
            if(index[d]<index[j]){
                index[d]=index[d]^index[j];
                index[j]=index[d]^index[j];
                index[d]=index[d]^index[j];
            }}}}
    return index;}};

/*
 * 
 */
void Menu();
int getN();
void def(int);
void Problem5();
void Problem4();
void Problem3();
void Problem1();
void Problem2();
int main(int argc, char** argv) {
   int inN;
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    Problem1();break;
          case 2:    Problem2();break;
          //case 3:    Problem3();break;
          case 4:    Problem4();break;
          case 5:    Problem5();break;
          default:   0;}
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
           cout<<"Type 8 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
		   cin>>inN;
           return inN;
    }
void Problem2(){
    cout<<"The start of Problem 2, the sorting problem"<<endl;
	Prob2Sort<char> rc;
	bool ascending=true;
	ifstream infile;
	infile.open("Problem2.txt",ios::in);
        if(infile.fail()){
            cout<<"The file failed to open!\n";
        }
        else{
	char *ch2=new char[10*16];
	char *ch2p=ch2;
	while(infile.get(*ch2)){cout<<*ch2;ch2++;}
	infile.close();
	cout<<endl;
	cout<<"Sorting on which column"<<endl;
	int column;
	cin>>column;
	char *zc=rc.sortArray(ch2p,10,16,column,ascending);
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<16;j++)
		{
			cout<<zc[i*16+j];
		}
	}
	delete []zc;
	cout<<endl;}
}

void Problem5(){
    Employee Mark("Mark","Boss",215.50);
	Mark.setHoursWorked(-3);
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(20.0),
		Mark.setHoursWorked(25));
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(40.0),
		Mark.setHoursWorked(25));
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(60.0),
		Mark.setHoursWorked(25));
	Mark.toString();

	Employee Mary("Mary","VP",50.0);
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(40));
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(50));
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(60));
	Mary.toString();
}


void Problem4(){
    Prob4 mine(-300);

	for(int i=1;i<=10;i++)
	{
		mine.Transaction((float)(rand()%500)*(rand()%3-1));
	}
	mine.toString();
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.Total((float)(0.10),7)<<endl;
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.TotalRecursive((float)(0.10),7)
		<<" Recursive Calculation "<<endl;
}


void Problem1(){
    char n=5;
	char rndseq[]={16,34,57,79,121};
	int ntimes=100000;
	Prob1Random a(n,rndseq);
	for(int i=1;i<=ntimes;i++)
	{
		a.randFromSet();
	}
	int *x=a.getFreq();
	char *y=a.getSet();
	for(int i=0;i<n;i++)
	{
		cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
	}
	cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}

