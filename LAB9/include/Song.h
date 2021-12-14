//
// Created by mik15 on 14.12.2021.
//

#ifndef LAB9_MUSIC_H
#define LAB9_MUSIC_H
#include <string>
class Song
{
    private:
    std::string name;
    short rate;

    public:
        Song();
        Song(std::string name, short rate);
        std::string getName();
        short getRate();
        void printSong();
};
#endif //LAB9_MUSIC_H
