#include "common.h"
#include "test.h"
#include "matrixLib.h"
#define DISPLAY_OPERATION true

void testAdd();
void testSubtract();
void testMultiply0();
void testMultiply1();
void testPower0();
void testPower1();
void testPower2();
void testPower3();
void detTest1();
void detTest2();
void detTest3();
void multiplyByScalarTest();
void transpozeMatrixTest();
void matrixIsDiagonalTest0();
void matrixIsDiagonalTest1();
void sortMatrixTest();

void testRun()
{
    testAdd();
    testSubtract();

    testMultiply0();
    testMultiply1();

    testPower0();
    testPower1();
    testPower2();
    testPower3();

    detTest1();
    detTest2();
    detTest3();

    multiplyByScalarTest();

    transpozeMatrixTest();

    matrixIsDiagonalTest0();
    matrixIsDiagonalTest1();

    sortMatrixTest();
}

void correct(std::string testName)
{
    std::cout<<testName<<" - CORRECT"<<std::endl;
}

void incorrect(std::string testName)
{
    std::cout<<testName<<" - INCORRECT"<<std::endl;
}

void testAdd()
{
    double** a = createMatrix(3, 4);
    double** b = createMatrix(3, 4);
    fillMatrix(3, 4, a, 1.0, 2.0, 3.0, 4.0 ,5.0 ,6.0 ,7.0 ,8.0 ,9.0 ,10.0, 11.0, 12.0);
    fillMatrix(3, 4, b, 12.0, 11.0, 10.0, 9.0 ,8.0 ,7.0 ,6.0 ,5.0 ,4.0 ,3.0 , 2.0, 1.0);

    double** correctAnswer = createMatrix(3, 4);
    fillMatrix(3, 4, correctAnswer, 13.0, 13.0, 13.0, 13.0, 13.0, 13.0, 13.0, 13.0, 13.0, 13.0, 13.0, 13.0);

    double** result = addMatrix(a, b, 3, 4);

    if(matrixcmp(correctAnswer, result, 3, 4))
        correct("testAdd");
    else
        incorrect("testAdd");

    if(DISPLAY_OPERATION)
    {
        std::cout<<"------------------------"<<std::endl;
        printMatrix(a);
        std::cout<<"+"<<std::endl;
        printMatrix(b);
        std::cout<<"="<<std::endl;
        printMatrix(result);
        std::cout<<"------------------------"<<std::endl;
    }

    deleteMatrix(a);
    deleteMatrix(b);
    deleteMatrix(correctAnswer);
    deleteMatrix(result);
}

void testSubtract()
{
    double** a = createMatrix(3, 4);
    double** b = createMatrix(3, 4);
    fillMatrix(3, 4, a, 1.0, 2.0, 3.0, 4.0 ,5.0 ,6.0 ,7.0 ,8.0 ,9.0 ,10.0, 11.0, 12.0);
    fillMatrix(3, 4, b,  1.0, 2.0, 3.0, 4.0 ,5.0 ,6.0 ,7.0 ,8.0 ,9.0 ,10.0, 11.0, 12.0);

    double** correctAnswer = createMatrix(3, 4);
    fillMatrix(3, 4, correctAnswer, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 ,0.0 ,0.0 ,0.0);

    double** result = subtractMatrix(a, b, 3, 4);

    if(matrixcmp(correctAnswer, result, 3, 4))
        correct("testSubtract");
    else
        incorrect("testSubtract");

    if(DISPLAY_OPERATION)
    {
        std::cout<<"------------------------"<<std::endl;
        printMatrix(a);
        std::cout<<"-"<<std::endl;
        printMatrix(b);
        std::cout<<"="<<std::endl;
        printMatrix(result);
        std::cout<<"------------------------"<<std::endl;
    }

    deleteMatrix(a);
    deleteMatrix(b);
    deleteMatrix(correctAnswer);
    deleteMatrix(result);
}

void testMultiply0()
{
    double** a = createMatrix(2, 3);
    double** b = createMatrix(3, 2);
    fillMatrix(2, 3, a, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    fillMatrix(3, 2, b, 1.0, 2.0, 3.0, 4.0 ,5.0, 6.0);

    double** correctAnswer = createMatrix(2, 2);
    fillMatrix(2, 2, correctAnswer, 22.0, 28.0, 49.0, 64.0);

    double** result = multiplyMatrix(a, b, 2, 3, 2);

    if(matrixcmp(correctAnswer, result, 2, 2))
        correct("testMultiply0");
    else
        incorrect("testMultiply0");

    if(DISPLAY_OPERATION)
    {
        std::cout<<"------------------------"<<std::endl;
        printMatrix(a);
        std::cout<<"*"<<std::endl;
        printMatrix(b);
        std::cout<<"="<<std::endl;
        printMatrix(result);
        std::cout<<"------------------------"<<std::endl;
    }

    deleteMatrix(a);
    deleteMatrix(b);
    deleteMatrix(correctAnswer);
    deleteMatrix(result);
}

void testMultiply1()
{
    double** a = createMatrix(3, 3);
    double** b = createMatrix(3, 3);
    fillMatrix(3, 3, a, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    fillMatrix(3, 3, b, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

    double** correctAnswer = createMatrix(3, 3);
    fillMatrix(3, 3, correctAnswer, 30.0, 36.0, 42.0, 66.0, 81.0, 96.0, 102.0, 126.0, 150.0);

    double** result = multiplyMatrix(a, b, 3, 3, 3);

    if(matrixcmp(correctAnswer, result, 3, 3))
        correct("testMultiply1");
    else
        incorrect("testMultiply1");

    if(DISPLAY_OPERATION)
    {
        std::cout<<"------------------------"<<std::endl;
        printMatrix(a);
        std::cout<<"*"<<std::endl;
        printMatrix(b);
        std::cout<<"="<<std::endl;
        printMatrix(result);
        std::cout<<"------------------------"<<std::endl;
    }

    deleteMatrix(a);
    deleteMatrix(b);
    deleteMatrix(correctAnswer);
    deleteMatrix(result);
}

void testPower0()
{
    double** a = createMatrix(3, 3);
    fillMatrix(3, 3, a, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

    unsigned int power = 0;

    double** correctAnswer = createMatrix(3, 3);
    fillMatrix(3, 3, correctAnswer, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);

    double** result = powerMatrix(a, 3, 3, power);

    if(matrixcmp(correctAnswer, result, 3, 3))
        correct("testPower0");
    else
        incorrect("testPower0");

    if(DISPLAY_OPERATION)
    {
        std::cout<<"------------------------"<<std::endl;
        printMatrix(a);
        std::cout<<"^"<<std::endl;
        std::cout<<power<<std::endl;
        std::cout<<"="<<std::endl;
        printMatrix(result);
        std::cout<<"------------------------"<<std::endl;
    }

    deleteMatrix(a);
    deleteMatrix(correctAnswer);
    deleteMatrix(result);
}

void testPower1()
{
    double** a = createMatrix(3, 3);
    fillMatrix(3, 3, a, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

    unsigned int power = 1;

    double** correctAnswer = createMatrix(3, 3);
    fillMatrix(3, 3, correctAnswer, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

    double** result = powerMatrix(a, 3, 3, power);

    if(matrixcmp(correctAnswer, result, 3, 3))
        correct("testPower1");
    else
        incorrect("testPower1");

    if(DISPLAY_OPERATION)
    {
        std::cout<<"------------------------"<<std::endl;
        printMatrix(a);
        std::cout<<"^"<<std::endl;
        std::cout<<power<<std::endl;
        std::cout<<"="<<std::endl;
        printMatrix(result);
        std::cout<<"------------------------"<<std::endl;
    }

    deleteMatrix(a);
    deleteMatrix(correctAnswer);
    deleteMatrix(result);
}

void testPower2()
{
    double **a = createMatrix(3, 3);
    fillMatrix(3, 3, a, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

    unsigned int power = 2;

    double **correctAnswer = createMatrix(3, 3);
    fillMatrix(3, 3, correctAnswer, 30.0, 36.0, 42.0, 66.0, 81.0, 96.0, 102.0, 126.0, 150.0);

    double **result = powerMatrix(a, 3, 3, power);

    if (matrixcmp(correctAnswer, result, 3, 3))
        correct("testPower2");
    else
        incorrect("testPower2");

    if (DISPLAY_OPERATION)
    {
        std::cout << "------------------------" << std::endl;
        printMatrix(a);
        std::cout << "^" << std::endl;
        std::cout << power << std::endl;
        std::cout << "=" << std::endl;
        printMatrix(result);
        std::cout << "------------------------" << std::endl;
    }

    deleteMatrix(a);
    deleteMatrix(correctAnswer);
    deleteMatrix(result);
}

void testPower3()
{
    double **a = createMatrix(3, 3);
    fillMatrix(3, 3, a, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

    unsigned int power = 7;

    double **correctAnswer = createMatrix(3, 3);
    fillMatrix(3, 3, correctAnswer, 31644432.0, 38881944.0, 46119456.0,
               71662158.0, 88052265.0, 104442372.0,
               111679884.0, 137222586.0, 162765288.0);

    double **result = powerMatrix(a, 3, 3, power);

    if (matrixcmp(correctAnswer, result, 3, 3))
        correct("testPower3");
    else
        incorrect("testPower3");

    if (DISPLAY_OPERATION)
    {
        std::cout << "------------------------" << std::endl;
        printMatrix(a);
        std::cout << "^" << std::endl;
        std::cout << power << std::endl;
        std::cout << "=" << std::endl;
        printMatrix(result);
        std::cout << "------------------------" << std::endl;
    }

    deleteMatrix(a);
    deleteMatrix(correctAnswer);
    deleteMatrix(result);
}

void detTest1()
{
    double **a = createMatrix(2, 2);
    fillMatrix(2, 2, a, 1.0, 2.0, 9.0, 4.0);

    double correctAnswer = -14;
    double result = determinantMatrix(a, 2, 2);

    if (result == correctAnswer)
        correct("detTest1");
    else
        incorrect("detTest1");

    if (DISPLAY_OPERATION)
    {
        std::cout << "------------------------" << std::endl;
        printMatrix(a);
        std::cout << "det(a) = "<<result<< std::endl;
        std::cout << "------------------------" << std::endl;
    }

    deleteMatrix(a);
}

void detTest2()
{
    double **a = createMatrix(3, 3);
    fillMatrix(3, 3, a, 1.0, 2.0, 9.0,
               4.0, 5.0, 6.0,
               7.0, 2.0, 3.0);

    double correctAnswer = -180;
    double result = determinantMatrix(a, 3, 3);

    if (result == correctAnswer)
        correct("detTest2");
    else
        incorrect("detTest2");

    if (DISPLAY_OPERATION)
    {
        std::cout << "------------------------" << std::endl;
        printMatrix(a);
        std::cout << "det(a) = "<<result<< std::endl;
        std::cout << "------------------------" << std::endl;
    }

    deleteMatrix(a);
}

void detTest3()
{
    double **a = createMatrix(4, 4);
    fillMatrix(4, 4, a, 1.0, 2.0, 9.0, 5.0,
               4.0, 5.0, 6.0, 6.0,
               7.0, 2.0, 3.0, 1.0,
               6.0, 5.0, 3.0, 2.0);

    double correctAnswer = 414;
    double result = determinantMatrix(a, 4, 4);

    if (result == correctAnswer)
        correct("detTest3");
    else
        incorrect("detTest3");

    if (DISPLAY_OPERATION)
    {
        std::cout << "------------------------" << std::endl;
        printMatrix(a);
        std::cout << "det(a) = "<<result<< std::endl;
        std::cout << "------------------------" << std::endl;
    }

    deleteMatrix(a);
}

void multiplyByScalarTest()
{
    double** a = createMatrix(3, 3);
    fillMatrix(3, 3, a, 1.0, 2.0, 1.0, 2.0, 1.0, 2.0, 1.0, 2.0, 1.0);

    double** correctAnswer = createMatrix(3, 3);
    fillMatrix(3, 3, correctAnswer, 30.0, 60.0, 30.0, 60.0, 30.0, 60.0, 30.0, 60.0, 30.0);

    int scalar = 30;

    double** result = multiplyByScalar(a, 3, 3, scalar);

    if(matrixcmp(correctAnswer, result, 3, 3))
        correct("multiplyByScalarTest");
    else
        incorrect("multiplyByScalarTest");

    if(DISPLAY_OPERATION)
    {
        std::cout<<"------------------------"<<std::endl;
        printMatrix(a);
        std::cout<<"*"<<std::endl;
        std::cout<<scalar<<std::endl;
        std::cout<<"="<<std::endl;
        printMatrix(result);
        std::cout<<"------------------------"<<std::endl;
    }

    deleteMatrix(a);
    deleteMatrix(correctAnswer);
    deleteMatrix(result);
}

void transpozeMatrixTest()
{
    double** a = createMatrix(3, 3);
    fillMatrix(3, 3, a, 1.0, 2.0, 3.0, 3.0, 5.0, 6.0, 7.0, 8.0, 9.0);

    double** correctAnswer = createMatrix(3, 3);
    fillMatrix(3, 3, correctAnswer, 1.0, 4.0, 7.0, 2.0, 5.0, 8.0, 3.0, 6.0, 9.0);

    double** result = transpozeMatrix(a, 3, 3);

    if(matrixcmp(correctAnswer, result, 3, 3))
        correct("transpozeMatrixTest");
    else
        incorrect("transpozeMatrixTest");

    if(DISPLAY_OPERATION)
    {
        std::cout<<"------------------------"<<std::endl;
        printMatrix(a);
        std::cout<<"*"<<std::endl;
        std::cout<<"^T"<<std::endl;
        std::cout<<"="<<std::endl;
        printMatrix(result);
        std::cout<<"------------------------"<<std::endl;
    }

    deleteMatrix(a);
    deleteMatrix(correctAnswer);
    deleteMatrix(result);
}

void matrixIsDiagonalTest0()
{
    double** a = createMatrix(3, 3);
    fillMatrix(3, 3, a, 1.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 9.0);

    bool correctAnswer = true;
    bool answer = matrixIsDiagonal(a, 3, 3);

    if(answer == correctAnswer)
        correct("matrixIsDiagonalTest0");
    else
        incorrect("matrixIsDiagonalTest0");

    if(DISPLAY_OPERATION)
    {
        std::cout<<"------------------------"<<std::endl;
        printMatrix(a);
        std::cout<<answer<<std::endl;
        std::cout<<"------------------------"<<std::endl;
    }

    deleteMatrix(a);
}

void matrixIsDiagonalTest1()
{
    double** a = createMatrix(3, 3);
    fillMatrix(3, 3, a, 1.0, 4.0, 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 9.0);

    bool correctAnswer = false;
    bool answer = matrixIsDiagonal(a, 3, 3);

    if(answer == correctAnswer)
        correct("matrixIsDiagonalTest1");
    else
        incorrect("matrixIsDiagonalTest1");

    if(DISPLAY_OPERATION)
    {
        std::cout<<"------------------------"<<std::endl;
        printMatrix(a);
        std::cout<<answer<<std::endl;
        std::cout<<"------------------------"<<std::endl;
    }

    deleteMatrix(a);
}

void sortMatrixTest()
{
    double** a = createMatrix(3, 3);
    fillMatrix(3, 3, a, 1.0, 4.0, 7.0, 8.0, 5.0, 1.0, 10.0, 1.0, 9.0);

    double** correctAnswer = createMatrix(3, 3);
    fillMatrix(3, 3, correctAnswer, 1.0, 4.0, 7.0, 1.0, 5.0, 8.0, 1.0, 9.0, 10.0);

    sortRowsInMatrix(a, 3, 3);

    if(matrixcmp(a, correctAnswer, 3, 3))
        correct("sortMatrixTest");
    else
        incorrect("sortMatrixTest");

    if(DISPLAY_OPERATION)
    {
        std::cout<<"------------------------"<<std::endl;
        printMatrix(a);
        std::cout<<"------------------------"<<std::endl;
    }

    deleteMatrix(a);
    deleteMatrix(correctAnswer);
}