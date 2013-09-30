/* 
 * File:   Employee.h
 * Author: Owner
 *
 * Created on June 11, 2010, 8:45 PM
 */

#ifndef _EMPLOYEE_H
#define	_EMPLOYEE_H

class Employee {
public:
		Employee(char[],char[],float);  //Constructor
		float  CalculatePay(float,int); //Procedure
		float  getGrossPay(float,int);  //Procedure
		float  getNetPay(float);        //Procedure
		void   toString();              //Procedure
		int    setHoursWorked(int);     //Procedure
		float  setHourlyRate(float);    //Procedure
	private:
		double Tax(float);      //Utility Procedure
		char   MyName[20];      //Property
		char   JobTitle[20];    //Property
		float  HourlyRate;      //Property
		int    HoursWorked;     //Property
		float  GrossPay;        //Property
		float  NetPay;          //Property
                int    Namesize;        //Property

};

#endif	/* _EMPLOYEE_H */

