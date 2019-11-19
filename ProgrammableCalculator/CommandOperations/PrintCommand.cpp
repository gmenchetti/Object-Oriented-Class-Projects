//
// Created by Guglielmo Menchetti on 2018-11-29.
//

#include "PrintCommand.h"

PrintCommand::PrintCommand(PC &p) : Command(p) { }

void PrintCommand::execute() {
    pc.printAll();
    pc.printRegisters();
}