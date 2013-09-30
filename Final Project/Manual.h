/* 
 * File:   Manual.h
 * Author: Owner
 *
 * Created on June 4, 2010, 2:36 PM
 */

#ifndef _MANUAL_H
#define	_MANUAL_H
#include <string>
using namespace std;

class Manual {
public:
    Manual();
    Manual(const Manual& orig);
    virtual ~Manual();
    void setsize(int);
    void setindex(int);
    void setsoda();
    void setmoney();
    void setarraysize();
    //fill functions
    double *manualmoney();
    string *manualsoda();
    //get functions
    double getmoney();
    string getsoda();
    int getsize();
    //Print fucntions
    void printarray(int);
    void vendprintcost();
private:
    int index;
    int manualsize;
    string *manualmachine;
    double *manualcost;
};

#endif	/* _MANUAL_H */

