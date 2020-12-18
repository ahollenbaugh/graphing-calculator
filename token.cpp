#include "token.h"
#include <string>
#include <iostream>
using namespace std;

Token::Token()
{
    // left blank
}
ostream& operator <<(ostream& outs, const Token* t){
    if (t==NULL) {
        cout<<"<<*t, t is NULL";
        cin.get();
    }

    t->print(outs);
    return outs;
}
void Token::print(ostream& outs) const{
//    outs << *this;
//    return outs;
}
int Token::TypeOf(){
    // returns some integer depending on object type
    // if operator... return 1
    // if operand... return 2
}
int Token::precedence(){
    //
}
