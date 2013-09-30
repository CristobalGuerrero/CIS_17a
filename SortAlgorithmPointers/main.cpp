//Cristobal Guerrero
//CIS-17a
//moded on March 22, 2010, 12:00 pm

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
int * mode(int*,int);



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
     //Find the mode of the function
    int *modeArray=mode(cArray,N);
    //Print the sorted Array
    printArray(cArray,N,NPERLINE);
    cout<<"The Size of the Array is = "<<N<<endl
        <<"The Median of the array is = "<<bArray<<endl
        <<"The average of the Array is = "<<AverArray<<endl
        <<"The last mode is = "<<modeArray[0]<<endl;
    //Clean up memory to prevent leakage
    delete []mArray;
    delete []cArray;
    delete []modeArray;
    return (EXIT_SUCCESS);
}
//find the mode of the array
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
