//
// Created by Guglielmo Menchetti on 17/11/2018.
//

#ifndef HW4_MODEL_H
#define HW4_MODEL_H

#include "LinkedList.h"
#include <stdio.h>

class Model {
public:
    Model(int nSongs);
    ~Model();

    void listSongs();
    void edit(int index);
    void saveClips();
    void createNewClip();
    void deepCopy();
    void changePrice(float newPrice);
    void printSong(MusicClipPtr *mptr);
    void readFromFile();
    int execute(std::string inst);
private:
    int numberOfSongs;
    int activePointers[3] = {-1, -1, -1};
    MusicClipPtr* currentMusicPtr;
    LinkedList songList;
    MusicClipPtr* getPointer(int index);
    void removeCurrentFiles();
    std::string parseSingleString(std::string oldString);
    std::vector<std::string> parsePeople(std::string oldString);
};

#endif //HW4_MODEL_H
