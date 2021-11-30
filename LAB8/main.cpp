#include <iostream>

#include "NoteDirector.h"
#include "TextNote.h"
#include "ListNote.h"

int main()
{
    TextNote* textNote = new TextNote();
    textNote->setTitle("TEXT NOTE 0");
    textNote->setContent("To moja notka.\nJest zolta,\ntak samo jak inne notki.");

    ListNote* listNote = new ListNote();
    listNote->setTitle("LIST NOTE 0");
    listNote->setContent("Kiedy niebo jak ciezka z olowiu pokrywa");
    listNote->setContent("Miazdzy umysl, zlej nudzie wydany na lup,");
    listNote->setContent("Gdy spoza chmur zaslony szare swiatlo splywa,");
    listNote->setContent("Swiatlo dnia smutniejszego nizli nocy grob;");
    listNote->setContent("Kiedy ziemia w wilgotne zmienia sie wiezienie,");
    listNote->setContent("Skad ucieka nadzieja, ten plochliwy stwor,");
    listNote->setContent("Jak nietoperz, gdy glowa tlukac o sklepienie,");
    listNote->setContent("Rozbija sie bezradnie o splesnialy mur");
    NoteDirector noteDirector;

    noteDirector.addNote(textNote);
    noteDirector.addNote(listNote);

    noteDirector.printNotes();

    delete listNote;
    delete textNote;

    return 0;
}
