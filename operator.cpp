#include "operator.h"


Operator::Operator(): Token()
{
    // left blank
}
Operator::Operator(char op):_op(op){
    // left blank
}
void Operator::print(ostream& outs) const{
    outs << this->_op;
//    return outs;
}


double Operator::result(double a, double b){
    switch (_op) {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    default:
        break;
    }
}
int Operator::TypeOf(){
    return 1;
}
int Operator::precedence(){
    // op = stack.top()
    // if my operator has lower precedence
    // than op,
    // (for example, - is lower than *)
    // then return 0
    // otherwise, return 1
    //
    Operator* p;
    p = static_cast<Operator*>(this);
    switch(p->_op){
    case '*':
    case '/':
        return 3;
        break;
    case '+':
    case '-':
        return 2;
        break;
    }
}

char Operator::getOp(){
    // accessor function to get _op
    return _op;
}
