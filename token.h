#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
using namespace std;

class Token
{
public:
    Token();
    friend ostream& operator <<(ostream& outs, const Token* t);
    virtual void print(ostream& outs = cout) const;
    virtual int TypeOf();
    virtual int precedence();
private:
    //
};

#endif // TOKEN_H
