//
// Created by Guglielmo Menchetti on 2018-11-28.
//

#include "ReadFileCommand.h"

ReadFileCommand::ReadFileCommand(PC &p, std::string fn) : Command(p) {
    filename = fn;
    pc.initialize();
}

void ReadFileCommand::execute() {
    Parser parser = Parser(pc, filename);
    pc.printAll();
}