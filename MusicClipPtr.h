//
// Created by Guglielmo Menchetti on 14/11/2018.
//
#ifndef MUSIC_CLIP_PTR
#define MUSIC_CLIP_PTR

#include "MusicClip.h"
#include <vector>
#include "Parser.h"

class MusicClipPtr {

public:
    MusicClipPtr(int index);

    MusicClipPtr(const MusicClip& mc);

    ~MusicClipPtr(); // Destructor should delete MusicClip instance as well

    bool getInMemory() const;

    MusicClip* getClip() const;

    void createNewClip(int id, int index, std::string artist, std::vector<std::string> people,
                        std::string title, MusicClip::genre genre, std::string clip, float price);

    void saveToFile(std::string path = "../clips/");

    void loadFromFile();

    void deleteClip();

    bool inFile();

    int getIndex();

    std::string intToGenreString(int i);

    MusicClip::genre intToGenre(int i);

    int genreToInt(MusicClip::genre g);

    MusicClip& operator*();

    MusicClip* operator->();

private:

    int index;

    bool inMemory;

    MusicClip *mMusicClip;

    MusicClipPtr(const MusicClipPtr& mptr);

    MusicClipPtr &operator=(const MusicClipPtr &);

    // TODO: Other auxiliary functions to manage MusicClip instances
};

#endif
