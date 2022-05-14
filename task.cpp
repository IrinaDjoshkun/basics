#include <iostream>
using namespace std;

// Задание №1 и №5.

namespace MyLib
{

    void InitArr(float* arr, size_t size)
    {
        srand(time(0));
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand();
        }
        return;
    }

    void PrintArr(float* arr, size_t size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
        return;
    }

    void CountDigits(float* arr, size_t size)
    {
        int pos = 0;
        int neg = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > 0)
                ++pos;
            else if (arr[i] < 0)
                ++neg;
        }

        cout << "Amount of positive numbers is:  " << pos << endl;
        cout << "Amount of negative numbers is:  " << neg << endl;

        return;
    }

}

// Задание №2.

#define COMPARE(a, b) if (((a) >= 0) && ((a) < (b))) cout << "true" << endl; else cout << "false" << endl;

// Задание №3.

#define SIZING(a) cout << "Please, enter a size of the array: "; cin >> a;
#define SwapINT(a, b) if((a)>(b)) {int foo = (a); (a)=(b); (b) = foo;};

void SortMass(int* array, int size)
{
    for (int i = size - 1; i >= 1; i--)
        for (int j = 0; j < i; j++)
        {
            int foo;
            SwapINT(array[j], array[j + 1]);
        }
}

void PrintIntArray(int* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}


