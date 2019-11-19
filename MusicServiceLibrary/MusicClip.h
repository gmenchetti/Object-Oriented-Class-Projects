//
// Created by Guglielmo Menchetti on 15/11/2018.
//

#ifndef MUSICCLIP_H
#define MUSICCLIP_H


#include <string>
#include <vector>

class MusicClip {
    friend class MusicClipPtr;    // Let MusicClipPtr access all members of MusicClip instances

private:
    int id;
    int index;
    std::string artist;
    enum genre {POP_MUSIC, FOLK_MUSIC, JAZZ, BLUES, CLASSICAL, OPERA, COUNTRY_MUSIC, REGGAE, ROCK} g;
    std::vector<std::string> people;
    std::string title;
    std::string clip;
    float price;

    MusicClip(int id, int index, std::string artist, std::vector<std::string> people,
            std::string title, MusicClip::genre genre, std::string clip, float price);

public:
    // Getter methods
    int getId() const;
    int getIndex() const;
    std::string getArtist() const;
    std::vector<std::string> getPeople() const;
    std::string getTitle() const;
    std::string getClip() const;
    float getPrice() const;
    MusicClip::genre getGenre() const;

    // Setter methods
    void setId(int id);
    void setIndex(int index);
    void setArtist(std::string artist);
    void setPeople(std::vector<std::string> people);
    void setTitle(std::string title);
    void setPrice(float price);

};

#endif //MUSICCLIP_H
