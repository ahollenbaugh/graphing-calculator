#ifndef OPERATOR_H
#define OPERATOR_H

#include "../../!includes/Token/token.h"

class Operator: public Token
{
public:
    Operator();
    Operator(char op);
    void print(ostream& outs = cout) const;    
    double result(double a, double b);
    int TypeOf();
    int precedence();
    char getOp();
protected:
    char _op;
};

#endif // OPERATOR_H
