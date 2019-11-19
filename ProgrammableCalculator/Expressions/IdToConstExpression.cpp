//
// Created by Guglielmo Menchetti on 27/11/2018.
//

#include "IdToConstExpression.h"

IdToConstExpression::IdToConstExpression(RegisterCounter& rc, std::string& o, std::string& re, std::string& l, double val) :
Expression(rc) {
    op = o;
    receiver = re;
    left = l;
    value = val;
}

void IdToConstExpression::execute() {
    Register& re = getRegister(receiver);
    Register& l = getRegister(left);
    double toAssign = operation(l.getValue(), value, op);
    re.setValue(toAssign);
}

std::string IdToConstExpression::getInstructionText() {
    return receiver + " = " + left + " " + op + " " + std::to_string(value);
}
