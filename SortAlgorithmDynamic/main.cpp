//Dr. Mark E. Lehr
//Created on March 1, 2010, 6:46 PM

#include <cstdlib>//constants
#include <iostream>//I/O
#include <ctime>//Time
using namespace std;

//Prototypes
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



int main(int argc, char** argv) {
    //Declare an array and set the seed
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
    float bArray=median(cArray,N);
    //Find the average of the Array
    float AverArray=average(cArray,N);
    //Print the sorted Array
    printArray(cArray,N,NPERLINE);
    cout<<"The Size of the Array is = "<<N<<endl
        <<"The Median of the array is = "<<bArray<<endl
        <<"The average of the Array is = "<<AverArray<<endl;
    //Clean up memory to prevent leakage
    delete []mArray;
    delete []cArray;
    return (EXIT_SUCCESS);
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
        a[i]=rand()%90+10;
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