//
// Created by Guglielmo Menchetti on 27/11/2018.
//

#include "AssignmentExpression.h"

AssignmentExpression::AssignmentExpression
(RegisterCounter& rc, std::string& rec, double val) : Expression(rc) {
    value = val;
    receiver = rec;
}

void AssignmentExpression::execute() {
    Register& r = getRegister(receiver);
    r.setValue(value);
}

std::string AssignmentExpression::getInstructionText() {
    return receiver + " = " + std::to_string(value);
}