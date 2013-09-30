// Hello World.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//defines the complete function above main
int sq(int x){
	return x*x;}

float save(float p, float i, int n){
		float bal=p;
		for(int j=1;j<+n;j++){
			val*=(1+i);}
		return bal;}

//defines prototype
int sq1(int);



int _tmain(int argc, _TCHAR* argv[])
{
	//kerninghan and ritchie
	string input;
	cout << "Hello World!" << endl;
	char a = 10;
	char b = 55;
	char c= a + b;
	cout << "c= " << c << endl;
	cout << "c= " << (static_cast<int>(c)) << endl;
	
	//overflow or wrap example
	c+= 100;
	cout << "c= " << (static_cast<int>(c)) << endl;
	unsigned char cc= c;
	cout << "cc= " << (static_cast<int>(cc)) << endl;

	//another integer wrap
	short aa= 10000, bb=30000,ee;
	ee=aa+bb;
	cout << "ee= " << (static_cast<int>(ee)) << endl;
	unsigned short eee= ee;
	cout << "eee= " << (static_cast<int>(eee)) << endl;
	
	//float inaccuracy
	//float sum 0.0f;
	//for(int i=1;i<=10000000;i++){
	//sum+=0.1f;}
	//cout << "Sum=" << sum << endl;

	cout << "n=10 and n^2= "<< sq(10) << endl;
	cout << "sav(100,0.05f)"; << save(100f,0.06f,12) << endl;
	cout << "that's it";
	cin >> input;
	return 0;
}

