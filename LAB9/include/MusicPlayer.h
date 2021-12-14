#ifndef LAB9_MUSICPLAYER_H
#define LAB9_MUSICPLAYER_H

#include <list>
#include "Song.h"

class MusicPlayer
{
    private:
        Song actualPlayed;
        std::list<Song> list;
        std::list<Song>::iterator iterator;
    public:
        MusicPlayer();
        Song getActualPlayedSong();
        void displayAll();
        void addSong(Song song);
        void remove(int pos);
        void playNext(int d);
        void playPrev(int d);
};
#endif //LAB9_MUSICPLAYER_H
