#ifndef VARIABLE_H
#define VARIABLE_H
#include "../../!includes/Token/token.h"

class Variable: public Token
{
public:
    Variable();
    Variable(double var);
    int TypeOf();
    void print(ostream& outs = cout) const{cout<<"X";}

private:
    double _var;
};

#endif // VARIABLE_H
