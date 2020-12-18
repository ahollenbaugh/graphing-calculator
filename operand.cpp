#include "operand.h"


Operand::Operand(): Token()
{
    // left blank
}

Operand::Operand(double num): _num(num){
    // left blank
}
void Operand::print(ostream& outs = cout) const{
    outs << this->_num;
//    return outs;
}
double Operand::num(){
    return _num;
}
int Operand::TypeOf(){
    return 2;
}
