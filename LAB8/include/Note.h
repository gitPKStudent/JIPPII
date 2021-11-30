#ifndef LAB8_NOTE_H
#define LAB8_NOTE_H

#include <iostream>

class Note
{
    protected:
        std::string title;
        std::string content;
    public:
        void setTitle(std::string);
        std::string getTitle();
        virtual void setContent(std::string content) = 0;
        virtual std::string getContent() = 0;
};
#endif //LAB8_NOTE_H
