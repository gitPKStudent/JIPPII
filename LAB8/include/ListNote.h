#ifndef LAB8_LISTNOTE_H
#define LAB8_LISTNOTE_H

#include <list>
#include <iterator>
#include "Note.h"

class ListNote : public Note
{
    private:
        std::list<std::string> stringList;
    public:
        void setContent(std::string);
        std::string getContent();
};
#endif //LAB8_LISTNOTE_H
