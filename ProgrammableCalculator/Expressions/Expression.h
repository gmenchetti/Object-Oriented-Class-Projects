//
// Created by Guglielmo Menchetti on 27/11/2018.
//

#ifndef HW5_EXPRESSION_H
#define HW5_EXPRESSION_H

#include <vector>
#include <string>
#include <cmath>

#include "../ProgrammableCalculator/RegisterCounter.h"
#include "../ProgrammableCalculator/Register.h"

class Expression {

public:
    virtual void execute() = 0;
    virtual std::string getInstructionText() = 0;
    virtual ~Expression() = default;

protected:
    RegisterCounter& rc;

    Expression(RegisterCounter& rc);
    Register& getRegister(std::string c);
    double operation(double l, double r, std::string op);
};


#endif //HW5_EXPRESSION_H
