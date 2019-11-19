//
// Created by Guglielmo Menchetti on 2018-11-29.
//

#include "RunCommand.h"

RunCommand::RunCommand(PC &p) : Command(p) {}

void RunCommand::execute() {
    pc.executeAll();
    pc.printRegisters();
}