//
// Created by Guglielmo Menchetti on 2018-11-28.
//

#ifndef HW5_READFILECOMMAND_H
#define HW5_READFILECOMMAND_H

#include "Command.h"
#include "../ProgrammableCalculator/Parser.h"

class ReadFileCommand : Command {
public:
    ReadFileCommand(PC& p, std::string fn);
    void execute();

private:
    std::string filename;
};


#endif //HW5_READFILECOMMAND_H
