#ifndef OPERAND_H
#define OPERAND_H

#include "../../!includes/Token/token.h"

class Operand: public Token
{
public:
    Operand();
    Operand(double num);
    void print(ostream &outs) const;
    double num();
    int TypeOf();
protected:
    double _num;
};

#endif // OPERAND_H
