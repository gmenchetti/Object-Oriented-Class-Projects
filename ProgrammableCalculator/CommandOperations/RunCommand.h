//
// Created by Guglielmo Menchetti on 2018-11-29.
//

#ifndef HW5_RUNCOMMAND_H
#define HW5_RUNCOMMAND_H

#include "Command.h"

class RunCommand : Command {
public:
    RunCommand(PC& p);
    void execute();
};


#endif //HW5_RUNCOMMAND_H
