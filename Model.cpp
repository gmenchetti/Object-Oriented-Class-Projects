//
// Created by Guglielmo Menchetti on 17/11/2018.
//

#include "Model.h"

Model::Model(int nSongs) {
    numberOfSongs = nSongs;
    for(unsigned int i = 0; i < nSongs; i++) {
        songList.insertLast();
    }
    currentMusicPtr = nullptr;
}

Model::~Model() {}

MusicClipPtr* Model::getPointer(int index) {
    if( (index > numberOfSongs) or (index < 0)) {
        return nullptr;
    }
    else {
        MusicClipPtr *mptr = songList.getMusicPtr(index);
        if(mptr != nullptr) {
            if(!mptr->getInMemory()) {
                if(activePointers[2] != -1) {
                    songList.removeFromMemory(activePointers[0]);
                    activePointers[0] = activePointers[1];
                    activePointers[1] = activePointers[2];
                    activePointers[2] = index;
                }
                else if(activePointers[0] == -1) {
                    activePointers[0] = index;
                }
                else if(activePointers[1] == -1) {
                    activePointers[1] = index;
                }
                else {
                    activePointers[2] = index;
                }
            }
            return mptr;
        }
        else {
            return nullptr;
        }
    }
}

void Model::removeCurrentFiles() {
    for(int i = 0; i < (sizeof(activePointers)/ sizeof(activePointers[0])); ++i) {
        if(activePointers[i] != -1 ) {
            std::string filename = "../clips/";
            filename += std::to_string(activePointers[i]);
            filename += ".txt";
            if(std::remove(filename.c_str()) == 0) {
                std::cout << "File "<< activePointers[i] << " correctly deleted\n";
            }
        }
    }
}

void Model::listSongs() {
    std::cout << "---------------Available songs---------------" << std::endl;
    for (int i = 0; i < numberOfSongs; ++i) {
        MusicClipPtr *mptr = getPointer(i);
        if(mptr->inFile()) {
            printSong(mptr);
        }
        else {
            std::cout << "no file is present with ID " << i << std::endl;
        }
    }
}

void Model::edit(int index) {
    std::cout << "---------------Edit current clip-------------" << std::endl;
    MusicClipPtr *ptr = getPointer(index);
    if(ptr != nullptr) {
        currentMusicPtr = ptr;
        currentMusicPtr->loadFromFile();
        std::cout << "Current clip modified\n" << std::endl;
    }
    else {
        std::cout << "Error in modifying current clip: index not valid" << std::endl;
    }
}

void Model::saveClips() {
    std::cout << "---------------Saving active clips-------------" << std::endl;
    if(activePointers[0] == -1) {
        std::cout << "Nothing to save" << std::endl;
    }
    else {
        removeCurrentFiles();
        for(unsigned int i = 0; i < (sizeof(activePointers)/ sizeof(activePointers[0])); ++i) {
            int indexToSave = activePointers[i];
            if(indexToSave != -1) {
                MusicClipPtr *tmp = getPointer(indexToSave);
                tmp->saveToFile();
            }
        }
    }
}

void Model::createNewClip() {
    std::cout << "---------------Creating new clip--------------" << std::endl;
    int id;
    int index;
    std::string dummy;
    std::string artist;
    int genre;
    std::vector<std::string> people;
    std::string title;
    std::string clip = "";
    float price;

    bool valid = false;
    while( valid == false ) {
        std::cout << "Insert ID: " << std::endl;
        std::cin >> id;
        if(id > 10 or id < 0) {
            std::cout << "Invalid id: must be between 0 and 9" << std::endl;
        }
        else {
            valid = true;
        }
    }
    std::cout << "Insert index: ";
    std::cin >> index;
    std::getline(std::cin, dummy);
    std::cout << "Insert title: ";
    std::getline(std::cin, title);
    valid = false;
    while(valid == false) {
        std::cout << "Insert genre (0 = POP MUSIC, 1 = FOLK MUSIC, 2 = JAZZ, 3 = BLUES, 4 = CLASSICAL, "
                     "5 = OPERA, 6 = COUNTRY MUSIC, 7 = REGGAE, 8 = ROCK): ";
        std::cin >> genre;
        std::getline(std::cin, dummy);
        if(genre > 8 or genre < 0) {
            std::cout << "Invalid genre: must be between 0 and 9" << std::endl;
        }
        else {
            valid = true;
        }
    }
    std::cout << "Insert artist name: ";
    std::getline(std::cin, artist);
    bool empty = false;
    while(empty == false) {
        std::cout << "Insert component name (empty when finish): ";
        std::string tmp;
        std::getline(std::cin, tmp);
        if(tmp.empty()) {
            empty = true;
        }
        else {
            people.push_back(tmp);
        }
    }
    std::cout << "Insert price: ";
    std::cin >> price;

    MusicClipPtr *mpt = songList.getMusicPtr(id);
    mpt->createNewClip(id, index, artist, people, title, mpt->intToGenre(genre), "", price);
    mpt->saveToFile();
}

void Model::deepCopy() {
    std::cout << "-------------Copying current clip-------------" << std::endl;
    if(currentMusicPtr != nullptr) {
        edit(currentMusicPtr->getIndex());
        if(currentMusicPtr->getClip() != nullptr) {
            MusicClipPtr *temporaryPtr = new MusicClipPtr(*(currentMusicPtr->getClip()));
            temporaryPtr->saveToFile("../temp.clip.txt");
        }
    }
    else {
        std::cout << "No current clip available" << std::endl;
    }
}

void Model::changePrice(float newPrice) {
    std::cout << "---------------Changing current price-------------" << std::endl;
    if(currentMusicPtr != nullptr) {
        (*currentMusicPtr)->setPrice(newPrice);
        printSong(currentMusicPtr);
    }
    else {
        std::cout << "No current clip available" << std::endl;
    }
}

void Model::printSong(MusicClipPtr *mptr) {
    std::cout << "Song " << (*mptr)->getIndex() << std::endl;
    std::cout << "Id: " << (*mptr)->getId() << std::endl;
    std::cout << "Title: " << (*mptr)->getTitle() << std::endl;
    std::cout << "Artist:" << (*mptr)->getArtist() << std::endl;
    std::string people;
    auto peopleVector = (*mptr)->getPeople();
    if (!peopleVector.empty()) {
        people += peopleVector.at(0);
        for(unsigned int i = 1; i < (peopleVector.size()); i++) {
            people += ",";
            people += peopleVector.at(i);
        }
    }
    std::cout << "Band components: " << people << std::endl;
    std::cout << "Genre: " << mptr->intToGenreString((*mptr)->getGenre()) << std::endl;
    std::cout << "Price: " << (*mptr)->getPrice() << "\n\n";
}

void Model::readFromFile() {
    std::string path = "../input.inp.txt";
    std::string line;
    std::ifstream myfile(path);
    std::vector<std::string> vec;
    if (myfile.is_open())
    {

        std::string op;
        while(myfile >> op) {
            if(op != "i" and op != "e" and op != "p" and op != "c") {
                execute(op);
            }
            else if(op == "e") {
                std::string tmp;
                myfile >> tmp;
                edit(std::stoi(tmp));
            }
            else if(op == "p") {
                std::string tmp;
                myfile >> tmp;
                changePrice(std::stof(tmp));
            }
            else if(op == "c") {
                std::string tmp;
                int id;
                int index;
                std::string artist;
                std::vector<std::string> people;
                std::string title;
                int genre;
                float price;
                myfile >> tmp;
                id = std::stoi(tmp);
                myfile >> tmp;
                index = std::stoi(tmp);
                myfile >> tmp;
                artist = parseSingleString(tmp);
                myfile >> tmp;
                people = parsePeople(tmp);
                myfile >> tmp;
                title = parseSingleString(tmp);
                myfile >> tmp;
                genre = std::stoi(tmp);
                myfile >> tmp;
                price = std::stof(tmp);
                MusicClipPtr *mpt = songList.getMusicPtr(id);
                mpt->createNewClip(id, index, artist, people, title, mpt->intToGenre(genre), "", price);
                mpt->saveToFile();
            }
        }
        myfile.close();
    }
    else {
        std::cout << "Unable to open file" << std::endl;
    }
}

std::string Model::parseSingleString(std::string old) {
    std::replace( old.begin(), old.end(), '_', ' ');
    return old;
}

std::vector<std::string> Model::parsePeople(std::string old) {
    std::string newStr;
    std::vector<std::string> vec;
    if(old == "_") {
        return vec;
    }
    else {
        int j = 0;
        for(int i = 0; i < old.size(); i++) {
            if(old[i] == ',') {
                newStr = old.substr(j, i);
                j = i+1;
                vec.push_back(parseSingleString(newStr));
            }
        }
        newStr = old.substr(j, old.size());
        vec.push_back(parseSingleString(newStr));
        return vec;
    }

}

int Model::execute(std::string inst) {
    if(inst == "l") {
        listSongs();
    }
    else if(inst == "e") {
        int id;
        bool valid = false;
        while( valid == false ) {
            std::cout << "Insert ID: " << std::endl;
            std::cin >> id;
            if(id > 10 or id < 0) {
                std::cout << "Invalid id: must be between 0 and 9" << std::endl;
            }
            else {
                valid = true;
            }
        }
        edit(id);
    }
    else if(inst == "c") {
        createNewClip();
    }
    else if(inst == "y") {
        deepCopy();
    }
    else if(inst == "i") {
        readFromFile();
    }
    else if(inst == "p") {
        float price;
        std::cout << "Insert price: ";
        std::cin >> price;
        changePrice(price);
    }
    else if(inst == "s") {
        saveClips();
    }
    else if(inst == "q") {
        std::cout << "End program" << std::endl;
        return 0;
    }
    else {
        std::cout << "Instruction not valid" << std::endl;
    }
    return 1;
}