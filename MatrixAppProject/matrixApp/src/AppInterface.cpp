#include "common.h"
#include "utils.h"
#include "ArgumentParser.h"
#include "matrixLib.h"
#include "AppInterface.h"

bool isAB(char arg0, char arg1);

bool AppInterface::addMatrix(int row, int col, char flag0, char flag1)
{
    if(flag0 == 'N')
    {
        double** matrixA = mlib::createMatrix(row, col);
        double** matrixB = mlib::createMatrix(row, col);

        if(!fillMatrix(matrixA, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;

        if(!fillMatrix(matrixB, row, col, "Wprowadz dane drugiej macierzy (iczby oddzielone spacja):"))
            return false;

        double** result =  mlib::addMatrix(matrixA, matrixB , row, col);
        mlib::printMatrix(result);

        mlib::deleteMatrix(result);
        mlib::deleteMatrix(matrixA);
        mlib::deleteMatrix(matrixB);
        return true;
    }

    else
    {
        if(!isAB(flag0, flag1))
            return false;

        if(matrixA == nullptr || matrixB == nullptr)
            return  false;
        double** result =  mlib::addMatrix(matrixA, matrixB, rowA, colA);
        mlib::printMatrix(result);
        mlib::deleteMatrix(result);
        return true;
    }
}

bool AppInterface::subtractMatrix(int row, int col, char flag0, char flag1)
{
    if(flag0 == 'N')
    {
        double** matrixA = mlib::createMatrix(row, col);
        double** matrixB = mlib::createMatrix(row, col);

        if(!fillMatrix(matrixA, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;

        if(!fillMatrix(matrixB, row, col, "Wprowadz dane drugiej macierzy (iczby oddzielone spacja):"))
            return false;

        double** result =  mlib::subtractMatrix(matrixA, matrixB , row, col);
        mlib::printMatrix(result);

        mlib::deleteMatrix(result);
        mlib::deleteMatrix(matrixA);
        mlib::deleteMatrix(matrixB);
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
            result =  mlib::subtractMatrix(matrixA, matrixB, rowA, colA);
        else
            result =  mlib::subtractMatrix(matrixB, matrixA, rowA, colA);
        mlib::printMatrix(result);
        mlib::deleteMatrix(result);
        return true;
    }
}

bool AppInterface::multiplyMatrix(int rowA, int colA, int rowB, int colB, char flag0, char flag1)
{
    if(flag0 == 'N')
    {
        if(colB != rowA)
            return false;

        double** matrixA =  mlib::createMatrix(rowA, colA);
        double** matrixB =  mlib::createMatrix(rowB, colB);

        if(!fillMatrix(matrixA, rowA, colA, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;

        if(!fillMatrix(matrixB, rowB, colB, "Wprowadz dane drugiej macierzy (iczby oddzielone spacja):"))
            return false;

        double** result =  mlib::multiplyMatrix(matrixA, matrixB , rowA, colA, colB);
        mlib::printMatrix(result);

        mlib::deleteMatrix(result);
        mlib::deleteMatrix(matrixA);
        mlib::deleteMatrix(matrixB);
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
                double** result = mlib::createMatrix(rowA, colB);
                result = mlib::multiplyMatrix(matrixA, matrixB, AppInterface::rowA, AppInterface::colA, AppInterface::colB);
                mlib::printMatrix(result);
                mlib::deleteMatrix(result);
                return true;
            }
            else
                return false;
        }
        else if(flag0 == 'B')
        {
            if(AppInterface::colB == AppInterface::rowA)
            {
                double** result = mlib::createMatrix(AppInterface::rowA, AppInterface::colB);
                result = mlib::multiplyMatrix(matrixB, matrixA, AppInterface::rowB, AppInterface::colB, AppInterface::colA);
                mlib::printMatrix(result);
                mlib::deleteMatrix(result);
                return true;
            }
            else
                return false;
        }
        return false;
    }
}

bool AppInterface::multiplyByScalar(int row, int col, double scalar, char flag)
{
    if(flag == 'N')
    {
        double** matrix = mlib::createMatrix(row, col);

        if(!fillMatrix(matrix, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;

        double** result = mlib::multiplyByScalar(matrix, row, col, scalar);
        mlib::printMatrix(result);

        mlib::deleteMatrix(result);
        mlib::deleteMatrix(matrix);
        return true;
    }
    else if(flag == 'A')
    {
        if(matrixA == nullptr)
            return false;
        double** result = mlib::multiplyByScalar(matrixA, rowA, colA, scalar);
        mlib::printMatrix(result);
        mlib::deleteMatrix(result);
        return true;
    }
    else if(flag == 'B')
    {
        if(matrixB == nullptr)
            return false;
        double** result = mlib::multiplyByScalar(matrixB, rowB, colB, scalar);
        mlib::printMatrix(result);
        mlib::deleteMatrix(result);
        return true;
    }
    return false;
}

bool AppInterface::transpozeMatrix(int row, int col, char flag)
{
    if(flag == 'N')
    {
        double** matrix = mlib::createMatrix(col, row);
        if(!fillMatrix(matrix, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;

        double** result = mlib::transpozeMatrix(matrix, row, col);
        mlib::printMatrix(result);

        mlib::deleteMatrix(matrix);
        mlib::deleteMatrix(result);
        return true;
    }
    else if(flag == 'A')
    {
        if(matrixA == nullptr)
            return false;

        double** result = mlib::transpozeMatrix(matrixA, rowA, colA);
        mlib::swap(rowA, colA);
        mlib::printMatrix(result);

        mlib::deleteMatrix(result);
        return true;
    }
    else if(flag == 'B')
    {
        if(matrixB == nullptr)
            return false;

        double** result = mlib::transpozeMatrix(matrixB, rowB, colB);
        mlib::swap(rowB, colB);
        mlib::printMatrix(result);

        mlib::deleteMatrix(result);
        return true;
    }
    else
        return false;
}

bool AppInterface::powerMatrix(int row, int col, unsigned int power, char flag)
{
    if(flag == 'N')
    {
        double** matrix = mlib::createMatrix(row, col);
        if(!fillMatrix(matrix, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;
        double** result = mlib::powerMatrix(matrix,row, col, power);
        mlib::printMatrix(result);

        mlib::deleteMatrix(result);
        mlib::deleteMatrix(matrix);
        return true;
    }
    else if(flag == 'A')
    {
        if(matrixA == nullptr)
            return false;

        double** result = mlib::powerMatrix(matrixA, rowA, colA, power);
        mlib::printMatrix(result);

        mlib::deleteMatrix(result);
        return true;
    }
    else if(flag == 'B')
    {
        if(matrixB == nullptr)
            return false;

        double** result = mlib::powerMatrix(matrixB, rowB, colB, power);
        mlib::printMatrix(result);

        mlib::deleteMatrix(result);
        return true;
    }

    return false;
}

bool AppInterface::matrixIsDiagonal(int row, int col, char flag)
{
    if(flag == 'N')
    {
        double** matrix = mlib::createMatrix(row, col);
        if(!fillMatrix(matrix, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;

        bool result = mlib::matrixIsDiagonal(matrix, row, col);
        std::cout<<result<<std::endl;

        mlib::deleteMatrix(matrix);
        return true;
    }
    else if(flag == 'A')
    {
        if(matrixA == nullptr)
            return false;
        std::cout<<mlib::matrixIsDiagonal(matrixA, rowA, colA)<<std::endl;
        return true;
    }
    else if(flag == 'B')
    {
        if(matrixB == nullptr)
            return false;
        std::cout<<mlib::matrixIsDiagonal(matrixB, rowB, colB)<<std::endl;
        return true;
    }

    return false;
}

bool AppInterface::sortRow(int row, int col, int rowToSort, char flag)
{
    if(flag == 'N')
    {
        double** matrix = mlib::createMatrix(row, col);
        if(!fillMatrix(matrix, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;
        if(rowToSort >= row)
            return false;

        mlib::sortRow(*(matrix + rowToSort), col);
        mlib::printMatrix(matrix);

        mlib::deleteMatrix(matrix);
        return true;
    }
    else if(flag == 'A')
    {
        if(matrixA == nullptr)
            return false;
        double** result = mlib::createMatrix(rowA, colA);
        mlib::matrixcpy(result, matrixA, rowA, colA);

        mlib::sortRow(*(result + rowToSort), colA);
        mlib::printMatrix(result);

        mlib::deleteMatrix(result);
        return true;
    }
    else if(flag == 'B')
    {
        if(matrixB == nullptr)
            return false;
        double** result = mlib::createMatrix(rowB, colB);
        mlib::matrixcpy(result, matrixB, rowB, colB);

        mlib::sortRow(*(result + rowToSort), colB);
        mlib::printMatrix(result);

        mlib::deleteMatrix(result);
        return true;
    }
    return false;
}

bool AppInterface::sortRowsInMatrix(int row, int col, char flag)
{
    if(flag == 'N')
    {
        double** matrix = mlib::createMatrix(row, col);
        if(!fillMatrix(matrix, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;

        mlib::sortRowsInMatrix(matrix, row, col);
        mlib::printMatrix(matrix);

        mlib::deleteMatrix(matrix);
        return true;
    }
    else if(flag == 'A')
    {
        if(matrixA == nullptr)
            return false;
        double** result = mlib::createMatrix(rowA, colA);
        mlib::matrixcpy(result, matrixA, rowA, colA);

        mlib::sortRowsInMatrix(result, rowA, colA);
        mlib::printMatrix(result);

        mlib::deleteMatrix(result);
        return true;
    }
    else if(flag == 'B')
    {
        if(matrixA == nullptr)
            return false;
        double** result = mlib::createMatrix(rowB, colB);
        mlib::matrixcpy(result, matrixB, rowB, colB);

        mlib::sortRowsInMatrix(result, rowB, colB);
        mlib::printMatrix(result);

        mlib::deleteMatrix(result);
        return true;
    }
    return false;
}

bool AppInterface::determinantMatrix(int row, int col, char flag)
{
    if(flag == 'N')
    {
        double** matrix = mlib::createMatrix(row, col);
        if(!fillMatrix(matrix, row, col, "Wprowadz dane pierwszej macierzy (iczby oddzielone spacja):"))
            return false;

        double result = mlib::determinantMatrix(matrix, row, col);
        std::cout<<result<<std::endl;

        mlib::deleteMatrix(matrix);
        return true;
    }
    else if(flag == 'A')
    {
        if(matrixA == nullptr)
            return false;
        std::cout<<mlib::determinantMatrix(matrixA, rowA, colA)<<std::endl;
        return true;
    }
    else if(flag == 'B')
    {
        if(matrixB == nullptr)
            return false;
        std::cout<<mlib::determinantMatrix(matrixB, rowB, colB)<<std::endl;
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
            mlib::deleteMatrix(matrixA);
        matrixA = mlib::createMatrix(row, col);
        rowA = row;
        colA = col;
        return fillMatrix(matrixA, row, col, "Wprowadz dane do macierzy (liczby oddzielone spacja):");
    }
    else if (flag == 'B')
    {
        if(matrixB != nullptr)
            mlib::deleteMatrix(matrixB);
        matrixB = mlib::createMatrix(row, col);
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
        mlib::deleteMatrix(matrixA);
    if(matrixB != nullptr)
        mlib::deleteMatrix(matrixB);
}