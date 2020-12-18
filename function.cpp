#include "function.h"

Function::Function()
{
    // left blank
}
Function::Function(string fxn): _fxn(fxn){
    // left blank
}
double Function::eval(double x){
    // use this for functions that only take one arg
    const bool debug = false;
    if(_fxn == "sin"){ // sine
        if(debug)cout << "sin(x) = " << sin(x) << endl;
        return sin(x);
    }
    if(_fxn == "cos"){ // cosine
        if(debug)cout << "cos(x) = " << cos(x) << endl;
        return cos(x);
    }
    if(_fxn == "tan"){ // tangent
        if(debug)cout << "tan(x) = " << tan(x) << endl;
        return tan(x);
    }
    if(_fxn == "asin"){ // inverse sine
        if(debug)cout << "arcsin(x) = " << asin(x) << endl;
        return asin(x);
    }
    if(_fxn == "acos"){ // inverse cosine
        if(debug)cout << "arccos(x) = " << acos(x) << endl;
        return acos(x);
    }
    if(_fxn == "atan"){ // inverse tangent
        if(debug)cout << "arctan(x) = " << atan(x) << endl;
        return atan(x);
    }
    if(_fxn == "log"){ // natural log
        if(debug)cout << "log(x) = " << log(x) << endl;
        return log(x);
    }
    if(_fxn == "log10"){ // log base 10
        if(debug)cout << "log10(x) = " << log10(x) << endl;
        return log10(x);
    }
    if(_fxn == "floor"){ // 1.9 is rounded to 1
        if(debug)cout << "floor(x) = " << floor(x) << endl;
        return floor(x);
    }
    if(_fxn == "ceil"){ // 2.1 is rounded to 3
        if(debug)cout << "ceil(x) = " << ceil(x) << endl;
        return ceil(x);
    }
    if(_fxn == "abs"){ // absolute value of x
        if(debug)cout << "abs(x) = " << abs(x) << endl;
        return abs(x);
    }
    if(_fxn == "cosh"){ // hyperbolic cosine
        if(debug)cout << "cosh(x) = " << cosh(x) << endl;
        return cosh(x);
    }
    if(_fxn == "sinh"){ // hyperbolic sine
        if(debug)cout << "sinh(x) = " << sinh(x) << endl;
        return sinh(x);
    }
    if(_fxn == "tanh"){ // hyperbolic tangent
        if(debug)cout << "tanh(x) = " << tanh(x) << endl;
        return tanh(x);
    }
    if(_fxn == "exp"){ // e^x
        if(debug)cout << "exp(x) = " << exp(x) << endl;
        return exp(x);
    }
    if(_fxn == "sqrt"){ // square root
        if(debug)cout << "sqrt(x) = " << sqrt(x) << endl;
        return sqrt(x);
    }
    if(_fxn == "cbrt"){ // cube root
        if(debug)cout << "cbrt(x) = " << cbrt(x) << endl;
        return cbrt(x);
    }
}
double Function::eval(double x1, double x2){
    // use this for evaluating min and max functions
    // since they take two args
    const bool debug = false;
    if(_fxn == "min"){ // get smaller value
        if(debug)cout << "min(x1, x2) = " << fmin(x1, x2) << endl;
        return fmin(x1, x2);
    }
    if(_fxn == "max"){ // get larger value
        if(debug)cout << "max(x1, x2) = " << fmax(x1, x2) << endl;
        return fmax(x1, x2);
    }
}
int Function::TypeOf(){
    return 4;
}
void Function::print(ostream& outs) const{
    outs << this->_fxn;
//    return outs;
}
int Function::precedence(){
    return 1;
}
int Function::numberOfArgs(){
    // return the number of arguments _fxn takes
    // example: sin(x) takes one, while
    // max(2, 3) takes two
    const bool debug = false;
    if(_fxn == "min" || _fxn == "max"){
        if(debug)cout<<"Function::numberOfArgs(): 2" << endl;
        return 2;
    }
    else{
        // most of the functions I have here only take one arg
        if(debug)cout<<"Function::numberOfArgs(): 1" << endl;
        return 1;
    }
}
