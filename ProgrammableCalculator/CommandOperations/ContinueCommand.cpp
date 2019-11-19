//
// Created by Guglielmo Menchetti on 2018-11-29.
//

#include "ContinueCommand.h"

ContinueCommand::ContinueCommand(PC &p) : Command(p) { }

void ContinueCommand::execute() {
    pc.executeContinue();
    pc.printRegisters();
}