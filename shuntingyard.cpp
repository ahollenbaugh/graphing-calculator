#include "shuntingyard.h"

Queue<Token*> infixToPostfix(Queue<Token*> infixExpression){
    // convert an infix expression,
    // for example 3 + x * 2
    // to a postfix expression,
    // for example 3 x 2 * +
    const bool debug = true; // <----- keep this set to TRUE!!!! program will crash otherwise
    Token* t; // stores the token you're popping off the infix queue
    Queue<Token*> postfixExpression; // output queue
    Stack<Token*> operators; // operator stack
    Token* topOfStack;
    Operator* topOp;
    Operator* op;

    // the operator at the top of the stack should always have highest precedence.
    // if you're about to push an operator that has higher precedence than
    // whatever is on top of the stack, then you'll need to
    // 1) pop the top of the stack and push it into the queue, then
    // 2) push your operator to the top of the stack.

    while(!infixExpression.empty()){
        if(debug)cout<<". . . . . . . "<<endl;
        t = infixExpression.pop(); // pop a token off the queue and figure out what to do with it
        if(debug){
            cout << "shuntingYard::infixToPostfix: popping " << t
                 << " off infix queue" << endl
                 << "shuntingYard::infixToPostfix: infix: " << infixExpression
                 << endl;
        }
        switch(t->TypeOf()){
        case 1:
            // operator
            if(debug)cout<<"shunting yard: OPERATOR"<<endl;
            // check if t is a left parenthesis
            // if so, push it to the stack
            // if t is a right parenthesis,
            // dump stuff off stack onto queue until you encounter
            // a left parenthesis
            // then pop the left parenthesis off the stack
            // but don't store it anywhere (we don't need it anymore)
            op = static_cast<Operator*>(t); // convert token* to operator* so we can use getOp()
            if (!operators.empty()){
                // make sure you actually have something in your stack
                topOfStack = operators.top();
                if(debug)cout<<"queue is not empty. setting topOp!";
                topOp = static_cast<Operator*>(topOfStack);
                if(debug)cout<<". top of stack is: "<<topOp->getOp()<<endl;

            }
            if(op->getOp() == ','){
                // ignore commas
            }
            else{
                if(op->getOp() == '('){
                    // if left paren, push to stack
                    if(debug)cout << "left parentheses found" << endl;
                    operators.push(t);
                }
                else if(op->getOp() == ')'){
                    // if right paren
                    if(debug)cout << "right parentheses found" << endl;
                    while (!operators.empty() && static_cast<Operator*>(operators.top())->getOp() != '('){
    //                while(topOp->getOp() != '('){
                        // while there isn't a left parentheses at the top of the stack,
                        // pop off stack and push onto queue
                        if(debug){
                            cout << "TEST saw open paren: popping stack, pushing to queue" << endl
                                 << "stack: " << operators << endl
                                 << "queue: " << postfixExpression << endl;
                        }
                        postfixExpression.push(operators.pop());
                    }
                    // pop left parentheses off stack

                    if(debug)cout<<"popping the open paren: ";
                    static_cast<Operator*>(operators.pop())->getOp();
                    cout<<endl;
                }
                else{
                    while(!operators.empty() && topOp->getOp() != '(' && t->precedence() <= operators.top()->precedence()){
                        // while the stack is not empty, and
                        // the top of the stack is not (, and
                        // the top of the stack has higher precedence,
                        // keep popping stuff off the stack and
                        // pushing onto the queue
                        postfixExpression.push(operators.pop());
                        }

                    operators.push(t); // push t onto operator stack
                }
            }


            break;
        case 2:
            // operand
            // push to output queue
            if(debug)cout<<"shunting yard: OPERAND"<<endl;
            postfixExpression.push(t);
            if(debug){
                cout << "shuntingYard::infixToPostfix: Pushing operand to queue" << endl;
            }
            break;
        case 3:
            // variable
            if(debug)cout << "shunting yard: VARIABLE"<<endl;
            postfixExpression.push(t);
            if(debug){
                cout << "shuntingYard::infixToPostfix: Pushing variable to queue" << endl;
            }
            break;
        case 4:
            // function
            if(debug)cout << "shunting yard: FUNCTION"<<endl;
            operators.push(t);
            break;
        }

        if(debug){
            cout << "queue: " << postfixExpression << endl
                 << "stack: " << operators << endl;
        }   // END OF DEBUG STATEMENT
    } // END OF WHILE LOOP

    while(!operators.empty()){
        // once you've emptied your infix queue,
        // push operators to output queue
        Token* op = operators.pop();
        postfixExpression.push(op);
        if(debug){
            cout << "Popping " << op << " off stack" << endl
                 << "Pushing " << op << " onto output queue"
                 << endl;
        } // END OF DEBUG STATEMENT
    } // END OF WHILE LOOP
//    cout<<"- - - - - - - - - - - - - - - - - "<<endl;
//    cout<<postfixExpression<<endl;
//    cout<<"- - - - - - - - - - - - - - - - - "<<endl;
    return postfixExpression;
}
