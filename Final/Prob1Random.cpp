/* 
 * File:   Problem_1.cpp
 * Author: Owner
 * 
 * Created on June 11, 2010, 1:23 PM
 */

#include <ctime>
#include <iostream>
#include "Prob1Random.h"
using namespace std;

Prob1Random::Prob1Random(const char a,const char * b){  //Constructor
    nset = a;
    set = new char[nset];
    for(int i=0;i<nset;i++){
        set[i]=b[i];
    }
    freq = new int[nset];
    numRand = 0;
}

Prob1Random::~Prob1Random(void){                        //Destructor
    delete []set;
    nset = 0;
}

char Prob1Random::randFromSet(void){                   //Returns a random number from the set
  numRand++;
  char temp = set[(rand()%nset)];
  for(int i=0;i<nset;i++)
  {
      if(temp == set[i])
        {
      freq[i]+=1;
        }
  }
  return temp;
}

int * Prob1Random::getFreq(void)
{//Returns the frequency histogram
    return freq;
}

char * Prob1Random::getSet(void)const {                   //Returns the set used
    return set;
}

int Prob1Random::getNumRand(void)const {         //Gets the number of times randFromSet has
    return numRand;                                     //been called
}

