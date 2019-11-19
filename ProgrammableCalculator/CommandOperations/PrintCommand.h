//
// Created by Guglielmo Menchetti on 2018-11-29.
//

#ifndef HW5_PRINTCOMMAND_H
#define HW5_PRINTCOMMAND_H

#include "Command.h"

class PrintCommand : Command {
public:
    PrintCommand(PC& p);
    void execute();
};


#endif //HW5_PRINTCOMMAND_H
