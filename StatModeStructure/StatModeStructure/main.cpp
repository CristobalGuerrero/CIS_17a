//Dr. Mark E. Lehr
//April 19th, 2010
//Solution to Mode Problem Stucture

#include <cstdlib>
#include <iostream>
using namespace std;

struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

int *fillArray(int,int);
void printArray(int *,int,int);
statsResult *avgMedMode(int *,int);
float average(int *,int);
float median(int *,int);
int* copyArray(int *,int);
int* sort(int*,int);
void printStat(statsResult *);

int main(int argc, char** argv) {
    //Testing the Array fill
    const int sArray=20,modArray=5,nPerLine=10;
    int *array=fillArray(sArray,modArray);
    printArray(array,sArray,nPerLine);
    //Call the stat result routine
    statsResult *s=avgMedMode(array,sArray);
    //print results
    printStat(s);
    //Clean up
    delete [] array;
    delete s;
    return (EXIT_SUCCESS);
}

void printStat(statsResult *s){
    cout<<"Average = "<<s->avg<<endl;
    cout<<"Median = "<<s->median<<endl;
    cout<<"Max Freq = "<<s->maxFreq<<endl;
    cout<<"Num Modes = "<<s->nModes<<endl;
    cout<<"{";
    for(int i=0;i<s->nModes;i++){
        if(i==(s->nModes-1)){cout<<s->mode[i];}
        else{
            cout<<s->mode[i]<<",";
        }
    }
    cout<<"}"<<endl;
}

int* sort(int *a,int n){
    int *b=copyArray(a,n);
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if(b[i]>b[j]){
                b[i]=b[i]^b[j];
                b[j]=b[i]^b[j];
                b[i]=b[i]^b[j];
            }
        }
    }
    return b;
}

int* copyArray(int *a,int n){
    int *b=new int[n];
    for (int i=0;i<n;i++){
        b[i]=a[i];
    }
    return b;
}

float average(int *a,int n){
    float avg=0;
    for(int i=0;i<n;i++){
        avg+=a[i];
    }
    return avg/n;
}
float median(int *a,int n){
    if(n%2)return a[n/2];
    return static_cast<float>((a[n/2]+a[n-1]/2)/2.0);
}

statsResult *avgMedMode(int *a,int n){
    statsResult *s=new statsResult;
    int *b=sort(a,n);
    s->avg=average(b,n);
    s->median=median(b,n);
    //Find Max Frequency
    int freq=0,count=0;
    for(int i=0;i<n-1;i++){
        if(b[i]==b[i+1]){
            count++;
            if(freq<count){freq=count;}
        }else{
            count=0;
        }
    }
    //Find nmodes
    int nmodes=0;
    if(freq){
        count=0;
        for(int i=0;i<n-1;i++){
            if(b[i]==b[i+1]){
                count++;
                if(freq==count)nmodes++;
            }else{
                count=0;
            }
        }
        s->nModes=nmodes;
        s->mode=new int[nmodes];
        count=0,nmodes=0;
        for(int i=0;i<n-1;i++){
            if(b[i]==b[i+1]){
                count++;
                if(freq==count)s->mode[nmodes++]=b[i];
            }else{
                count=0;
            }
        }
    }
    s->maxFreq=freq+1;
    //clean up
    delete []b;
    return s;
}

void printArray(int *a,int n,int p){
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%p==(p-1))cout<<endl<<endl;
    }
    cout<<endl<<endl;
}

int *fillArray(int n,int m){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=i%m;
    }
    return a;
}


