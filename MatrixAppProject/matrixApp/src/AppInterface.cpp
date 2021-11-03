#include "common.h"
#include "utils.h"
#include "ArgumentParser.h"
#include "matrixLib.h"
#include "AppInterface.h"

bool isAB(char arg0, char arg1);

bool AppInterface::addMatrixInterf(int row, int col, char flag0, char flag1)
{
    if(flag0 == 'N')
    {
        double** matrixA = createMatrix(row, col);
        double** matrixB = createMatrix(row, col);

        if(!fillMatrix(matrixA, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;

        if(!fillMatrix(matrixB, row, col, "Wprowadz dane drugiej macierzy (iczby oddzielone spacja):"))
            return false;

        double** result =  addMatrix(matrixA, matrixB , row, col);
        printMatrix(result);

        deleteMatrix(result);
        deleteMatrix(matrixA);
        deleteMatrix(matrixB);
        return true;
    }

    else
    {
        if(!isAB(flag0, flag1))
            return false;

        if(matrixA == nullptr || matrixB == nullptr)
            return  false;
        double** result =  addMatrix(matrixA, matrixB, rowA, colA);
        printMatrix(result);
        deleteMatrix(result);
        return true;
    }
}

bool AppInterface::subtractMatrixInterf(int row, int col, char flag0, char flag1)
{
    if(flag0 == 'N')
    {
        double** matrixA = createMatrix(row, col);
        double** matrixB = createMatrix(row, col);

        if(!fillMatrix(matrixA, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;

        if(!fillMatrix(matrixB, row, col, "Wprowadz dane drugiej macierzy (iczby oddzielone spacja):"))
            return false;

        double** result =  subtractMatrix(matrixA, matrixB , row, col);
        printMatrix(result);

        deleteMatrix(result);
        deleteMatrix(matrixA);
        deleteMatrix(matrixB);
        return true;
    }
    else
    {
        if(!isAB(flag0, flag1))
            return false;

        if(matrixA == nullptr || matrixB == nullptr)
            return  false;
        double** result;
        if(flag0 == 'A')
            result =  subtractMatrix(matrixA, matrixB, rowA, colA);
        else
            result =  subtractMatrix(matrixB, matrixA, rowA, colA);
        printMatrix(result);
        deleteMatrix(result);
        return true;
    }
}

bool AppInterface::multiplyMatrixInterf(int rowA, int colA, int rowB, int colB, char flag0, char flag1)
{
    if(flag0 == 'N')
    {
        if(colB != rowA)
            return false;

        double** matrixA =  createMatrix(rowA, colA);
        double** matrixB =  createMatrix(rowB, colB);

        if(!fillMatrix(matrixA, rowA, colA, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;

        if(!fillMatrix(matrixB, rowB, colB, "Wprowadz dane drugiej macierzy (iczby oddzielone spacja):"))
            return false;

        double** result =  multiplyMatrix(matrixA, matrixB , rowA, colA, colB);
        printMatrix(result);

        deleteMatrix(result);
        deleteMatrix(matrixA);
        deleteMatrix(matrixB);
        return true;
    }
    else
    {
        if(!isAB(flag0, flag1))
            return false;

        if(matrixA == nullptr || matrixB == nullptr)
            return false;

        if(flag0 == 'A')
        {
            if(AppInterface::colA == AppInterface::rowB)
            {
                double** result = createMatrix(rowA, colB);
                result = multiplyMatrix(matrixA, matrixB, AppInterface::rowA, AppInterface::colA, AppInterface::colB);
                printMatrix(result);
                deleteMatrix(result);
                return true;
            }
            else
                return false;
        }
        else if(flag0 == 'B')
        {
            if(AppInterface::colB == AppInterface::rowA)
            {
                double** result = createMatrix(AppInterface::rowA, AppInterface::colB);
                result = multiplyMatrix(matrixB, matrixA, AppInterface::rowB, AppInterface::colB, AppInterface::colA);
                printMatrix(result);
                deleteMatrix(result);
                return true;
            }
            else
                return false;
        }
        return false;
    }
}

bool AppInterface::multiplyByScalarInterf(int row, int col, double scalar, char flag)
{
    if(flag == 'N')
    {
        double** matrix = createMatrix(row, col);

        if(!fillMatrix(matrix, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;

        double** result = multiplyByScalar(matrix, row, col, scalar);
        printMatrix(result);

        deleteMatrix(result);
        deleteMatrix(matrix);
        return true;
    }
    else if(flag == 'A')
    {
        if(matrixA == nullptr)
            return false;
        double** result = multiplyByScalar(matrixA, rowA, colA, scalar);
        printMatrix(result);
        deleteMatrix(result);
        return true;
    }
    else if(flag == 'B')
    {
        if(matrixB == nullptr)
            return false;
        double** result = multiplyByScalar(matrixB, rowB, colB, scalar);
        printMatrix(result);
        deleteMatrix(result);
        return true;
    }
    return false;
}

bool AppInterface::transpozeMatrixInterf(int row, int col, char flag)
{
    if(flag == 'N')
    {
        double** matrix = createMatrix(col, row);
        if(!fillMatrix(matrix, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;

        double** result = transpozeMatrix(matrix, row, col);
        printMatrix(result);

        deleteMatrix(matrix);
        deleteMatrix(result);
        return true;
    }
    else if(flag == 'A')
    {
        if(matrixA == nullptr)
            return false;

        double** result = transpozeMatrix(matrixA, rowA, colA);
        swap(rowA, colA);
        printMatrix(result);

        deleteMatrix(result);
        return true;
    }
    else if(flag == 'B')
    {
        if(matrixB == nullptr)
            return false;

        double** result = transpozeMatrix(matrixB, rowB, colB);
        swap(rowB, colB);
        printMatrix(result);

        deleteMatrix(result);
        return true;
    }
    else
        return false;
}

bool AppInterface::powerMatrixInterf(int row, int col, unsigned int power, char flag)
{
    if(flag == 'N')
    {
        double** matrix = createMatrix(row, col);
        if(!fillMatrix(matrix, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;
        double** result = powerMatrix(matrix,row, col, power);
        printMatrix(result);

        deleteMatrix(result);
        deleteMatrix(matrix);
        return true;
    }
    else if(flag == 'A')
    {
        if(matrixA == nullptr)
            return false;

        double** result = powerMatrix(matrixA, rowA, colA, power);
        printMatrix(result);

        deleteMatrix(result);
        return true;
    }
    else if(flag == 'B')
    {
        if(matrixB == nullptr)
            return false;

        double** result = powerMatrix(matrixB, rowB, colB, power);
        printMatrix(result);

        deleteMatrix(result);
        return true;
    }

    return false;
}

bool AppInterface::matrixIsDiagonalInterf(int row, int col, char flag)
{
    if(flag == 'N')
    {
        double** matrix = createMatrix(row, col);
        if(!fillMatrix(matrix, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;

        bool result = matrixIsDiagonal(matrix, row, col);
        std::cout<<result<<std::endl;

        deleteMatrix(matrix);
        return true;
    }
    else if(flag == 'A')
    {
        if(matrixA == nullptr)
            return false;
        std::cout<<matrixIsDiagonal(matrixA, rowA, colA)<<std::endl;
        return true;
    }
    else if(flag == 'B')
    {
        if(matrixB == nullptr)
            return false;
        std::cout<<matrixIsDiagonal(matrixB, rowB, colB)<<std::endl;
        return true;
    }

    return false;
}

bool AppInterface::sortRowInterf(int row, int col, int rowToSort, char flag)
{
    if(flag == 'N')
    {
        double** matrix = createMatrix(row, col);
        if(!fillMatrix(matrix, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;
        if(rowToSort >= row)
            return false;

        sortRow(*(matrix + rowToSort), col);
        printMatrix(matrix);

        deleteMatrix(matrix);
        return true;
    }
    else if(flag == 'A')
    {
        if(matrixA == nullptr)
            return false;
        double** result = createMatrix(rowA, colA);
        matrixcpy(result, matrixA, rowA, colA);

        sortRow(*(result + rowToSort), colA);
        printMatrix(result);

        deleteMatrix(result);
        return true;
    }
    else if(flag == 'B')
    {
        if(matrixB == nullptr)
            return false;
        double** result = createMatrix(rowB, colB);
        matrixcpy(result, matrixB, rowB, colB);

        sortRow(*(result + rowToSort), colB);
        printMatrix(result);

        deleteMatrix(result);
        return true;
    }
    return false;
}

bool AppInterface::sortRowsInMatrixInterf(int row, int col, char flag)
{
    if(flag == 'N')
    {
        double** matrix = createMatrix(row, col);
        if(!fillMatrix(matrix, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;

        sortRowsInMatrix(matrix, row, col);
        printMatrix(matrix);

        deleteMatrix(matrix);
        return true;
    }
    else if(flag == 'A')
    {
        if(matrixA == nullptr)
            return false;
        double** result = createMatrix(rowA, colA);
        matrixcpy(result, matrixA, rowA, colA);

        sortRowsInMatrix(result, rowA, colA);
        printMatrix(result);

        deleteMatrix(result);
        return true;
    }
    else if(flag == 'B')
    {
        if(matrixA == nullptr)
            return false;
        double** result = createMatrix(rowB, colB);
        matrixcpy(result, matrixB, rowB, colB);

        sortRowsInMatrix(result, rowB, colB);
        printMatrix(result);

        deleteMatrix(result);
        return true;
    }
    return false;
}

bool AppInterface::determinantMatrixInterf(int row, int col, char flag)
{
    if(flag == 'N')
    {
        double** matrix = createMatrix(row, col);
        if(!fillMatrix(matrix, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;

        double result = determinantMatrix(matrix, row, col);
        std::cout<<result<<std::endl;

        deleteMatrix(matrix);
        return true;
    }
    else if(flag == 'A')
    {
        if(matrixA == nullptr)
            return false;
        std::cout<<determinantMatrix(matrixA, rowA, colA)<<std::endl;
        return true;
    }
    else if(flag == 'B')
    {
        if(matrixB == nullptr)
            return false;
        std::cout<<determinantMatrix(matrixB, rowB, colB)<<std::endl;
        return true;
    }

    return false;
}

bool AppInterface::fill(int row, int col, char flag)
{
    double **matrixToFill;
    std::string input = "";

    if (flag == 'A')
    {
        if(matrixA != nullptr)
            deleteMatrix(matrixA);
        matrixA = createMatrix(row, col);
        rowA = row;
        colA = col;
        return fillMatrix(matrixA, row, col, "Wprowadz dane do macierzy (liczby oddzielone spacja):");
    }
    else if (flag == 'B')
    {
        if(matrixB != nullptr)
            deleteMatrix(matrixB);
        matrixB = createMatrix(row, col);
        rowB = row;
        colB = col;
        return fillMatrix(matrixB, row, col, "Wprowadz dane do macierzy (liczby oddzielone spacja):");
    }
    else
        return false;
}

bool AppInterface::fillMatrix(double** matrix, int row, int col, std::string msg)
{
    std::cout<<msg<<std::endl;
    std::string input;
    for (int i = 0; i < row; i++)
        for (int k = 0; k < col; k++)
        {
            std::cin>>input;
            if(isNumber(input))
                matrix[i][k] = std::stod(input);
            else
                return false;
        }
    return true;
}

void AppInterface::help()
{
    std::cout<<
    "Matrix Calculator\n"
    "matrixApp [nazwa dzialania]\n\n"

    "Dzialania:\n"

    "fill [row] [col] [A|B]\n\n"

    "Opis:\n"
    "   Wypelnia macierz podreczna. Istniaja dwie macierze podreczne - A i B.\n"
    "   Wypelnianie macierzy odbywa sie wierszami. Umozliwa tworzenie zlozonych instrukcji.\n"
    "   Np.: fill 2 2 A  fill 2 2 B  addMatrix A B determinantMatrix A - instrukcja wypelnia macierze A i B, nastepnie zwraca\n"
    "   wynik ich sumy i wartosc wyznacznika macierzy A\n\n"

    "-------------------------------------------------\n"
    "addMatrix [row] [col]\n\n"

    "Opis:\n"
    "   Dodaje dwie macierze. Po zatwierdzeniu polecenia nalezy wpisac kolejne elementy macierzy (oddzielone spacja).\n"
    "   Wypelnianie macierzy odbywa sie wierszami.\n\n"


    "-------------------------------------------------\n"
    "addMatrix [A] [B]\n\n"

    "Opis:\n"
    "   Dodaje macierz ppodreczna A do macierzy podrecznej B.\n"
    "   Instrukcja musi zostac poprzedzona instrukcja fill A oraz fill B.\n\n"

    "-------------------------------------------------\n"
    "subtractMatrix [row] [col]\n\n"

    "Opis:\n"
    "   Odejmuje dwie macierze. Po zatwierdzeniu polecenia nalezy wpisac kolejne elementy macierzy.\n"
    "   Wypelnianie macierzy odbywa sie wierszami. Druga macierz jest odejmowana od pierwszej.\n\n"


    "-------------------------------------------------\n"
    "subtractMatrix [A] [B]\n\n"

    "Opis:\n"
    "   Odejmuje macierz ppodreczna B od macierzy podrecznej A."
    "   Instrukcja musi zostac poprzedzona instrukcja fill A oraz fill B.\n\n"


    "-------------------------------------------------\n"
    "multiplyMatrix [rowA] [colA] [colB]\n\n"

    "Opis:\n"
    "   Mnoży dwie macierze. Po zatwierdzeniu polecenia nalezy wpisac kolejne elementy macierzy.\n"
    "   Wypelnianie macierzy odbywa sie wierszami. Operacja zwraca wynik: \n"
    "   pierwsza macierz * druga macierz.\n\n"

    "-------------------------------------------------\n"
    "multiplyMatrix [A] [B]\n\n"

    "Opis:\n"
    "   Mnoży dwie macierze podreczne (A * B).\n"
    "   Intrukcja musi zostac poprzedzona instrukcjami fill.\n\n"


    "-------------------------------------------------\n"
    "multiplyMatrix [row] [col] [scalar]\n\n"


    "Opis:\n"
    "   Mnoży macierz przez skalar. Po zatwierdzeniu polecenia nalezy wpisac kolejne elementy macierzy.\n"
    "   Wypelnianie macierzy odbywa sie wierszami. Operacja zwraca wynik: \n"
    "   skalar * macierz.\n\n"

    "-------------------------------------------------\n"
    "multiplyMatrix [A|B] [scalar]\n\n"


    "Opis:\n"
    "   Zwraca wynik mnozenia macierzy podrecznej przez skalar.\n"
    "   Wartosc zwracana: skalar * [A|B].\n\n"

    "-------------------------------------------------\n"
    "transpozeMatrix [row] [col]\n\n"


    "Opis:\n"
    "   Dokonuje transpozycji macierzy. Po zatwierdzeniu polecenia nalezy wpisac kolejne elementy macierzy.\n"
    "   Wypelnianie macierzy odbywa sie wierszami. Operacja zwraca wynik: \n"
    "   macierz ^ T.\n\n"


    "-------------------------------------------------\n"
    "transpozeMatrix [A|B]\n\n"


    "Opis:\n"
    "   Zwaraca  transpozycje macierzy podrecznej: [A|B] ^ T.\n\n"


    "-------------------------------------------------\n"
    "powerMatrix [row] [col] [power]\n\n"

    "Opis:\n"
    "   Podnosi macierz do potegi [power]. Po zatwierdzeniu polecenia nalezy wpisac kolejne elementy macierzy.\n"
    "   Wypelnianie macierzy odbywa sie wierszami. Operacja zwraca wynik: \n"
    "   macierz ^ power.\n\n"

    "-------------------------------------------------\n"
    "powerMatrix [A] [power]\n\n"

    "Opis:\n"
    "   Zwraca wynik potegowania macierzy  podrecznej do potegi [power].\n"
    "   Wartosc zwracana: [A|B] ^ power.\n\n"


    "-------------------------------------------------\n"
    "determinantMatrix [row] [col]\n\n"

    "Opis:\n"
    "   Liczy wyznacznik macierzy. Po zatwierdzeniu polecenia nalezy wpisac kolejne elementy macierzy.\n"
    "   Wypelnianie macierzy odbywa sie wierszami. Operacja zwraca wynik: \n"
    "   det(macierz).\n\n"


    "-------------------------------------------------\n"
    "determinantMatrix [A|B]\n\n"

    "Opis:\n"
    "   Liczy wyznacznik macierzy podrecznej. Operacja zwraca wynik: det( [A|B] ).\n\n"


    "-------------------------------------------------\n"
    "matrixIsDiagonal [row] [col]\n\n"


    "Opis:\n"
    "   Sprawdza czy macierz jest diagonalna. Po zatwierdzeniu polecenia nalezy wpisac kolejne elementy macierzy.\n"
    "   Wypelnianie macierzy odbywa sie wierszami. Operacja zwraca wynik: \n"
    "   1 - macierz jest diagonalna, 0 - macierz nie jest diagonalna.\n\n"


    "-------------------------------------------------\n"
    "matrixIsDiagonal  [A|B]\n\n"

    "Opis:\n"
    "   Sprawdza czy macierz podreczna jest diagonalna. \n"
    "   1 - macierz jest diagonalna, 0 - macierz nie jest diagonalna.\n\n";
}

//helper's methods
bool isAB(char arg0, char arg1)
{
    return (arg0 == 'A' || arg0 == 'B')
           && (arg1 == 'A' || arg1 == 'B')
           && (arg0 != arg1);
}

//CONSTRUCTOR / DESTRUCTOR
AppInterface::~AppInterface()
{
    if(matrixA != nullptr)
        deleteMatrix(matrixA);
    if(matrixB != nullptr)
        deleteMatrix(matrixB);
}