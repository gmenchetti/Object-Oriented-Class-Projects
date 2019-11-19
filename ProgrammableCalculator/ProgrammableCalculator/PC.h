//
// Created by Guglielmo Menchetti on 27/11/2018.
//

#ifndef HW5_PC_H
#define HW5_PC_H

#include <vector>
#include <iostream>
#include "../Expressions/Expression.h"
#include "RegisterCounter.h"

class PC {

public:
    PC();
    ~PC();
    void initialize();
    void initializeRC();
    void executeAll();
    void executeContinue();
    void executeCurrent();
    void printAll();
    void printRegisters();
    void printNextIndex();

    inline void addExpression(Expression* ex) { expressions.push_back(ex); }
    inline RegisterCounter& getRegisterCounter() { return rc; }

private:
    RegisterCounter rc;
    std::vector<Expression*> expressions;
};


#endif //HW5_PC_H
