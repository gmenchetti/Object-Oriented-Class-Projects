//
// Created by Guglielmo Menchetti on 27/11/2018.
//

#include "IdToIdExpression.h"

IdToIdExpression::IdToIdExpression(RegisterCounter& rc, std::string& o, std::string& re,
                                   std::string& l, std::string& r) : Expression(rc) {
    op = o;
    receiver = re;
    left = l;
    right = r;
}

void IdToIdExpression::execute() {
    Register& re = getRegister(receiver);
    Register& l = getRegister(left);
    Register& r = getRegister(right);
    double toAssign = operation(l.getValue(), r.getValue(), op);
    re.setValue(toAssign);
}

std::string IdToIdExpression::getInstructionText() {
    return receiver + " = " +  left + " " + op + " " + right;
}