//
// Created by Guglielmo Menchetti on 27/11/2018.
//

#include "PC.h"

PC::PC() : rc() {}

PC::~PC() {
    for(unsigned int i = 0; i < expressions.size(); i++) {
        delete(expressions.at(i));
    }
}

void PC::initialize() {
    if(!expressions.empty()) {
        for(unsigned int i = 0; i < expressions.size(); i++) {
            delete(expressions.at(i));
        }
        expressions.clear();
    }
    initializeRC();
}

void PC::initializeRC() {
    rc.resetExecuted();
    rc.resetCurrent();
    rc.resetRegisters();
}

void PC::executeAll(){
    if(!expressions.empty()) {
        rc.resetExecuted();
        while( rc.getCurrentInstruction() < expressions.size() and rc.getExecuted() < 100 ) {
            executeCurrent();
        }
        if(rc.getCurrentInstruction() == expressions.size()) {
            std::cout << "\nProgram terminated" << std::endl;
        }
        else if(rc.getExecuted() == 100) {
            std::cout << "\nProgram halted: 100 instructions executed" << std::endl;
        }
    }
    else {
        std::cout << "\nNo instructions loaded" << std::endl;
    }
}

void PC::executeContinue() {
    if(!expressions.empty()) {
        if(rc.getExecuted() >= 100) {
            executeAll();
        }
        else if(rc.getCurrentInstruction() < expressions.size()) {
            std::cout << "\nRun first" << std::endl;
        }
        else {
            std::cout << "\nProgram terminated" << std::endl;
        }
    }
    else {
        std::cout << "\nNo instructions loaded" << std::endl;
    }
}

void PC::executeCurrent() {
    if(!expressions.empty()) {
        if(rc.getCurrentInstruction() < expressions.size()) {
            expressions.at(rc.getCurrentInstruction())->execute();
            rc.incrementCurrent();
            rc.incrementExecuted();
        }
        else {
            std::cout << "\nProgram terminated" << std::endl;
        }
    }
    else {
        std::cout << "\nNo instruction loaded" << std::endl;
    }
}

void PC::printAll() {
    if(!expressions.empty()) {
        std::cout << "\nInstructions" << std::endl;
        for(unsigned int i = 0; i < expressions.size(); i++) {
            std::cout << std::to_string(i+1) << ": " << expressions.at(i)->getInstructionText() << std::endl;
        }
    }
    else {
        std::cout << "\nNo instructions loaded" << std::endl;
    }
}

void PC::printRegisters() {
    std::cout << "\nRegisters value" << std::endl;
    std::cout << "x: " << rc.getX().getValue() << ", y: " << rc.getY().getValue() << ", w: " << rc.getW().getValue() << ", z: " << rc.getZ().getValue() << std::endl;
}

void PC::printNextIndex() {
    if(rc.getCurrentInstruction() >= expressions.size()) {
        std::cout << "\nNext instruction index: none" << std::endl;
    }
    else {
        std::cout << "\nNext instruction index: " << rc.getCurrentInstruction() + 1 << std::endl;
    }
}
