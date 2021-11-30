#include "NoteDirector.h"

void NoteDirector::addNote(Note* note)
{
    std::vector<Note*>::iterator it;
    it = notes.end();
    notes.insert(it, note);
}

void NoteDirector::deleteNote(int index)
{
    if(index < notes.size())
    {
        std::vector<Note*>::iterator it;
        std::advance(it, index);
        delete *it;
        notes.erase(it);
    }
}

void NoteDirector::editNote(int index, std::string content)
{
    if(index < notes.size())
    {
        std::vector<Note*>::iterator it;
        std::advance(it, index);
        (*it)->setContent(content);
    }
}

void NoteDirector::printNotes()
{
    std::string out = "";
    std::vector<Note*>::iterator it;
    for(it = notes.begin(); it != notes.end();  it++)
    {
        std::cout<<"-----------------\n";
        std::cout<<"***"<<(*it)->getTitle()<<"***\n";
        std::cout<<(*it)->getContent()<<std::endl;
        std::cout<<"-----------------\n";
    }
}