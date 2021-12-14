#include <iostream>
#include "MusicPlayer.h"

using namespace std;

MusicPlayer::MusicPlayer()
{
    actualPlayed = {"none", 0};
    iterator = list.begin();
}

void MusicPlayer::addSong(Song song)
{
    list.emplace_back(song.getName(), song.getRate());
}

void MusicPlayer::remove(int pos)
{
   int size = list.size();
   pos = pos % size;
   std::list<Song>::iterator iterator = list.begin();
   std::advance(iterator, pos);
   list.erase(iterator);
}

void MusicPlayer::playPrev(int d)
{
    if(list.size() == 0)
        return;
    if(list.size() == 1)
    {
        iterator = list.begin();
        actualPlayed = *iterator;
        return;
    }

    d = d % list.size();
    while (d > 0)
    {
        if(iterator == list.begin())
            iterator = list.end();
        else
            iterator--;
        d--;
    }
    actualPlayed = *iterator;
}

void MusicPlayer::playNext(int d)
{
    if(list.size() == 0)
        return;
    if(list.size() == 1)
    {
        iterator = list.begin();
        actualPlayed = *iterator;
        return;
    }

    d = d % list.size();
    while (d > 0)
    {
        if(iterator == list.end())
            iterator = list.begin();
        else
            iterator++;
        d--;
    }
    actualPlayed = *iterator;
}

void MusicPlayer::displayAll()
{
    int i = 0;
    for(Song& song : list)
    {
        cout<<i++<<". ";
        song.printSong();
    }
}

Song MusicPlayer::getActualPlayedSong()
{
    return actualPlayed;
}