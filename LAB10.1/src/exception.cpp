#include "exception.h"

FileStreamException::FileStreamException()
{

}

const char* FileStreamException::what() const noexcept
{
    return "File openning error !";
}