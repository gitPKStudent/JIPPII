#ifndef MATRIXAPP_APP_H
#define MATRIXAPP_APP_H

class AppInterface
{
    public:
        bool addMatrixInterf(int row, int col, char flag0 = 'N', char flag1 = 'N');
        bool subtractMatrixInterf(int row, int col, char flag0 = 'N', char flag1 = 'N');
        bool multiplyMatrixInterf(int rowA, int colA, int rowB, int colB, char flag0 = 'N', char flag1 = 'N');
        bool multiplyByScalarInterf(int row, int col, double scalar, char flag = 'N');
        bool transpozeMatrixInterf(int row, int col, char flag = 'N');
        bool powerMatrixInterf(int row, int col, unsigned int power, char flag = 'N');
        bool matrixIsDiagonalInterf(int row, int col, char flag = 'N');
        bool sortRowInterf(int row, int col, int rowToSort, char flag = 'N');
        bool sortRowsInMatrixInterf(int row, int col, char flag = 'N');
        bool determinantMatrixInterf(int row, int col, char flag = 'N');
        bool fill(int row, int col, char flag);
        static void help();
        ~AppInterface();

private:
        int rowA, colA;
        double** matrixA = nullptr;

        int rowB, colB;
        double** matrixB = nullptr;

        bool fillMatrix(double** matrix, int row, int col, std::string msg);
};
#endif //MATRIXAPP_APP_H
