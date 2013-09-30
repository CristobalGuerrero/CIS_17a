/* 
 * File:   Prob4.h
 * Author: Owner
 *
 * Created on June 11, 2010, 7:47 PM
 */

#ifndef _PROB4_H
#define	_PROB4_H

class Prob4 {
public:
		Prob4(float);               //Constructor
		void  Transaction(float);            //Procedure
		float Total(float=0,int=0);	         //Savings Procedure
		float TotalRecursive(float=0,int=0);
		void  toString();                    //Output Properties
                ~Prob4();
private:
		float Withdraw(float);               //Utility Procedure
		float Deposit(float);                //Utility Procedure
		float Balance;                       //Property
		int   FreqWithDraw;                  //Property
		int   FreqDeposit;                   //Property

};

#endif	/* _PROB4_H */

