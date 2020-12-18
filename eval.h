#ifndef EVAL_H
#define EVAL_H

#include "../../!includes/Token/token.h"
#include "../../!includes/Operand/operand.h"
#include "../../!includes/Operator/operator.h"
#include "../../!includes/Queue/queue.h"
#include "../../!includes/Stack/stack.h"
#include "../../!includes/Variable/variable.h"
#include "../../!includes/shuntingYard/shuntingyard.h"

double eval(Queue<Token*> postfix);
double eval(Queue<Token*> postfix, double var);

#endif // EVAL_H
