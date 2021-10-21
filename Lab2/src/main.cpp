#include <iostream>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <cstdlib>
#include "lab2.h"

using namespace std;

int main()
{
    cout<<"***********************************"<<endl;
    //1
    cout<<area(2)<<endl;
    cout<<area(2.0)<<endl;
    cout<<area(4,4)<<endl;
    cout<<"***********************************"<<endl;
    //2.1 2.2 2.3
    double* array = new double [5];
    for(int i = 0; i < 5; i++)
        array[i] = random(1, 100);
    cout<<"ARRAY: ";
    printArray(array);
    cout<<"MAX: "<<maxArrayValue(array)<<endl;
    cout<<"REVERSE: "<<endl;
    reverse(array);
    printArray(array);
    cout<<"***********************************"<<endl;
    //3.1 3.2 3.3 3.4
    double a = 10, b = 5;
        //1
    cout<<average(&a,&b)<<endl;
        //2
    loadPositives();
        //3
    printArray(array);
    bubleSort(array);
    printArray(array);
    delete [] array;
        //4
    int n = 10;
    int* wsk = new int;
    swap(n, wsk);
    cout<<*wsk<<endl;
    delete wsk;
    //4.1 4.2
        //1
    divide(2, 2);
    divide(2, 1);
    divide(2, 3);
    divide(2, -3);
        //2
    //correct
    convert("123");
    convert("-123");
    convert("2147483647");
    convert("-2147483648");
    //incorrect
    convert("-2147483649");
    convert("2147483649");
    convert("2187483649");
    convert("-9999999999999");

}

//Napisz funkcję, która będzie liczyła pole figury. Pole będzie zależne od ilości oraz typu argumentów.

//returns area of square
double area(double a)
{
    cout<<"SQUARE: a = "<<a<<endl;
    return a * a;
}

//returns area of triangle, a - base, h - height
double area(double a, double h)
{
    cout<<"TRIANGLE: a, h = "<<a<<" "<<h<<endl;
    return (a * h)  / 2;
}

//returns area of a circle, r - integer radius
double area(int r)
{
    cout<<"CIRCLE: r = "<<r<<endl;
    return M_PI * r * r;
}

// 2.1 Napisz funkcję zwracającą liczbę losową z przedziału <a, b>, gdzie a i b to argumenty tej funkcji

//returns random value in range of [a,b]
double random(double a, double b)
{
    static bool srandSet = false;
    if(!srandSet)
    {
        srand(time(nullptr));
        srandSet = true;
    }
    return a + (rand() * (b - a)) / RAND_MAX ;
}

// 2.2 Napisz funkcję, która zwraca największą wartość przechowywaną w tablicy jednowymiarowej. Przetestuj ją w prostym programie (użyj tablicy alokowanej dynamicznie, wypełnionej liczbami losowymi z przedziału <1, 100>).

//returns max value from array
double maxArrayValue(double * array)
{
    int size = _msize(array) / sizeof(double);
    if(size == 0)
        return 0;

    double max = array[0];
    for(int i = 1; i < size; i++)
        if(array[i] > max)
            max = array[i];
    return max;
}

// 3 Napisz funkcję, która zmienia kolejność elementów tablicy (odwraca tablicę), podanej do funkcji jako argument.

//reverse elements in array
void reverse(double* array)
{
    int size = _msize(array) / sizeof(double);
    for(int i = 0; i < size/2; i++)
        swap(array[i], array[size - i - 1]);
}

//prints array elements on screen
void printArray(double* array)
{
    int size = _msize(array) / sizeof(double);
    for(int i = 0; i < size; i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

// 3.1 Do napisania jest program pobierający 2 liczby oraz ustawi wskaźniki na ich adresach, a także obliczy ich średnią. Należy wykorzystać wskaźniki.

//returns average of numbers a, b
double average(double* a, double* b)
{
    return  (*a + *b) / 2;
}

// 3.2 Do napisania program gdzie wczytamy i wypiszemy na ekran elementy tablicy większe od 0 (należy użyć wskaźników).

void loadPositives()
{
    int size;
    cout<<"Podaj rozmiar danych wejsciowych"<<endl;
    cin>>size;
    cout<<"Wpisz kolejne liczby."<<endl;
    double * array = new double [size];
    int i = size;
    int iter = 0;
    double numberCandidate;
    while (i > 0)
    {
        i--;
        cin>>numberCandidate;
        if(numberCandidate > 0)
            array[iter++] = numberCandidate;
    }
    cout<<"Wczytane liczby to: "<<endl;
    for(int i = 0; i < iter; i++)
        cout<<array[i]<<" ";
    cout<<endl;
    delete [] array;

}

// 3.3 Do napisania jest funkcja do sortowania liczb, które są zapisane w zmiennych w rosnącej kolejności. Należy użyć wskaźników.

//sorts array
void bubleSort(double* array)
{
    int size = _msize(array) / sizeof(double);
    for(int i = 0; i < size; i++)
        for(int k = size - 1; k > i; k--)
        {
            if(array[k] < array[k - 1])
                swap(array[k], array[k - 1]);
        }
}

// 3.4 Proszę stworzyć funkcję, której argumentami będą liczba całkowita x oraz intowy wskaźnik w. Powinna ona wpisywać wartość x do zmiennej wskazywanej przez wskaźnik.

void swap(int x, int *w)
{
    *w = x;
}

// 4.1 Do napisania jest program wczytuje od użytkownika dwie liczby naturalne a i b. Program ma wypisać na ekran wynik dzielenia a przez b, a jeśli jest to niemożliwe to ma wypisać odpowiedni komunikat. Dzielenie będzie odbywać się w zbiorze liczb naturalnych, dlatego wynikiem dzielenia nie może być ułamek.

//divide operation: N x N -> N, prints error if result is not natural number
void divide(double a, double b)
{
    try
    {
        if(a <= 0 || b <= 0)
            throw "Invalid imput error !";
        if(b == 0)
            throw "Divide by 0.";

        double result = a / b;
        if(result != (int) result)
            throw "Result is not natural value.";

        cout<<"RESULT: "<<result<<endl;
    }
    catch (const char* msg)
    {
        cout<<msg<<endl;
    }

}

// 4.2 Do napisania jest funkcja, która wczyta od użytkownika linijkę zawierającą ciąg znaków. Program powinien następnie spróbować przekonwertować wprowadzony tekst na liczbę typu int. W trakcie konwersji program może zwrócić dwa wyjątki: Wprowadzony ciąg zawiera nieprawidłowe znaki oraz Wprowadzona liczba jest za duża. Na sam koniec program powinien wypisać skonwertowaną liczbę na ekran.

int compare(string a, string b)
{
    if(a[0] == '-' && b[0] != '-')
        return -1;
    if(a[0] != '-' && b[0] == '-')
        return 0;
    if(a[0] != '-' && b[0] != '-')
    {
        int diff = abs(a.length() - b.length());
        if(a.length() > b.length())
            return  1;
        if(a.length() < b.length())
            return  -1;
        for(int i = 0; i < a.length(); i++)
        {
            int tmp = a[i] - b[i];
            if(tmp != 0)
                return tmp;
        }
        return 0;
    }

    if(a[0] == '-' && b[0] == '-')
    {
        a[0] = '0';
        b[0] = '0';
        return compare(b, a);
    }
}

void convert(string num)
{
    try
    {
        for(int i = 0 ;i < num.size(); i++)
        {
            if(i == 0 && num[i] == '-')
                i++;
            if (num[i] < '0' || num[i] > '9')
                throw "Not a integer number.";
        }
        string maxINT = "2147483647";
        string minInt = "-2147483648";
        if(compare(num, maxINT) > 0 || compare(num, minInt) < 0)
            throw "TO LARGE / TO SMALL VALUE";
        cout<<"CONVERTED NUMBER: "<<atoi(num.c_str())<<endl;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
}
