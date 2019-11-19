//
// Created by Guglielmo Menchetti on 27/11/2018.
//

#ifndef HW5_IDTOCONSTEXPRESSION_H
#define HW5_IDTOCONSTEXPRESSION_H

#include "Expression.h"

class IdToConstExpression : Expression {
public:
    IdToConstExpression(RegisterCounter& rc, std::string& o, std::string& re, std::string& l, double val);
    void execute();
    std::string getInstructionText();

private:
    std::string op;
    std::string receiver;
    std::string left;
    double value;
};


#endif //HW5_IDTOCONSTEXPRESSION_H
