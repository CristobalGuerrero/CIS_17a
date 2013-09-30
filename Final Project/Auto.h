/* 
 * File:   Auto.h
 * Author: Owner
 *
 * Created on June 3, 2010, 11:28 PM
 */

#ifndef _AUTOF_H
#define	_AUTOF_H

#include <string>
using namespace std;

class Auto {
        
public:
    //constructor
    Auto();
    //Destructor
    virtual ~Auto();
    //set functions
    void setsize(int);
    void setindex(int);
    void setsoda();
    void setmoney();
    //fill functions
    double *moneyfilled();
    string *machinefilled();
    //get functions
    double getmoney();
    int getsize();
    string getsoda();
    //Print fucntions
    void printarray();
    void vendprintcost();
private:
    int index;
    int autosize;
    string *automachine;
    double *autocost;
};

#endif	/* _AUTO_H */
