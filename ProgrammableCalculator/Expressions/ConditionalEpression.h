//
// Created by Guglielmo Menchetti on 27/11/2018.
//

#ifndef HW5_CONDITIONALEPRESSION_H
#define HW5_CONDITIONALEPRESSION_H

#include "Expression.h"

class ConditionalEpression : Expression {
public:
    ConditionalEpression(RegisterCounter& rc, std::string& r, int newL);
    void execute();
    std::string getInstructionText();

private:
    std::string receiver;
    int newLine;
};


#endif //HW5_CONDITIONALEPRESSION_H
