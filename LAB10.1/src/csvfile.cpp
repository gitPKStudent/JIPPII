#include "csvfile.h"
#include "exception.h"

using namespace std;

CSVFile::CSVFile(const char*  path)
{
    row = 0;
    col = 0;
    index = 0;
    fStream = ifstream(path);
    line = readNextLine();
    if(line == "")
        throw FileStreamException();
    else
    {
        int counter = 0;
        while(index < line.length())
        {
            index = nextElementIndex();
            counter++;
        }
        numOfCols = counter;
    }
    index = 0;
}

std::string CSVFile::readNextLine()
{
    if(fStream.good())
    {
        string line;
        getline(fStream, line);
        return line;
    }
    return "";
}

bool isUpper(char c)
{
    return c > 'A' && c < 'Z';
}

int CSVFile::nextElementIndex()
{
    if(index < line.length())
    {
        if(col == numOfCols - 1)
        {
            return line.length() + 1;
        }
        else
        {
            int tmpI = index;
            while(tmpI < line.length() && line[tmpI] != ',')
                tmpI++;
            return tmpI+1;
        }
    }
    return line.length() + 1;
}

std::string CSVFile::readNextElement()
{

    if(index >= (int)  line.length() || col >= numOfCols)
    {
        getline(fStream, line);
        index = 0;
        row++;
        col = 1;

        int tmp = index;
        index = nextElementIndex();
        return line.substr(tmp, index - tmp - 1);
    }
    else
    {
        int tmp = index;
        index = nextElementIndex();
        std::string ret = line.substr(tmp, index - tmp - 1);
        col++;
        return ret;
    }
}

int CSVFile::getColNum()
{
    return numOfCols;
}

int CSVFile::getCol()
{
    return col;
}

bool CSVFile::hasNextElement()
{
    return (fStream.peek() != EOF   || col < numOfCols) && !(fStream.peek() == EOF && index >= line.length());
}

CSVFile::~CSVFile()
{
    fStream.close();
}