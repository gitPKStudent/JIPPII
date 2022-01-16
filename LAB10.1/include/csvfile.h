#ifndef LAB10_1_CSVFILE_H
#define LAB10_1_CSVFILE_H
#include <fstream>
#include <string>

class CSVFile
{
    private:
        int numOfCols;
        int index;
        int row;
        int col;
        bool nextElement;
        std::string line;
        std::ifstream fStream;
    public:
        CSVFile(const char* path);
        ~CSVFile();
        void close();
        std::string readNextElement();
        int getRow();
        int getCol();
        int getColNum();
        bool hasNextElement();
    private:
         std::string readNextLine();
         int nextElementIndex();


};
#endif //LAB10_1_CSVFILE_H
