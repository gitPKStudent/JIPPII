#ifndef LAB8_NOTEDIRECTOR_H
#define LAB8_NOTEDIRECTOR_H

#include <vector>
#include "Note.h"
#include "TextNote.h"
#include "ListNote.h"

class NoteDirector
{
    private:
        std::vector<Note*> notes;
    public:
        void addNote(Note* note);
        void deleteNote(int index);
        void editNote(int index, std::string content);
        void printNotes();
};
#endif //LAB8_NOTEDIRECTOR_H
