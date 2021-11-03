#ifndef MATRIXCALCPROJECT_MATRIX_H
#define MATRIXCALCPROJECT_MATRIX_H

namespace mlib
{
                                  //DOUBLE'S
    //******************** MATRIX OPERATION FUNCTIONS ********************

    /* Adds two matrix
     *
     * @param a - first matrix
     * @param b - second matrix
     * @param row - number of rows of matrix a and b
     * @param col - number of columns of matrix a and b
     *
     * @result - pointer of result(a+b) array
     * */
    double** addMatrix(double** a, double** b, int row, int col);

    /* Subtracts two matrix. Returns matrix a - b.
     *
     * @param a - first matrix
     * @param b - second matrix
     * @param row - number of rows of matrix a and b
     * @param col - number of columns of matrix a and b
     *
     * @result - pointer of result(a - b) array.
     * */
    double** subtractMatrix(double** a, double** b, int row, int col);

    /* Multiplies two matrix. Returns matrix a * b.
     *
     * @param a - first matrix
     * @param b - second matrix
     * @param rowA - number of rows of matrix a
     * @param colA - number of columns of matrix a
     * @param rowB - number of rows of matrix b
     *
     * @result - pointer of result(a * b) array.
     * */
    double** multiplyMatrix(double** a, double** b, int rowA, int colA, int colB);

    /* Returns scalar * a, where a - matrix, s - scalar
     *
     * @param a - matrix
     * @param row - number of rows of matrix a
     * @param col - number of columns of matrix a
     * @param scalar - scalar
     *
     * @result - pointer of result(a * s) array.
     * */
    double** multiplyByScalar(double** a, int row, int col, double scalar);

    /* Prints array on screen.
     *
     * @param a - matrix
     * @param row - number of rows of matrix a
     * @param col - number of columns of matrix a
     * */
    void printMatrix(double** a, int row, int col);

    /* Prints array on screen. Array must be created by "new" operator (or malloc()).
     *
     * @param a - matrix
     * */
    void printMatrix(double** a);

    /* Returns transposition of matrix.
     *
     * @param a - matrix
     * @param row - number of rows of matrix a
     * @param col - number of columns of matrix a
     *
     * @result pointer to result array (a^T)
     * */
    double** transpozeMatrix(double** a, int row, int col);

    /* Returns a^power. Number of rows must equal number of columns.
     *
     * @param a - matrix.
     * @param row - number of rows of matrix a
     * @param col - number of columns of matrix a
     * @param power - must be >= 0
     *
     * @result pointer to result array (a^power)
     * */
    double** powerMatrix(double** a, int row, int col, unsigned int power);

    /* Checks if matrix is diagonal.
     *
     * @param a - matrix.
     * @param row - number of rows of matrix a
     * @param col - number of columns of matrix a
     *
     * @result returns true if matrix is diagonal, false otherwise
     * */
    bool matrixIsDiagonal(double**a, int row, int col);

    /* Swaps two double variables.
     *
     * @param a - Reference to first value.
     * @param b - Reference to second value.
     * */
    void swap(double &a, double &b);

    /* Sorts single row in matrix.
     *
     * @param matrix - pointer to matrix column
     * @param col - length of matrix
     * */
    void sortRow(double* matrix, int col);

    /* Sorts ascending each row in matrix.
     *
     * @param a - pointer to matrix
     * @param row - number of rows
     * @param col - number of columns
     * */
    void sortRowsInMatrix(double** a, int row, int col);

    /* Returns determinant of matrix a
     *
     * @param a - pointer to matrix
     * @param row - number of rows
     * @param col - number of columns
     *
     * @result det(a)
     * */
    double determinantMatrix(double** a, int row, int col);

    //******************** MATRIX CREATION FUNCTIONS ********************

    /* Checks if matrix a == matrix b
     *
     * @param a - pointer to first matrix
     * @param b - pointer to second matrix
     * @param row - number of rows
     * @param col - number of columns
     *
     * @result true if matrix'es are equal, false otherwise
     * */
    bool matrixcmp(double** a, double** b, int row, int col);

    /* Creates empty array with row - rows and col - columns
     *
     * @param row - number of rows
     * @param col - number of columns
     *
     * @result pointer to created array
     * */

    double** createMatrix(int row, int col);

    /* Deletes matrix a
     *
     * @param a - pointer to matrix
     * */
    void deleteMatrix(double** a);

    /* Fills array with row * col elements
     *
     * @param a - pointer to matrix
     * @param row - number of rows
     * @param col - number of columns
     * @param ... - next double value's
     * */
    void fillMatrix(int row, int col, double** a, ...);

                                 //INTEGER'S
    //******************** MATRIX OPERATION FUNCTIONS ********************

    /* Adds two matrix
     *
     * @param a - first matrix
     * @param b - second matrix
     * @param row - number of rows of matrix a and b
     * @param col - number of columns of matrix a and b
     *
     * @result - pointer of result(a+b) array
     * */
    int** addMatrix(int** a, int** b, int row, int col);

    /* Subtracts two matrix. Returns matrix a - b.
     *
     * @param a - first matrix
     * @param b - second matrix
     * @param row - number of rows of matrix a and b
     * @param col - number of columns of matrix a and b
     *
     * @result - pointer of result(a - b) array.
     * */
    int** subtractMatrix(int** a, int** b, int row, int col);

    /* Multiplies two matrix. Returns matrix a * b.
     *
     * @param a - first matrix
     * @param b - second matrix
     * @param rowA - number of rows of matrix a
     * @param colA - number of columns of matrix a
     * @param rowB - number of rows of matrix b
     *
     * @result - pointer of result(a * b) array.
     * */
    int** multiplyMatrix(int** a, int** b, int rowA, int colA, int colB);

    /* Returns scalar * a, where a - matrix, s - scalar
     *
     * @param a - matrix
     * @param row - number of rows of matrix a
     * @param col - number of columns of matrix a
     * @param scalar - scalar
     *
     * @result - pointer of result(a * s) array.
     * */
    int** multiplyByScalar(int** a, int row, int col, double scalar);

    /* Prints array on screen.
     *
     * @param a - matrix
     * @param row - number of rows of matrix a
     * @param col - number of columns of matrix a
     * */
    void printMatrix(int** a, int row, int col);

    /* Prints array on screen. Array must be created by "new" operator (or malloc()).
     *
     * @param a - matrix
     * */
    void printMatrix(int** a);

    /* Returns transposition of matrix.
     *
     * @param a - matrix
     * @param row - number of rows of matrix a
     * @param col - number of columns of matrix a
     *
     * @result pointer to result array (a^T)
     * */
    int** transpozeMatrix(int** a, int row, int col);

    /* Returns a^power. Number of rows must equal number of columns.
     *
     * @param a - matrix.
     * @param row - number of rows of matrix a
     * @param col - number of columns of matrix a
     * @param power - must be >= 0
     *
     * @result pointer to result array (a^power)
     * */
    int** powerMatrix(int** a, int row, int col, unsigned int power);

    /* Checks if matrix is diagonal.
     *
     * @param a - matrix.
     * @param row - number of rows of matrix a
     * @param col - number of columns of matrix a
     *
     * @result returns true if matrix is diagonal, false otherwise
     * */
    bool matrixIsDiagonal(int**a, int row, int col);

    /* Swaps two double variables.
     *
     * @param a - Reference to first value.
     * @param b - Reference to second value.
     * */
    void swap(int &a, int &b);

    /* Sorts single row in matrix.
     *
     * @param matrix - pointer to matrix column
     * @param col - length of matrix
     * */
    void sortRow(int* matrix, int col);

    /* Sorts ascending each row in matrix.
     *
     * @param a - pointer to matrix
     * @param row - number of rows
     * @param col - number of columns
     * */
    void sortRowsInMatrix(int** a, int row, int col);

    /* Returns determinant of matrix a
     *
     * @param a - pointer to matrix
     * @param row - number of rows
     * @param col - number of columns
     *
     * @result det(a)
     * */
    int determinantMatrix(int** a, int row, int col);

    /* Copies src matrix into dest matrix.
     *
     * @param dest - destination matrix
     * @param src - source matrix
     * @param row - number of rows of matrix
     * @param col - number of columns of matrix
     * */
    void matrixcpy(double** dest, double** src, int row , int col);

    //******************** MATRIX CREATION FUNCTIONS ********************

    /* Checks if matrix a == matrix b
     *
     * @param a - pointer to first matrix
     * @param b - pointer to second matrix
     * @param row - number of rows
     * @param col - number of columns
     *
     * @result true if matrix'es are equal, false otherwise
     * */
    bool matrixcmp(int** a, int** b, int row, int col);

    /* Creates empty array with row - rows and col - columns
     *
     * @param row - number of rows
     * @param col - number of columns
     *
     * @result pointer to created array
     * */

    int** createMatrixI(int row, int col);

    /* Deletes matrix a
     *
     * @param a - pointer to matrix
     * */
    void deleteMatrix(int** a);

    /* Fills array with row * col elements
     *
     * @param a - pointer to matrix
     * @param row - number of rows
     * @param col - number of columns
     * @param ... - next double value's
     * */
    void fillMatrix(int row, int col, int** a, ...);

    /* Copies src matrix into dest matrix.
     *
     * @param dest - destination matrix
     * @param src - source matrix
     * @param row - number of rows of matrix
     * @param col - number of columns of matrix
     * */
    void matrixcpy(int** a, int** b, int row , int col);
}
#endif //MATRIXCALCPROJECT_MATRIX_H
