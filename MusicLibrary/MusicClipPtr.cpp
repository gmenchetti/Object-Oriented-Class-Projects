//
// Created by Guglielmo Menchetti on 14/11/2018.
//

#include "MusicClipPtr.h"

MusicClipPtr::MusicClipPtr(int index) {
    this->index = index;
    this->mMusicClip = nullptr;
}

MusicClipPtr::MusicClipPtr(const MusicClip& mc) {
    this->index = mc.getIndex();
    this->mMusicClip = new MusicClip(mc.getId(), mc.getIndex(), mc.getArtist(), mc.getPeople(),
            mc.getTitle(), mc.getGenre(), mc.getClip(), mc.getPrice());
}

MusicClipPtr::~MusicClipPtr() {
    MusicClip *toDelete = mMusicClip;
    inMemory = false;
    mMusicClip = nullptr;
    if(mMusicClip != nullptr) {
        delete(toDelete);
    }
}

void MusicClipPtr::saveToFile(std::string path) {
    std::string fileName;
    if(path != "../clips/") {
        fileName = "../temp.clip.txt";
    }
    else {
        fileName = path + std::to_string(this->index) + ".txt";
    }
    std::ofstream newFile;
    newFile.open(fileName);
    if(newFile.is_open()) {
        newFile << "id:" << std::to_string(mMusicClip->getId()) << ";\n";
        newFile << "index:" << std::to_string(mMusicClip->getIndex()) << ";\n";
        newFile << "artist:" << mMusicClip->getArtist() << ";\n";
        newFile << "genre:" << std::to_string(genreToInt(mMusicClip->getGenre())) << ";\n";
        std::string tmp;
        std::vector<std::string> peopleVec = mMusicClip->getPeople();
        if(!peopleVec.empty()) {
            tmp += peopleVec.at(0);
            for(unsigned int i = 1; i < (peopleVec.size()); ++i) {
                tmp += ",";
                tmp += peopleVec.at(i);
            }
        }
        newFile << "people:" << tmp << ";\n";
        newFile << "title:" << mMusicClip->getTitle() << ";\n";
        newFile << "clip:" << mMusicClip->getClip() << ";\n";
        newFile << "price:" << std::to_string(mMusicClip->getPrice()) << ";\n";
        std::cout << "Clip " << std::to_string(mMusicClip->getId()) << " correctly saved" << std::endl;
    }
    else {
        std::cout << "Unable to open file";
    }
}

void MusicClipPtr::loadFromFile() {
    std::string fileName = "../clips/" + std::to_string(this->index) + ".txt";
    Parser p = Parser(fileName);
    if(!p.isEmpty()) {
        int id = p.getId();
        int index = p.getIndex();
        std::string artist = p.getArtist();
        MusicClip::genre g = intToGenre(p.getGenre());
        std::vector<std::string> people = p.getPeople();
        std::string title = p.getTitle();
        std::string clip = p.getClip();
        float price = p.getPrice();
        createNewClip(id, index, artist, people, title, g, clip, price);
    }
    else {
        mMusicClip = nullptr;
    }
}

void MusicClipPtr::createNewClip(int id, int index, std::string artist, std::vector<std::string> people,
                                  std::string title, MusicClip::genre genre, std::string clip, float price) {
    MusicClip *mc = new MusicClip(id, index, artist, people, title, genre, clip, price);
    mMusicClip = mc;
    inMemory = true;
}

MusicClip& MusicClipPtr::operator*() {
    if(mMusicClip == nullptr) {
        loadFromFile();
    }
    return *mMusicClip;
}

MusicClip* MusicClipPtr::operator->() {
    if(mMusicClip == nullptr) {
        loadFromFile();
    }
    return mMusicClip;
}

MusicClip::genre MusicClipPtr::intToGenre(int i) {
    switch(i) {
        case 0:
            return MusicClip::genre::POP_MUSIC;
        case 1:
            return MusicClip::genre::FOLK_MUSIC;
        case 2:
            return MusicClip::genre::JAZZ;
        case 3:
            return MusicClip::genre::BLUES;
        case 4:
            return MusicClip::genre::CLASSICAL;
        case 5:
            return MusicClip::genre::OPERA;
        case 6:
            return MusicClip::genre::COUNTRY_MUSIC;
        case 7:
            return MusicClip::genre::REGGAE;
        case 8:
            return MusicClip::genre::ROCK;
        default:
            return MusicClip::genre::POP_MUSIC;
    }
}

int MusicClipPtr::genreToInt(MusicClip::genre g) {
    switch(g) {
        case MusicClip::genre::POP_MUSIC:
            return 0;
        case MusicClip::genre::FOLK_MUSIC:
            return 1;
        case MusicClip::genre::JAZZ:
            return 2;
        case MusicClip::genre::BLUES:
            return 3;
        case MusicClip::genre::CLASSICAL:
            return 4;
        case MusicClip::genre::OPERA:
            return 5;
        case MusicClip::genre::COUNTRY_MUSIC:
            return 6;
        case MusicClip::genre::REGGAE:
            return 7;
        case MusicClip::genre::ROCK:
            return 8;
        default:
            return 0;
    }
}

std::string MusicClipPtr::intToGenreString(int i){
    switch(i) {
        case 0:
            return "POP_MUSIC";
        case 1:
            return "FOLK_MUSIC";
        case 2:
            return "JAZZ";
        case 3:
            return "BLUES";
        case 4:
            return "CLASSICAL";
        case 5:
            return "OPERA";
        case 6:
            return "COUNTRY_MUSIC";
        case 7:
            return "REGGAE";
        case 8:
            return "ROCK";
        default:
            return "POP_MUSIC";
    }
}
bool MusicClipPtr::getInMemory() const {
    return inMemory;
}

MusicClip* MusicClipPtr::getClip() const {
    return mMusicClip;
}

int MusicClipPtr::getIndex(){
    return index;
}

void MusicClipPtr::deleteClip() {
    MusicClip *toDelete = mMusicClip;
    if(mMusicClip != nullptr) {
        delete(toDelete);
    }
    inMemory = false;
    mMusicClip = nullptr;
}

bool MusicClipPtr::inFile() {
    std::string fileName = "../clips/" + std::to_string(this->index) + ".txt";
    Parser p = Parser(fileName);
    if(!p.isEmpty()) {
        return true;
    }
    else {
        return false;
    }
}
