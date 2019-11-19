//
// Created by Guglielmo Menchetti on 16/11/2018.
//

#include "Parser.h"
#include "MusicClip.h"

Parser::Parser(std::string fileName) {
    parseText(fileName);
}

Parser::~Parser() {}

void Parser::parseText(std::string fileName) {
    std::string line;
    std::ifstream myfile(fileName);
    std::vector<std::string> vec;
    if (myfile.is_open())
    {
        while(getline(myfile,line)) {
            std::string v;
            char ch = line[0];
            unsigned int i = 0;
            while (ch != ':') {
                i++;
                ch = line[i];
            }
            i++;
            ch = line[i];
            while (ch != ';') {
                v += ch;
                i++;
                ch = line[i];
            }
            vec.push_back(v);
        }
        parsedText = vec;
        myfile.close();
    }
    else{
        std::cout << "Unable to open file: ";
        parsedText = vec;
    }
}
bool Parser::isEmpty() {
    return parsedText.empty();
}

int Parser::getId() {
    return std::stoi(parsedText.at(0));
}
int Parser::getIndex() {
    return std::stoi(parsedText.at(1));
}
std::string Parser::getArtist() {
    return parsedText.at(2);
}
int Parser::getGenre() {
    return std::stoi(parsedText.at(3));
}

std::vector<std::string> Parser::getPeople() {
    std::string values = parsedText.at(4);
    std::vector<std::string> people;
    unsigned int i = 0;
    while( i < values.length() ) {
        std::string str;
        while( (values[i] != ',') and (values[i] != '\0')) {
            str += values[i];
            i++;
        }
        i++;
        people.push_back(str);
    }
    return people;
}
std::string Parser::getTitle() {
    return parsedText.at(5);
}

std::string Parser::getClip() {
    return parsedText.at(6);
}

float Parser::getPrice() {
    return std::stof(parsedText.at(7));
}