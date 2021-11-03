#ifndef MATRIXAPP_APP_H
#define MATRIXAPP_APP_H

class AppInterface
{
    public:
        bool addMatrix(int row, int col, char flag0 = 'N', char flag1 = 'N');
        bool subtractMatrix(int row, int col, char flag0 = 'N', char flag1 = 'N');
        bool multiplyMatrix(int rowA, int colA, int rowB, int colB, char flag0 = 'N', char flag1 = 'N');
        bool multiplyByScalar(int row, int col, double scalar, char flag = 'N');
        bool transpozeMatrix(int row, int col, char flag = 'N');
        bool powerMatrix(int row, int col, unsigned int power, char flag = 'N');
        bool matrixIsDiagonal(int row, int col, char flag = 'N');
        bool sortRow(int row, int col, int rowToSort, char flag = 'N');
        bool sortRowsInMatrix(int row, int col, char flag = 'N');
        bool determinantMatrix(int row, int col, char flag = 'N');
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
