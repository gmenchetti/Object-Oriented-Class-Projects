//
// Created by Guglielmo Menchetti on 27/11/2018.
//

#include "ConditionalEpression.h"

ConditionalEpression::ConditionalEpression(RegisterCounter& rc, std::string& rec, int newL) :
Expression(rc) {
    receiver = rec;
    newLine = newL;
}

void ConditionalEpression::execute() {
    Register& r = getRegister(receiver);
    if(r.getValue() != 0) {
        rc.setCurrentInstruction(newLine - 2);
    }
}

std::string ConditionalEpression::getInstructionText() {
    return receiver + " ? " + std::to_string(newLine);
}
