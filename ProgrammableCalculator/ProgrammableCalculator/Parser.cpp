//
// Created by Guglielmo Menchetti on 2018-11-28.
//

#include "Parser.h"

Parser::Parser(PC& p, string fn) : pc(p) {
    parseFile(fn);
}

void Parser::parseFile(string fn) {
    string path = "../InstructionFiles/" + fn;
    ifstream f(path);


    if(!f or fn == "") {
        cout << "Unable to open file" << endl;
    }
    else {
        char str[50];
        while(f) {
            f.getline(str, 50);
            if(f) {
                parseRow(str);
            }
        }
        cout << "Instructions loaded" << endl;
        f.close();
    }
}

bool Parser::parseRow(const std::string &str) {
    std::smatch match;
    std::regex_match(str, match, assignmentRE);
    if(!match.empty()) {
        std::string re = string(match[1]);
        double val = stod(match[2]);
        AssignmentExpression* ex = new AssignmentExpression(pc.getRegisterCounter(), re, val);
        pc.addExpression((Expression*) ex);
        return true;
    }
    std::regex_match(str, match, conditionalRE);
    if(!match.empty()) {
        std::string rec = string(match[1]).c_str();
        int line = stoi(match[2]);
        ConditionalEpression* ex = new ConditionalEpression(pc.getRegisterCounter(), rec, line);
        pc.addExpression((Expression*) ex);
        return true;
    }
    std::regex_match(str, match, idToIdRE);
    if(!match.empty()) {
        std::string re = string(match[1]).c_str();
        std::string l = string(match[2]).c_str();
        std::string op = string(match[3]);
        std::string r = string(match[4]).c_str();
        IdToIdExpression* ex = new IdToIdExpression(pc.getRegisterCounter(), op, re, l, r);
        pc.addExpression((Expression*) ex);
        return true;
    }
    std::regex_match(str, match, idToConstRE);
    if(!match.empty()) {
        std::string re = string(match[1]).c_str();
        std::string l = string(match[2]).c_str();
        std::string op = string(match[3]);
        double val = stod(match[4]);
        IdToConstExpression* ex = new IdToConstExpression(pc.getRegisterCounter(), op, re, l, val);
        pc.addExpression((Expression*) ex);
        return true;
    }
    return false;
}
