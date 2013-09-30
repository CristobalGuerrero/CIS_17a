// Joseph Erian												Homework: Scores
//Input: The user will input ten scores
//Process: find the standerd deviation
//Output: standerd deviation
// take the input (10 numbers subtract the average, square them, sum all, divide by 9, then takesquare root

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double dev(double *, int, double);
int main()
{
	int size=10;
	 double a[10],avg=0,devi,i;
//    ifstream idm;
//    ofstream out;
//    idm.open("test.dat");
//	idm>>i;
//	out<<i<<endl;
        for (int i=0; i<size; i++)
	{
            cout<< "enter a number";
            cin>>a[i];

	}
//idm>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9];

	//double avg=0;
	for (int j=0; j<size; j++)
	{
		avg+=a[j];
	}
//cout<<temp; debugger
	avg/=size;
	devi=dev(a, size, avg);
	cout<<"The deviation is: "<<devi<<endl;
	cout<<"The average is: "<<avg;
	cout<<"";
	cin>>avg;

//avg=(v_1+v_2+v_3+v_4+v_5+v_6+v_7+v_8+v_9+v_10)/10;
//cout<<"mean is "<<avg;
//delete []a;
	return 0;
}

double dev(double *a, int size, double avg)
{
	double tot=0,variance=0,deviation=0;
	for (int i=0; i<size; i++)
	{
			a[i]=avg-a[i];
			a[i]=pow(a[i],2);
			tot+=a[i];


				}
	variance = tot/(size-1);
	cout << "The variance is: "<<variance<<endl;
	deviation = sqrt(variance);

return deviation;
}
