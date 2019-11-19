//
// Created by Guglielmo Menchetti on 2018-11-29.
//

#ifndef HW5_CONTINUECOMMAND_H
#define HW5_CONTINUECOMMAND_H

#include "Command.h"

class ContinueCommand : Command{
public:
    ContinueCommand(PC& pc);
    void execute();
};


#endif //HW5_CONTINUECOMMAND_H
