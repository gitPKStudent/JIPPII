#include <iostream>
#include <vector>
#include <chrono>
#include "MusicPlayer.h"

using namespace std;

void simpleVector() {
    vector<int> vect;
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.shrink_to_fit();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
}

void smarterVector() {
    vector<int> vect;
    vect.reserve(20);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.shrink_to_fit();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
}

void simpleVectorNoCout() {
    vector<int> vect;

    vect.push_back(1);

    vect.push_back(1);

    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);

    vect.pop_back();

    vect.pop_back();

    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();

    vect.shrink_to_fit();
}

void smarterVectorNoCout() {
    vector<int> vect;
    vect.reserve(20);

    vect.push_back(1);

    vect.push_back(1);

    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);

    vect.pop_back();

    vect.pop_back();

    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();

    vect.shrink_to_fit();
}

int main()
{
    MusicPlayer musicPlayer;
    musicPlayer.addSong({"Abba", 3});
    musicPlayer.addSong({"Hania Rani - Roztopy", 5});
    musicPlayer.addSong({"Bisz - Babel", 4});
    musicPlayer.displayAll();

    musicPlayer.playNext(1);
    musicPlayer.getActualPlayedSong().printSong();

    musicPlayer.playNext(5);
    musicPlayer.getActualPlayedSong().printSong();

    musicPlayer.playPrev(1);
    musicPlayer.getActualPlayedSong().printSong();


    musicPlayer.playPrev(12);
    musicPlayer.getActualPlayedSong().printSong();

    musicPlayer.remove(1);
    musicPlayer.remove(1);
    musicPlayer.playNext(1);
    musicPlayer.getActualPlayedSong().printSong();
    musicPlayer.playNext(1);
    musicPlayer.getActualPlayedSong().printSong();
    musicPlayer.playNext(1);
    musicPlayer.getActualPlayedSong().printSong();

    musicPlayer.addSong({"Grande valse brillante", 5});
    musicPlayer.playNext(1);
    musicPlayer.getActualPlayedSong().printSong();

    return 0;
}