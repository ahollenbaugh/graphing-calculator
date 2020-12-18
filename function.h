#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <cmath>
#include "../../!includes/Token/token.h"

using namespace std;

class Function: public Token
{
public:
    Function();
    Function(string fxn);
    double eval(double x);
    double eval(double x1, double x2);
    int TypeOf();
    void print(ostream& outs = cout) const;
    int precedence();
    int numberOfArgs();
private:
    string _fxn;
};

#endif // FUNCTION_H
