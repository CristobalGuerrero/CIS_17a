/* 
 * File:   Manual.h
 * Author: Owner
 *
 * Created on June 3, 2010, 12:39 PM
 */

#ifndef _MANUAL_H
#define	_MANUAL_H

#include <string>
using namespace std;

class Manual {
    protected:
        int manualsize;
        string *manualmachine;
        double *manualcost;
    public:
        string *manualfill(int);  //This is an manual fill for the vending machine if the user picks to test
        double *manualcostfill(int); //This is for manual fill for the cost
};
#endif	/* _MANUAL_H */

