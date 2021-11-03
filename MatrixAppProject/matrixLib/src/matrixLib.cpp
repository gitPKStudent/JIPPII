#include "common.h"
#include "matrixLib.h"

//helper's method declaration
double multiplyRowCol(double** a, double** b, int row, int col, int n);
int multiplyRowCol(int** a, int** b, int row, int col, int n);

double** idnetityMatrix(int n);
int** idnetityMatrixI(int n);

double det(double** a, int n, bool* excludedRows, bool* excludedCols, int numOfExcluded = 0/*number of ecluded columns*/, int actualCol = 0);
int det(int** a, int n, bool* excludedRows, bool* excludedCols, int numOfExcluded = 0/*number of ecluded columns*/, int actualCol = 0);

void multiplyMatrixS(double** a, double** b, int rowA, int colA, int rowB);
void multiplyMatrixS(int** a, int** b, int rowA, int colA, int rowB);

void printMatrixD(double** array, bool* excludedRows, bool* excludedCols, int  actualRow, int actualCol, int znak);

//LIBRARY METHOD'S
double** addMatrix(double** a, double** b, int row, int col)
{
    double** result = createMatrix(row, col);

    for(int i = 0; i < row; i++)
        for (int k = 0; k < col; k++)
            result[i][k] = a[i][k] + b[i][k];

    return result;
}

double** subtractMatrix(double** a, double** b, int row, int col)
{
    double** result = createMatrix(row, col);

    for(int i = 0; i < row; i++)
        for (int k = 0; k < col; k++)
            result[i][k] = a[i][k] - b[i][k];

    return result;
}

double** multiplyMatrix(double** a, double** b, int rowA, int colA, int colB)
{
    double** result = createMatrix(rowA, colB);

    for(int i = 0; i < rowA; i++)
        for (int k = 0; k < colB; k++)
            result[i][k] = multiplyRowCol(a, b, i, k, colA);

    return result;
}

void multiplyMatrixS(double **a, double **b, int rowA, int colA, int colB)
{
    double** result = multiplyMatrix(a, b, rowA, colA, colB);
    matrixcpy(a, result, rowA, colB);
    deleteMatrix(result);
}


double** multiplyByScalar(double** a, int row, int col, double scalar)
{
    double** result = createMatrix(row, col);
    matrixcpy(result, a, row, col);

    for(int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
            result[i][k] *= scalar;
    }

    return result;
}

void printMatrix(double** a, int row, int col)
{
    std::cout<<"-----------------\n";
    for(int i = 0; i < row; i++)
    {
        std::cout<<"[ ";
        for (int k = 0; k < col; k++)
        {
            std::cout<<a[i][k]<<" ";
        }
        std::cout<<"]"<<std::endl;
    }
}

double** transpozeMatrix(double** a, int row, int col)
{
    double** result = createMatrix(col, row);

    for(int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
            result[i][k] = a[k][i];
    }

    return result;
}

double** powerMatrix(double** a, int row, int col, unsigned int power)
{
    double** tmp = createMatrix(row, col);
    matrixcpy(tmp, a, row, col);
    double** result = idnetityMatrix(row);

    while(power > 0)
    {
        if(power % 2 == 1)
            multiplyMatrixS(result, tmp, row, col, col);

        power = power / 2;
        multiplyMatrixS(tmp, tmp, row, col, col);
    }

    deleteMatrix(tmp);
    return result;
}

void printMatrix(double** a)
{
    std::cout<<"-----------------\n";
    int row = _msize(a) / sizeof (double*);
    int col = _msize(*a) / sizeof (double);
    for(int i = 0; i < row; i++)
    {
        std::cout<<"[ ";
        for (int k = 0; k < col; k++)
        {
            std::cout<<a[i][k]<<" ";
        }
        std::cout<<"]"<<std::endl;
    }
}

bool matrixIsDiagonal(double**a, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
            if(a[i][k] != 0 && i != k)
                return false;
    }
    return true;
}

void swap(double &a, double &b)
{
    double c = a;
    a = b;
    b = c;
}

void sortRow(double* matrix, int col)
{
    for(int i = 0; i < col; i++)
        for(int k = col - 1; k > i; k--)
            if(matrix[k - 1] > matrix[k])
                swap(matrix[k - 1], matrix[k]);
}

void sortRowsInMatrix(double** a, int row, int col)
{
    for(int i = 0; i < row; i++)
        sortRow(a[i], col);
}

double determinantMatrix(double** a, int row, int col)
{
    bool* excludedRows = new bool [row];
    bool* excludedCols = new bool [row];
    for(int i = 0; i < row; i++)
    {
        excludedCols[i] = false;
        excludedRows[i] = false;
    }

    double result = det(a, row, excludedRows, excludedCols);
    delete [] excludedRows;
    delete [] excludedCols;
    return result;
}

bool matrixcmp(double** a, double** b, int row, int col)
{
    for(int i = 0; i < row; i++)
        for(int k = 0; k < col; k++)
            if(a[i][k] != b[i][k])
                return false;
    return true;
}

void deleteMatrix(double** a)
{
    int rows = _msize(a) / sizeof(double *);
    for (int i = 0; i < rows; i++)
        delete[] a[i];
    delete[] a;
}

void fillMatrix(int row, int col, double** a, ...)
{
    va_list listOfArg;
    va_start(listOfArg, row * col);
    for(int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
            a[i][k] = va_arg(listOfArg, double);
    }
    va_end(listOfArg);
}

double** createMatrix(int row, int col)
{
    double** result = new double* [row];
    for(int i = 0;i < row; i++)
        result[i] = new double [col];
    return result;
}

//helper funtion's
double det(double** a, int n, bool* excludedRows, bool* excludedCols, int numOfExcluded/*number of ecluded columns*/, int actualRow)
{
    if(n - numOfExcluded == 1)
    {
        int row, col;
        for (int i = 0; i < n; i++)
            if (!excludedCols[i])
            {
                col = i;
                break;
            }

        for (int i = 0; i < n; i++)
            if (!excludedRows[i])
            {
                row = i;
                break;
            }

        return a[row][col];
    }//if(n - numOfExcluded == 1)
    else
    {
        int sign = 0;
        double result = 0;
        for(int i = 0; i < n; i++)
        {
            if(!excludedCols[i])
            {
                excludedRows[actualRow] = true;
                excludedCols[i] = true;
                result += pow(-1, sign) * a[actualRow][i] * det(a, n, excludedRows, excludedCols, numOfExcluded+1, actualRow + 1);
                excludedCols[i] = false;
                excludedRows[actualRow] = false;
                sign++;
            }
        }
        return result;
    }
}//double det(double**, int, bool*, bool*, int)

double multiplyRowCol(double** a, double** b, int row, int col, int n)
{
    double result = 0;
    for(int i = 0; i < n; i++)
        result += a[row][i] * b[i][col];
    return result;
}


void matrixcpy(double** a, double** b, int row , int col)
{
    for(int i = 0; i < row; i++)
        for (int k = 0; k < col; k++)
            a[i][k] = b[i][k];
}

//SAME SET OF FUNCIONS WORKING WITH INTEGER'S
int** addMatrix(int** a, int** b, int row, int col)
{
    int** result = createMatrixI(row, col);

    for(int i = 0; i < row; i++)
        for (int k = 0; k < col; k++)
            result[i][k] = a[i][k] + b[i][k];

    return result;
}

int** subtractMatrix(int** a, int** b, int row, int col)
{
    int** result = createMatrixI(row, col);

    for(int i = 0; i < row; i++)
        for (int k = 0; k < col; k++)
            result[i][k] = a[i][k] - b[i][k];

    return result;
}

int** multiplyMatrix(int** a, int** b, int rowA, int colA, int colB)
{
    int** result = createMatrixI(rowA, colB);

    for(int i = 0; i < rowA; i++)
        for (int k = 0; k < colB; k++)
            result[i][k] = multiplyRowCol(a, b, i, k, colA);

    return result;
}

int** multiplyByScalar(int** a, int row, int col, double scalar)
{
    int** result = createMatrixI(row, col);
    matrixcpy(result, a, row, col);

    for(int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
            result[i][k] *= scalar;
    }

    return result;
}

void printMatrix(int** a, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        std::cout<<"[ ";
        for (int k = 0; k < col; k++)
        {
            std::cout<<a[i][k]<<" ";
        }
        std::cout<<"]"<<std::endl;
    }
}

int** transpozeMatrix(int** a, int row, int col)
{
    int** result = createMatrixI(row, col);

    for(int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
            result[i][k] = a[k][i];
    }

    return result;
}

int** powerMatrix(int** a, int row, int col, unsigned int power)
{
    int** tmp = createMatrixI(row, col);
    matrixcpy(tmp, a, row, col);
    int** result = idnetityMatrixI(row);

    while(power > 0)
    {
        if(power % 2 == 1)
            multiplyMatrixS(result, tmp, row, col, col);

        power = power / 2;
        multiplyMatrixS(tmp, tmp, row, col, col);
    }

    deleteMatrix(tmp);
    return result;
}

void printMatrix(int** a)
{
    int row = _msize(a) / sizeof (int*);
    int col = _msize(*a) / sizeof (int);
    for(int i = 0; i < row; i++)
    {
        std::cout<<"[ ";
        for (int k = 0; k < col; k++)
        {
            std::cout<<a[i][k]<<" ";
        }
        std::cout<<"]"<<std::endl;
    }
}

bool matrixIsDiagonal(int**a, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
            if(a[i][k] != 0 && i != k)
                return false;
    }
    return true;
}

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void sortRow(int* matrix, int col)
{
    for(int i = 0; i < col; i++)
        for(int k = col - 1; k > i; k--)
            if(matrix[k - 1] > matrix[k])
                swap(matrix[k - 1], matrix[k]);
}

void sortRowsInMatrix(int** a, int row, int col)
{
    for(int i = 0; i < row; i++)
        sortRow(a[i], col);
}

int determinantMatrix(int** a, int row, int col)
{
    bool* excludedRows = new bool [row];
    bool* excludedCols = new bool [row];
    for(int i = 0; i < row; i++)
    {
        excludedCols[i] = false;
        excludedRows[i] = false;
    }

    int result = det(a, row, excludedRows, excludedCols);
    delete [] excludedRows;
    delete [] excludedCols;
    return result;
}

bool matrixcmp(int** a, int** b, int row, int col)
{
    for(int i = 0; i < row; i++)
        for(int k = 0; k < col; k++)
            if(a[i][k] != b[i][k])
                return false;
    return true;
}

void deleteMatrix(int** a)
{
    int rows = _msize(a) / sizeof (int *);
    for(int i = 0; i < rows; i++)
        delete [] a[i];
    delete [] a;
}

void fillMatrix(int row, int col, int** a, ...)
{
    va_list listOfArg;
    va_start(listOfArg, row * col);
    for(int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
            a[i][k] = va_arg(listOfArg, int);
    }
    va_end(listOfArg);
}

int** createMatrixI(int row, int col)
{
    int** result = new int* [row];
    for(int i = 0;i < row; i++)
        result[i] = new int [col];
    return result;
}

void matrixcpy(int** a, int** b, int row , int col)
{
    for(int i = 0; i < row; i++)
        for (int k = 0; k < col; k++)
            a[i][k] = b[i][k];
}


//helper funtion's
int det(int** a, int n, bool* excludedRows, bool* excludedCols, int numOfExcluded/*number of ecluded columns*/, int actualRow)
{
    if(n - numOfExcluded == 1)
    {
        int row, col;
        for (int i = 0; i < n; i++)
            if (!excludedCols[i])
            {
                col = i;
                break;
            }

        for (int i = 0; i < n; i++)
            if (!excludedRows[i])
            {
                row = i;
                break;
            }

        return a[row][col];
    }//if(n - numOfExcluded == 1)
    else
    {
        int sign = 0;
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            if(!excludedCols[i])
            {
                excludedRows[actualRow] = true;
                excludedCols[i] = true;
                result += pow(-1, sign) * a[actualRow][i] * det(a, n, excludedRows, excludedCols, numOfExcluded+1, actualRow + 1);
                excludedCols[i] = false;
                excludedRows[actualRow] = false;
                sign++;
            }
        }
        return result;
    }
}//double det(double**, int, bool*, bool*, int)

int multiplyRowCol(int** a, int** b, int row, int col, int n)
{
    int result = 0;
    for(int i = 0; i < n; i++)
        result += a[row][i] * b[i][col];
    return result;
}

int** idnetityMatrixI(int n)
{
    int** result = createMatrixI(n, n);

    for(int i = 0;i < n; i++)
        for(int k = 0;k < n; k++)
            if(i == k)
                result[i][k] = 1;
            else
                result[i][k] = 0;
    return result;
}


void multiplyMatrixS(int **a, int **b, int rowA, int colA, int colB)
{
    int** result = multiplyMatrix(a, b, rowA, colA, colB);
    matrixcpy(a, result, rowA, colB);
    deleteMatrix(result);
}


double** idnetityMatrix(int n)
{
    double** result = createMatrix(n, n);

    for(int i = 0;i < n; i++)
        for(int k = 0;k < n; k++)
            if(i == k)
                result[i][k] = 1.0;
            else
                result[i][k] = 0.0;
    return result;
}

void printMatrixD(double** array, bool* excludedRows, bool* excludedCols, int  actualRow, int actualCol, int znak)
{
    int row = _msize(array) / sizeof(double*);
    int col = _msize(*array) / sizeof(double);
    std::cout<<"------------------------- "<<std::endl;
    std::cout<<znak<<std::endl;
    for(int i = 0; i < row; i++)
    {
        std::cout<<"[ ";
        for(int k = 0;k < col; k++)
        {

            if(excludedCols[k] || excludedRows[i])
                std::cout<<"- ";
            else if(actualRow == i && actualCol == k)
                std::cout<<"["<<array[i][k]<<"] ";
            else
                std::cout<<array[i][k]<<" ";
        }
        std::cout<<"]"<<std::endl;
    }
    std::cout<<"------------------------- "<<std::endl;
}