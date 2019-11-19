//
// Created by Guglielmo Menchetti on 26/11/2018.
//

#ifndef HW5_COMMAND_H
#define HW5_COMMAND_H

#include "../ProgrammableCalculator/PC.h"

class Command {
public:
    virtual void execute() = 0;

protected:
    Command(PC& p) : pc(p) {}
    PC& pc;
};


#endif //HW5_COMMAND_H
