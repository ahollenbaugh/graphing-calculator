#include "eval.h"
#include "../../!includes/Token/token.h"
#include "../../!includes/Function/function.h"

double eval(Queue<Token*> postfix){
    // use this if your expression doesn't have a variable
    // takes the first two operands off the top of the stack,
    // applies the operator to the two operands,
    // and pushes the result back onto the top of the stack.
    const bool debug = false;
    if(debug)cout << postfix << endl;
    Stack<Operand*> s;
    Token* p;
    Operand* left;
    Operand* right;
    double ans;
    Operand* oandPtr;
    Operator* otorPtr;
    Function* fPtr;

    while(!postfix.empty()){ // go through entire queue
        p = postfix.pop(); // check whether OAND or OTOR
        if(debug){
            cout << "main::eval: popping " << p
                                   << " off queue" << endl;
            cout << "postfix: " << postfix << endl;
        }
        if(debug){
            cout << p << " is of type " << p->TypeOf() << endl;
        }
        switch(p->TypeOf()){
        // sort OAND and OTOR
        // OANDs go onto stack
        // OTORs are applied to the top two OANDs on stack
        case 4:
            // Do this for FUNCTIONS:
            // convert p from Token* to Operator* so that
            // the eval() function from the Function class can be used:
            fPtr = static_cast<Function*>(p);
            if(fPtr->numberOfArgs() == 1){
                // if your function has ONE argument:
                if(debug) cout << "eval::eval: FUNCTION WITH ONE ARG" << endl;
                if(debug) cout << "s: " << s << endl;
                right = s.pop(); // grab an operand from the stack
                if(debug){
                    cout << "main::eval: popping " << right << " off stack" << endl;
                }
                ans = fPtr->eval(right->num()); // apply OTOR to OANDs
                if(debug) cout << "main::eval: ans = " << ans << endl;
                s.push(new Operand(ans)); // push answer back onto stack
                if(debug) cout << "ans = " << ans << endl;
            }
            else if(fPtr->numberOfArgs() == 2){
                // if your function has TWO arguments:
                if(debug) cout << "eval::eval: FUNCTION WITH TWO ARGS" << endl;
                left = s.pop();
                right = s.pop();
                ans = fPtr->eval(left->num(), right->num());
                if(debug) cout << "eval::eval:function with two args: ans = " << ans << endl;
                s.push(new Operand(ans));
            }
            break;
        case 2:
            // Do this for OPERANDS:
            // cast p from Token* to Operand*
            // so that we can push it to the stack:
            oandPtr = static_cast<Operand*>(p);
            if(debug){
                cout << "oandPtr: " << oandPtr->num() << endl;
            }
            s.push(oandPtr); // push to stack
            if(debug){
                cout << "main::eval: pushing " << oandPtr->num() << " onto stack" << endl;
                cout << "main::eval: s: " << s << endl;
            }
            break;
        case 1:
            // Do this for OPERATORS:
            if(debug) cout << "s: " << s << endl;
            right = s.pop(); // grab an operand from the stack
            if(debug){
                cout << "main::eval: popping " << right << " off stack" << endl;
            }
            left = s.pop(); // grab another operand from the stack
            if(debug){
                cout << "main::eval: popping " << left << " off stack" << endl;
            }
            // convert p from Token* to Operator* so that
            // the result() function from the operator class can be used:
            otorPtr = static_cast<Operator*>(p);
            ans = otorPtr->result(left->num(), right->num()); // apply OTOR to OANDs
            if(debug) cout << "main::eval: ans = " << ans << endl;
            s.push(new Operand(ans)); // push answer back onto stack
            if(debug) cout << "ans = " << ans << endl;
            break;
        default:
            break;
        }

    }
    Operand* finalAnswer = s.top();
//    cout << finalAnswer << endl;
    return finalAnswer->num();
}

double eval(Queue<Token*> postfix, double var){
    // overloaded eval function
    // use this if your expression has a variable
    const bool debug = false;
    Stack<Operand*> s; // store your answer here
    Token* p;
    Operand* left;
    Operand* right;
    double ans;
    Operand* oandPtr;
    Operator* otorPtr;
    Function* fPtr;

    while(!postfix.empty()){ // go through entire queue
        p = postfix.pop(); // check whether OAND or OTOR
        if(debug){
            cout << "main::eval: popping " << p
                                   << " off queue" << endl;
            cout << "postfix: " << postfix << endl;
        }
        if(debug){
            cout << p << " is of type " << p->TypeOf() << endl;
        }
        Operand test(var);
        switch(p->TypeOf()){
        // sort OAND and OTOR
        // OANDs go onto stack
        // OTORs are applied to the top two OANDs on stack
        case 4:
//            // Do this for FUNCTIONS:

//            // this, except you pop only one argument.


//            if(debug) cout << "s: " << s << endl;
//            right = s.pop(); // grab an operand from the stack
//            if(debug){
//                cout << "main::eval: popping " << right << " off stack" << endl;
//            }
//            // convert p from Token* to Operator* so that
//            // the result() function from the operator class can be used:
////            otorPtr = static_cast<Operator*>(p);
//            fPtr = static_cast<Function*>(p);
//            ans = fPtr->eval(right->num()); // apply OTOR to OANDs
//            if(debug) cout << "main::eval: ans = " << ans << endl;
//            s.push(new Operand(ans)); // push answer back onto stack
//            if(debug) cout << "ans = " << ans << endl;

            // Do this for FUNCTIONS:
            // convert p from Token* to Operator* so that
            // the eval() function from the Function class can be used:
            fPtr = static_cast<Function*>(p);
            if(fPtr->numberOfArgs() == 1){
                // if your function has ONE argument:
                if(debug) cout << "eval::eval: FUNCTION WITH ONE ARG" << endl;
                if(debug) cout << "s: " << s << endl;
                right = s.pop(); // grab an operand from the stack
                if(debug){
                    cout << "main::eval: popping " << right << " off stack" << endl;
                }
                ans = fPtr->eval(right->num()); // apply OTOR to OANDs
                if(debug) cout << "main::eval: ans = " << ans << endl;
                s.push(new Operand(ans)); // push answer back onto stack
                if(debug) cout << "ans = " << ans << endl;
            }
            else if(fPtr->numberOfArgs() == 2){
                // if your function has TWO arguments:
                if(debug) cout << "eval::eval: FUNCTION WITH TWO ARGS" << endl;
                left = s.pop();
                right = s.pop();
                ans = fPtr->eval(left->num(), right->num());
                if(debug) cout << "eval::eval:function with two args: ans = " << ans << endl;
                s.push(new Operand(ans));
            }
            break;

            break;
        case 3:
            // Do this for VARIABLES:
            oandPtr = static_cast<Operand*>(p);
            *oandPtr = test;
            if(debug){
                cout << "oandPtr: " << oandPtr->num() << endl;
            }
            s.push(oandPtr);
            if(debug){
                cout << "main::eval: pushing " << oandPtr->num() << " onto stack" << endl;
                cout << "main::eval: s: " << s << endl;
            }
            break;
        case 2:
            // Do this for OPERANDS:
            // cast p from Token* to Operand*
            // so that we can push it to the stack:
            oandPtr = static_cast<Operand*>(p);
            if(debug){
                cout << "oandPtr: " << oandPtr->num() << endl;
            }
            s.push(oandPtr); // push to stack
            if(debug){
                cout << "main::eval: pushing " << oandPtr->num() << " onto stack" << endl;
                cout << "main::eval: s: " << s << endl;
            }
            break;
        case 1:
            // Do this for OPERATORS:

            if(debug) cout << "s: " << s << endl;
            right = s.pop(); // grab an operand from the stack
            if(debug){
                cout << "main::eval: popping " << right << " off stack" << endl;
            }
            left = s.pop(); // grab another operand from the stack
            if(debug){
                cout << "main::eval: popping " << left << " off stack" << endl;
            }
            // convert p from Token* to Operator* so that
            // the result() function from the operator class can be used:
            otorPtr = static_cast<Operator*>(p);
            ans = otorPtr->result(left->num(), right->num()); // apply OTOR to OANDs
            if(debug) cout << "main::eval: ans = " << ans << endl;
            s.push(new Operand(ans)); // push answer back onto stack
            if(debug) cout << "ans = " << ans << endl;
            break;
        default:
            break;
        }

    }
    return s.top()->num();

}

//double eval(Queue<Token*> postfix, Operand var){
//    // overloaded eval function
//    // use this if your expression has a variable
//    const bool debug = false;
//    Stack<Operand*> s;
//    Token* p;
//    Operand* left;
//    Operand* right;
//    double ans;
//    Operand* oandPtr;
//    Operator* otorPtr;
//    cout << "POSTFIX: " << postfix << endl;
//    while(!postfix.empty()){ // go through entire queue
//        p = postfix.pop(); // check whether OAND or OTOR
//        if(debug){
//            cout << "main::eval: popping " << p
//                                   << " off queue" << endl;
//            cout << "postfix: " << postfix << endl;
//        }
//        if(debug){
//            cout << p << " is of type " << p->TypeOf() << endl;
//        }
//        switch(p->TypeOf()){
//        // sort OAND and OTOR
//        // OANDs go onto stack
//        // OTORs are applied to the top two OANDs on stack
//        case 3:
//            // Do this for VARIABLES:
//            oandPtr = static_cast<Operand*>(p);
//            *oandPtr = var;
//            if(debug){
//                cout << "oandPtr: " << oandPtr->num() << endl;
//            }
//            s.push(oandPtr);
//            if(debug){
//                cout << "main::eval: pushing " << oandPtr->num() << " onto stack" << endl;
//                cout << "main::eval: s: " << s << endl;
//            }
//            break;
//        case 2:
//            // Do this for OPERANDS:
//            // cast p from Token* to Operand*
//            // so that we can push it to the stack:
//            oandPtr = static_cast<Operand*>(p);
//            if(debug){
//                cout << "oandPtr: " << oandPtr->num() << endl;
//            }
//            s.push(oandPtr); // push to stack
//            if(debug){
//                cout << "main::eval: pushing " << oandPtr->num() << " onto stack" << endl;
//                cout << "main::eval: s: " << s << endl;
//            }
//            break;
//        case 1:
//            // Do this for OPERATORS:
//            if(debug) cout << "s: " << s << endl;
//            right = s.pop(); // grab an operand from the stack
//            if(debug){
//                cout << "main::eval: popping " << right << " off stack" << endl;
//            }
//            left = s.pop(); // grab another operand from the stack
//            if(debug){
//                cout << "main::eval: popping " << left << " off stack" << endl;
//            }
//            // convert p from Token* to Operator* so that
//            // the result() function from the operator class can be used:
//            otorPtr = static_cast<Operator*>(p);
//            ans = otorPtr->result(left->num(), right->num()); // apply OTOR to OANDs
//            if(debug) cout << "main::eval: ans = " << ans << endl;
//            s.push(new Operand(ans)); // push answer back onto stack
//            if(debug) cout << "ans = " << ans << endl;
//            break;
//        default:
//            break;
//        }

//    }
//    return s.top()->num();

//}

