#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int encrypt(int);
int decrypt(int);
void swap(int,int);
int main(){

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
    return 0;
    }

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

void swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}

