/* 
 * File:   Problem_1.h
 * Author: Owner
 *
 * Created on June 11, 2010, 1:23 PM
 */

#ifndef _PROB1RANDOM_H
#define	_PROB1RANDOM_H

class Prob1Random
{
	private:
		char *set;      //The set of numbers to draw random numbers from
		char  nset;     //The number of variables in the sequence
		int  *freq;     //Frequency of all the random numbers returned
		int   numRand;  //The total number of times the random number function is called
	public:
		Prob1Random(const char,const char *);     //Constructor
		~Prob1Random(void);                       //Destructor
		char randFromSet(void);                   //Returns a random number from the set
		int *getFreq(void);                       //Returns the frequency histogram
		char *getSet(void) const;                 //Returns the set used
		int getNumRand(void) const;               //Gets the number of times randFromSet has
		                                          //been called
                void print();
};

#endif	/* _PROBLEM_1_H */

