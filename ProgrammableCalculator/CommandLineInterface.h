//
// Created by Guglielmo Menchetti on 26/11/2018.
//

#ifndef HW5_USERINTERFACE_H
#define HW5_USERINTERFACE_H

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include "ProgrammableCalculator/PC.h"
#include "CommandOperations/ReadFileCommand.h"
#include "CommandOperations/DebugCommand.h"
#include "CommandOperations/RunCommand.h"
#include "CommandOperations/ContinueCommand.h"
#include "CommandOperations/PrintCommand.h"

using namespace std;

class CommandLineInterface {
public:
    CommandLineInterface();
private:
    PC pc;

    void start();
};


#endif //HW5_USERINTERFACE_H
