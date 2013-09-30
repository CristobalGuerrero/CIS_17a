/* 
 * File:   Validate.h
 * Author: Owner
 *
 * Created on June 5, 2010, 8:13 PM
 */

#ifndef _VALIDATE_H
#define	_VALIDATE_H
#include "Auto.h"

class Validate {
public:
    Validate();
    Validate(const Validate& orig);
    double Moneyverify(double);
    string Moneyquestion(double);
    void Automanualset(string);
    string Automanual(string);
    int Sodachoice(string);
    virtual ~Validate();
private:
    string decision;
    string verify;
    string value;
};

#endif	/* _VALIDATE_H */

