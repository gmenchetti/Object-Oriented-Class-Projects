//
// Created by Guglielmo Menchetti on 2018-11-29.
//

#ifndef HW5_DEBUGCOMMAND_H
#define HW5_DEBUGCOMMAND_H

#include "Command.h"
#include "../ProgrammableCalculator/PC.h"

class DebugCommand : Command {
public:
    DebugCommand(PC& p);
    void execute();
};


#endif //HW5_DEBUGCOMMAND_H
