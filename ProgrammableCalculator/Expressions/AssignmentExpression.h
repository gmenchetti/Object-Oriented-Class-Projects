//
// Created by Guglielmo Menchetti on 27/11/2018.
//

#ifndef HW5_ASSIGNMENTEXPRESSION_H
#define HW5_ASSIGNMENTEXPRESSION_H

#include "Expression.h"

class AssignmentExpression : Expression {

public:
    AssignmentExpression(RegisterCounter& rc, std::string& rec, double val);
    void execute();
    std::string getInstructionText();

private:
    std::string receiver;
    double value;
};


#endif //HW5_ASSIGNMENTEXPRESSION_H
