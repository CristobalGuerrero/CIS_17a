
//header includes
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main ()
{
    //initializing the variables
    double sum=1,powerOfx,nFactorial,counter,total=0,x,MAX_N = 100;
    string goAgain; //variable for loop check
    string formula = "1 + x + x^2/2! + ... + x^n/n!"; //gen formula
    string question = "Do you want to enter another x? (y or n) ";
    string comparison = "Your answer from the caluclation we made: ";
    do {
        cout << "Enter a value of x: ";
        cin >> x;
        cout << endl;

        cout << "Estimated value of e^" << x << " using the sum ";

        cout << formula << endl;
        cout << endl;
		nFactorial=1;

		for ( counter = 1; counter <= MAX_N; counter++ )
		{
                        powerOfx = pow(x,counter);
			nFactorial = nFactorial * counter;
                        total = powerOfx/nFactorial;
                        sum += total;
		}

        cout <<comparison<<sum<<endl;
        // Output the C++ exp function value for comparison
        cout << "C++ Function exp(x): " << exp(x) << endl;

        //ask the user the question if they would like to start the loop again
        //then it inputs it in the the variable go again for a condition check
        cout << question;
        cin >> goAgain;
        cout << endl;
        sum = 1;
    }
    while (goAgain=="Y"||goAgain=="y"||goAgain=="Yes"||goAgain=="yes");

    return 0;
}

