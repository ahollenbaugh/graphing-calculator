#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include "../../!includes/Token/token.h"
#include "../../!includes/Operand/operand.h"
#include "../../!includes/Operator/operator.h"
#include "../../!includes/Queue/queue.h"
#include "../../!includes/Stack/stack.h"
#include "../../!includes/Variable/variable.h"
#include "../../!includes/Function/function.h"

Queue<Token*> infixToPostfix(Queue<Token*> infixExpression);

#endif // SHUNTINGYARD_H
