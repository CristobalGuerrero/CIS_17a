//Mark E. Lehr
//April 5th, 2010
//Example Menu to be used for the midterm,
//final, and homework

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;
struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

statsResult *avgMedMode(int *,int);


struct Banking{
    double balance;
    double deposit;
    double withdraw;
    int account;
    char question;
};
struct Payroll{
   string ename;
   double hours;
   double pay;
   string *array;
   double *payarray;
   int sz;
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


//Problem number 2 prototypes
double normpay(double,double);
double xpay(double,double);
double txpay(double,double);
void printarrays(string,double);
//Problem number 4 prototypes
int encrypt(int);
int decrypt(int);
void swap(int&,int&);
//Problem number 3 prototypes
int * fillArray(int);
void printArray(int *,int,int);
void swapREF(int &,int &);
void swapPTR(int *,int *);
void swapXOR(int &,int &);
void sortPos(int,int *,int);
void mSort(int*,int);
int * copyArray(int*,int);
int * markSort(int*,int);
float median(int*,int);
float average(int*,int);
int * mode(int*,int);

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
        temp=0;
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
        <<"Have a nice day!"<<endl<<endl;
    }
    else{
        cout << "There are too many input errors try again later."<<endl;
    }}





    void problem2()
    {
           cout<<"In problem # 2"<<endl<<endl;
            Payroll check;
    int i = 0;
    double hour=0,pays=0;
    check.sz=50;
    check.array=new string[check.sz];

    while((hour>=0||pays>=0)){
        cout<< "Employee's name: ";
        cin >> check.array[i];
        cout<< "Hours worked: ";
        cin >> hour;
        check.hours=hour;
        cout<<"Workers pay: ";
        cin >> pays;
        check.pay=pays;

        if(check.hours<=20){
            check.pay=normpay(check.pay,check.hours);
        }
        else if(check.hours>20&&check.hours<=40){
            check.pay=xpay(check.pay,check.hours);
        }
        else{
            check.pay=txpay(check.pay,check.hours);
        }
        check.payarray[i]=check.pay;
        i++;
    }
    for(int n=0;n<i-1;n++){
        cout << check.array[n] << " made a total of: " <<check.payarray[n]<<endl;
    }
}
//Problem 2 functions
double normpay(double a,double b){
    return a*b;
}

double xpay(double pay,double hours){
     double pay2=pay*2;
            pay*=20;
            hours-=20;
            pay2*=hours;
     return pay+=pay2;
}

double txpay(double pay,double hours){
     double pay2=pay*2;
     double pay3=pay*3;
            pay*=20;
            pay2*=20;
            hours-=40;
            pay3*=hours;
    return (pay+pay2+pay3);
}



    void problem3()
    {
           cout<<"In problem # 3"<<endl<<endl;
            //Declare an array and set the seed
           statsResult stats;
    int N;
    cout<<"Input the size of the array"<<endl;
    cin>>N;
    const int NPERLINE=10;
    srand(static_cast<unsigned int>(time(0)));
    //Fill the Array
    int *mArray=fillArray(N);
    //Print out the array
    printArray(mArray,N,NPERLINE);
    //Sort the first position
    int *cArray=markSort(mArray,N);
    //Find the median of the Array
    stats.median=median(cArray,N);
    //Find the average of the Array
    stats.avg=average(cArray,N);
     //Find the mode of the function
    stats.mode=mode(cArray,N);
    //Print the sorted Array
    printArray(cArray,N,NPERLINE);
    cout<<"The Size of the Array is = "<<N<<endl
        <<"The Median of the array is = "<<stats.median<<endl
        <<"The average of the Array is = "<<stats.avg<<endl
        <<"The last mode is = "<<*(stats.mode)<<endl;
    //Clean up memory to prevent leakage
    delete []mArray;
    delete []cArray;
    delete []stats.mode;
    }
//Problem 3 functions
int *mode(int a[],int n){
    int *a2,count,sentinel=0,temp,highest=0;
    int mode=0;
    a2=new int[n];
    //clearing the new array for future test
    for(count=0;count<n;count++){a2[count]=0;}

    for(count=0;count<n;count++){
        temp=a[count];
        a2[temp]++;
    }

    //Finds the mode of the function
    for(count=0;count<n+1;count++){
        //checks and sets the mode
        if(a2[count]>highest){
            highest=a2[count];
            mode=count;
        }
        //checking if there are multiple modes
        //if(mode==a3[sentinel]){
           // a3[sentinel]=mode;
           // sentinel++;
        //}
    }
    count=0;
    a2[count]=mode;
    return a2;
}
//find the average of the array
float average(int a[],int n){
    float total=0;
    for(int i=0;i<n;i++)
    {
        total+=a[i];
    }
    total/=n;
    return total;
}
//finding the median of the array
float median(int a[],int n){
    float middle,temp,temp2;

    if((n%2)==1 && n!=2){
         n/=2;
         middle = a[n];}
    else if((n%2)==0){
        n/=2;
        temp2 = a[n];
        temp = a[n-1];
        middle = (temp2+temp)/2;
    }
    return middle;
}

//Sorting a copy vs. an original
int * markSort(int orig[],int n){
    int *cpy=copyArray(orig,n);
    mSort(cpy,n);
    return cpy;
}

//Making a copy of an array
int * copyArray(int orig[],int n){
    int *cpy=new int[n];
    for(int i=0;i<n;i++){
        cpy[i]=orig[i];
    }
    return cpy;
}

//Sorting all Positions thereby accomplishing a full sort
void mSort(int a[],int n){
    for(int i=0;i<n;i++){
        sortPos(i,a,n);
    }
}

//Sorting a single position
void sortPos(int pos,int a[],int n){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i])swapPTR(&a[pos],&a[i]); //The Pointer Call
        //if(a[pos]>a[i])swapREF(a[pos],a[i]);  The Reference Call
    }
}

//XOR Swap in place
void swapXOR(int &a,int &b){
    a=b^a;
    b=b^a;
    a=b^a;
}

//Swap using temporary position  Pointer
void swapPTR(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

//Swap using temporary position  Reference
void swapREF(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

//Filling an array with 2 digit random numbers
int * fillArray(int n){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter in a number for the array "<<(i+1)<<": ";
        cin>>a[i];
    }
    return a;
}

//Printing an array
void printArray(int a[],int n,int nPerLine){

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%nPerLine==(nPerLine-1))cout<<endl;
    }
    cout<<endl<<endl;
}


    void problem4()
    {
           cout<<"In problem # 4"<<endl<<endl;
           int num, num2,num3,num4,num5=0,counter=1,pogo;
string decision = "Yes";

cout << "Would you like to"<<endl
     << "Encrypt = 1" << endl
     << "Decrypt =2"  << endl;
cin >> pogo;



if(pogo==2){
    while(decision=="Y"||decision=="y"||decision=="Yes"||decision=="yes"){
    if(counter>2){
        cout << "Forget it you just ruined the program!"<<endl
             << "Encryption reset: 0000"<<endl;decision="no";}
    if(counter<=2){
        cout <<endl<< "4 digit num to decrypt: " << endl;
        cin>>num;

    num2=num;
    num2/=1000;
    num3=(num%1000)/100;
    num4=(num%100)/10;
    num5=(num%10)/1;
    swap(num2,num3);
    swap(num4,num5);
    if(num2==8||num2==9){
        cout << "Your first digit is not valid" << endl;counter++;}
    else if(num2!=8||num2!=9){
        num2=decrypt(num2);}

    if(num3==8||num3==9){
        cout << "Your second digit is not valid" << endl;counter++;}
    else if(num3!=8||num3!=9){
        num3=decrypt(num3);}

    if(num4==8||num4==9){
        cout << "Your third digit is not valid" << endl;counter++;}
    else if(num4!=8||num4!=9){
        num4=decrypt(num4);}

    if(num5==8||num5==9){
        cout << "Your fourth digit is not valid" << endl;counter++;}
    else if(num5!=8||num5!=9){
        num5=decrypt(num5);}
    cout<< num2<<num3<<num4<<num5<<endl;
    cout<<"Try again? ";
    cin >> decision;
}}}







//Encryption
if(pogo==1){
while(decision=="Y"||decision=="y"||decision=="Yes"||decision=="yes"){
    if(counter>2){
        cout << "Forget it you just ruined the program!"<<endl
             << "Encryption reset: 0000"<<endl;decision="no";}
    if(counter<=2){
        cout << "4 digit num to encrypt: " << endl;
        cin>>num;

    num2=num;
    num2/=1000;
    num3=(num%1000)/100;
    num4=(num%100)/10;
    num5=(num%10)/1;

    if(num2==8||num2==9){
        cout << "Your first digit is not valid" << endl;
    if(counter<=2){cout << "Try again? ";
        cin >> decision;}
        counter++;}
    else if(num2!=8||num2!=9){
        num2=encrypt(num2);}


    if(num3==8||num3==9){
        cout << "Your second digit is not valid"<<endl
             << "Try again? ";
        cin >> decision;
                counter++;}
    else if(num3!=8||num3!=9){
        num3=encrypt(num3);}

    if(num4==8||num4==9){
        cout << "Your third digit is not valid"<<endl
             << "Try again? ";
        cin >> decision;
                counter++;}
    else if(num4!=8||num4!=9){
        num4=encrypt(num4);}

    if(num5==8||num5==9){
       cout << "Your fourth digit is not valid"<<endl
            << "Try again? ";
        cin >> decision;
        counter++;}
    else if(num5!=8||num5!=9){
        num5=encrypt(num5);}
    swap(num2,num3);
    swap(num4,num5);
        cout << num2 << num3 << num4<< num5 << endl;
        cout << "Another encryption? ";cin >> decision;}}}
    }
//Problem 4 functions
int decrypt(int a){
    if(a>=4){
        a-=3;
    }
    else if(a<4){
    a+=5;}
    return a;
}

int encrypt(int a){
    a=(a+3)%8;
    return a;
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}




    void problem5()
    {
           cout<<"In problem # 5"<<endl<<endl;
            int num=1;
    float num2=1;
    double num3=1;
    short num4=1;
    long num5=1;
    int n,i,f,d,s,l;

    //for the normal ints
    for(n=1;n<=20;n++){
            num*=n;
            if(num<=0){
                i=n-1;
                n=20;}}
        cout << "factorial for int: "<<i<<endl;

    //for the floats
    for(n=1;n<=50;n++){
        num2*=n;
         if(num2<=0){
                f=n-1;
                n=50;}
        else if(n==50){f=n;}}
        cout << "factorial for float: "<<f<<endl;

     //for the doubles
     for(n=1;n<=100;n++){
        num3*=n;
        if(num3<=0){
                d=n-1;
                n=100;}
        else if(n==100){d=n;}}
        cout << "factorial for double: "<<d<<endl;

      //for the short ints
      for(n=1;n<=20;n++){
        num4*=n;
         if(num4<=0){
                s=n-1;
                n=20;}}
        cout << "factorial for short int: "<<s<<endl;

       //for the long ints
       for(n=1;n<=20;n++){
        num5*=n;
         if(num5<=0){
                l=n-1;
                n=20;}}
        cout << "factorial for long int: "<<l<<endl
             << "Doubles are the data type that can hold the highest value"<<endl<<endl;

    }
    void problem6()
    {
           cout<<"In problem # 6"<<endl<<endl;
           cout<<"The number  2.125"<<endl
               <<"Binary rep: 01000000000010000000000000000000"<<endl
               <<"Octal rep:  10.1"<<endl
               <<"Hex rep:    40080000"<<endl
               <<"The number  0.06640625"<<endl
               <<"Binary rep: 00111101100010000000000000000000"<<endl
               <<"Octal rep:  .004"<<endl
               <<"Hex rep:    3D880000"<<endl
               <<"The number  -2.125"<<endl
               <<"Binary rep: 11000000000010000000000000000000"<<endl
               <<"Octal rep:  110.1"<<endl
               <<"Hex rep:    C0080000"<<endl
               <<"The number  -0.06640625"<<endl
               <<"Binary rep: 10111101100010000000000000000000"<<endl
               <<"Octal rep:  1.004"<<endl
               <<"Hex rep:    BD880000"<<endl
               <<"The number  46666601"<<endl
               <<"Binary rep: 01000110011001100110011000000001"<<endl
               <<"Dec rep:    14745.501"<<endl
               <<"The number  46666602"<<endl
               <<"Binary rep: 01000110011001100110011000000010"<<endl
               <<"Dec rep:    14745.502"<<endl
               <<"The number  B9999AFE"<<endl
               <<"Binary rep: 10111001100110011001101011111110"<<endl
               <<"Dec rep:    -2.9297912"<<endl<<endl;

    }
    void problem7()
    {
	   cout<<"In problem # 7"<<endl<<endl;
    }
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }


