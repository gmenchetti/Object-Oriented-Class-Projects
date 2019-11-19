//
// Created by Guglielmo Menchetti on 26/11/2018.
//

#include "CommandLineInterface.h"

CommandLineInterface::CommandLineInterface() {
    pc = PC();
    start();
}

void CommandLineInterface::start() {
    cout << "WELCOME TO THE PROGRAMMABLE CALCULATOR" << endl;
    cout << "Press:" << endl;
    cout << "     i filename.txt" << endl;
    bool cont = true;
    string action = "";
    while(cont) {
        cout << "Insert command: ";
        std::getline (std::cin, action);
        if(action[0] == 'i' and action[1] == ' ') {
            std::string filename;
            for(unsigned int i = 1; i < action.length(); i++) {
                if(action[i] == ' ') {
                    continue;
                }
                else {

                    filename = action.substr(i);
                    break;
                }
            }
            ReadFileCommand rf = ReadFileCommand(pc, filename);
            rf.execute();
        }
        else if(action == "d") {
            DebugCommand dc = DebugCommand(pc);
            dc.execute();
        }
        else if(action == "r") {
            RunCommand rc = RunCommand(pc);
            rc.execute();
        }
        else if(action == "c") {
            ContinueCommand cc = ContinueCommand(pc);
            cc.execute();
        }
        else if(action == "p") {
            PrintCommand pr = PrintCommand(pc);
            pr.execute();
        }
        else if(action == "q") {
            cout << "PROGRAMMABLE CALCULATOR QUIT" << endl;
            break;
        }
        else {
            cout << "Command not valid" << endl;
        }
        cout << "\n";
    }

}