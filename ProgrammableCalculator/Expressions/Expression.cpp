//
// Created by Guglielmo Menchetti on 27/11/2018.
//
#include "Expression.h"

Expression::Expression(RegisterCounter& r) : rc(r) { };


Register& Expression::getRegister(std::string s) {
    if(s == "x") {
        return rc.getX();
    }
    else if(s == "y") {
        return rc.getY();
    }
    else if(s == "w") {
        return rc.getW();
    }
    else if(s == "z") {
        return rc.getZ();
    }
    else {
        throw "Wrong access to registers";
    }
}

double Expression::operation(double l, double r, std::string op) {
    if (op == "+") {
        return l+r;
    }
    else if(op == "*") {
        return l*r;
    }
    else if(op == "**") {
        return pow(l, r);
    }
    else if(op == "-") {
        return l - r;
    }
    else {
        throw "Invalid operation";
    }
}