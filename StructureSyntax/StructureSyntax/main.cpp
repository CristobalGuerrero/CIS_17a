//Dr. Mark E. Lehr
//March 29th, 2010
//All the syntax you could want

#include <cstdlib>  //Standard Lib constants/etc...
#include <ctime>    //Time
#include <iostream> //I/O
using namespace std;

struct Xstructure{
    int a;      //Variable value
    int *bptr;  //Single value pointer
    int *carray;//Array pointer
    int sz;     //Size of array
};


//Structures that are not arrays
void fillStructure(Xstructure &,int);
Xstructure *fillStructure(int);
Xstructure *fillStructure1(int);
void printStructure(Xstructure);
void destroyStructure(Xstructure);
void destroyStructure(Xstructure *);
//Structures that are static arrays
void fillStructure(Xstructure [],int,int);
void printStructure(Xstructure [],int);
void destroyStructure(Xstructure [],int);
//Structures that are dynamic arrays
Xstructure *fillStructure(int,int);

int main(int argc, char** argv) {
    //Declare and utilze a structure
    int arraysize=5;
    srand(static_cast<unsigned int>(time(0)));
    Xstructure x;
    fillStructure(x,arraysize);
    printStructure(x);
    destroyStructure(x);
    //Use the above with a different fill
    Xstructure *xx=fillStructure(arraysize);
    printStructure(*xx);
    destroyStructure(xx);
    //Use the above with a different fill
    Xstructure *xxx=fillStructure1(arraysize);
    printStructure(*xxx);
    destroyStructure(xxx);
    //Static Structure Array
    const int nStruct=2;
    Xstructure y[nStruct];
    fillStructure(y,nStruct,arraysize);
    printStructure(y,nStruct);
    destroyStructure(y,nStruct);
    //Dynamic Structure Array
    int nDynStruct=3;
    Xstructure *yy=fillStructure(nDynStruct,arraysize);
    printStructure(yy,nDynStruct);
    destroyStructure(yy,nDynStruct);
    delete [] yy;

    return (EXIT_SUCCESS);
}
Xstructure *fillStructure(int ns,int na){
    Xstructure *x=new Xstructure[ns];
    for(int i=0;i<ns;i++){
        fillStructure(x[i],na);
    }
    return x;
}

void fillStructure(Xstructure x[],int ns,int na){
    for(int i=0;i<ns;i++){
        fillStructure(x[i],na);
    }
}
void printStructure(Xstructure x[],int ns){
    cout<<"My array of Structures"<<endl;
    for(int i=0;i<ns;i++){
        printStructure(x[i]);
    }
    cout<<"The end of My array of Structures"<<endl;
}
void destroyStructure(Xstructure x[],int ns){
    for(int i=0;i<ns;i++){
        destroyStructure(x[i]);
    }
}

void fillStructure(Xstructure &x,int n){
    x.a=rand()%100;
    x.bptr=&x.a;
    if(n<=2)x.sz=2;
    else x.sz=n;
    x.carray=new int[x.sz];
    for(int i=0;i<x.sz;i++){
        x.carray[i]=rand();
    }
}
Xstructure *fillStructure(int n){
    Xstructure *x=new Xstructure;
    x->a=rand()%100;
    x->bptr=&x->a;
    if(n<=2)x->sz=2;
    else x->sz=n;
    x->carray=new int[x->sz];
    for(int i=0;i<x->sz;i++){
        x->carray[i]=rand();
    }
    return x;
}
Xstructure *fillStructure1(int n){
    Xstructure *x=new Xstructure;
    (*x).a=rand()%100;
    (*x).bptr=&(*x).a;
    if(n<=2)(*x).sz=2;
    else (*x).sz=n;
    (*x).carray=new int[(*x).sz];
    for(int i=0;i<(*x).sz;i++){
        //(*x).carray[i]=rand();
        *((*x).carray+i)=rand();
    }
    return x;
}
void printStructure(Xstructure x){
    cout<<"Our Structure"<<endl;
    cout<<"a="<<x.a<<endl;
    cout<<"*b="<<*x.bptr<<endl;
    cout<<"b address="<<x.bptr<<endl;
    cout<<"The Array size="<<x.sz<<endl;
    for(int i=0;i<x.sz;i++){
        cout<<"c["<<i<<"]="<<x.carray[i]<<endl;
    }
    cout<<"The end of our Structure"<<endl;
}
void destroyStructure(Xstructure x){
    delete []x.carray;
}
void destroyStructure(Xstructure *x){
    delete []x->carray;
    delete x;
}