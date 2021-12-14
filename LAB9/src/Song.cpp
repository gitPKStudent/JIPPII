#include <iostream>
#include "Song.h"

using namespace std;

Song::Song()
{
    this->name = "none";
    this->rate = 0;
}
Song::Song(string name, short rate)
{
    this->name = name;
    this->rate = rate;
}

string Song::getName()
{
    return name;
}

short Song::getRate()
{
    return rate;
}

void Song::printSong()
{
    cout<<getName()<<" "<<getRate()<<endl;
}