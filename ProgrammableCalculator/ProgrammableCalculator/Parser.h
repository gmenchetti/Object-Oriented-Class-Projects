//
// Created by Guglielmo Menchetti on 2018-11-28.
//

#ifndef HW5_PARSER_H
#define HW5_PARSER_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <regex>

#include "PC.h"
#include "../Expressions/IdToIdExpression.h"
#include "../Expressions/IdToConstExpression.h"
#include "../Expressions/AssignmentExpression.h"
#include "../Expressions/ConditionalEpression.h"

using namespace std;

class Parser {
public:
    Parser(PC& p, string fn);

private:
    PC& pc;
    const regex assignmentRE =
            regex("(x|y|z|w)(?: *)=(?: *)([0-9]*((\\.)[0-9]*)?)(?: *)(\\.)(?: *)");
    const regex conditionalRE =
            regex("(x|y|z|w)(?: *)\\?(?: *)([0-9]*)(?: *)(\\.)(?: *)");
    const regex idToIdRE =
            regex("(x|y|z|w)(?: *)=(?: *)(x|y|z|w)(?: *)(\\*|\\*\\*|\\+|\\-)(?: *)(x|y|z|w)(?: *)(\\.)(?: *)");
    const regex idToConstRE =
            regex("(x|y|z|w)(?: *)=(?: *)(x|y|z|w)(?: *)(\\*|\\*\\*|\\+|\\-)(?: *)([0-9]*((\\.)[0-9]*)?)(?: *)(\\.)(?: *)");

    void parseFile(string fn);
    bool parseRow(const string &str);
};


#endif //HW5_PARSER_H
