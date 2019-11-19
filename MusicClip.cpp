//
// Created by Guglielmo Menchetti on 15/11/2018.
//

#include "MusicClip.h"

MusicClip::MusicClip(int id, int index, std::string artist, std::vector<std::string> people,
                     std::string title, MusicClip::genre genre, std::string clip, float price) :
                     id(id), index(index), artist(artist), people(people),
                     title(title), price(price), clip(clip), g(genre) { }//this->clip = clip; }

int MusicClip::getId() const{
    return id;
}

int MusicClip::getIndex() const{
    return index;
}

std::string MusicClip::getArtist() const{
    return artist;
}

MusicClip::genre MusicClip::getGenre() const{
    return g;
}

std::vector<std::string> MusicClip::getPeople() const{
    return people;
}

std::string MusicClip::getTitle() const{
    return title;
}


std::string MusicClip::getClip() const{
    return clip;
}

float MusicClip::getPrice() const{
    return price;
}

void MusicClip::setId(int id) {
    this->id = id;
}
void MusicClip::setIndex(int index) {
    this->index = index;
}
void MusicClip::setArtist(std::string artist) {
    this->artist = artist;
}
void MusicClip::setPeople(std::vector<std::string> people) {
    this->people = people;
}

void MusicClip::setTitle(std::string title) {
    this->title = title;
}

void MusicClip::setPrice(float price) {
    this->price = price;
}