//
// Created by Guglielmo Menchetti on 27/11/2018.
//

#ifndef HW5_IDTOIDEXPRESSION_H
#define HW5_IDTOIDEXPRESSION_H

#include "Expression.h"
#include <string>

class IdToIdExpression : Expression {
public:
    IdToIdExpression(RegisterCounter& rc, std::string& o, std::string& re, std::string& l, std::string& r);
    void execute();
    std::string getInstructionText();

private:
    std::string op;
    std::string receiver;
    std::string left;
    std::string right;
};


#endif //HW5_IDTOIDEXPRESSION_H
