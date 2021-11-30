#include "ListNote.h"

void ListNote::setContent(std::string content)
{
    stringList.push_back(content);
}

std::string ListNote::getContent()
{
    std::string out = "";
    int index = 1;
    std::list<std::string >::iterator it;
    for(it = stringList.begin() ;it != stringList.end(); it++, index++)
        out += std::to_string(index) + " " + *it + "\n";
    return out.substr(0, out.length() - 1);
}