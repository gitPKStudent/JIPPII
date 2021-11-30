#ifndef LAB8_TEXTNOTE_H
#define LAB8_TEXTNOTE_H

#include "Note.h"

class TextNote : public Note
{
    public:
        void setContent(std::string content);
        std::string getContent();
};

#endif //LAB8_TEXTNOTE_H
