//
// Created by Guglielmo Menchetti on 16/11/2018.
//

#ifndef HW4_PARSER_H
#define HW4_PARSER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Parser {
private:
    std::vector<std::string> parsedText;
    void parseText(std::string fileName);
public:
    Parser(std::string fileName);
    ~Parser();
    bool isEmpty();

    int getId();
    int getIndex();
    std::string getArtist();
    int getGenre();
    std::vector<std::string> getPeople();
    std::string getTitle();
    std::string getClip();
    float getPrice();

};


#endif //HW4_PARSER_H
