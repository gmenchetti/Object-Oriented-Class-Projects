//
// Created by Guglielmo Menchetti on 2018-11-29.
//

#include "DebugCommand.h"

DebugCommand::DebugCommand(PC &p) : Command(p) { }

void DebugCommand::execute() {
    pc.executeCurrent();
    pc.printRegisters();
    pc.printNextIndex();
}