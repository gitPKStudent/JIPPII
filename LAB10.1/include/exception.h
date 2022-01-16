#ifndef LAB10_1_EXCEPTION_H
#define LAB10_1_EXCEPTION_H

#include <exception>

class FileStreamException : public std::exception
{
    public:
        FileStreamException();
        const char * what() const noexcept;
};
#endif //LAB10_1_EXCEPTION_H
