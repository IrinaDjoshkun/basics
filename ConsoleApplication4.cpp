﻿#include <iostream>
using namespace std;

//=================================================================================================================================================================================
//1. Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер. Вызвать эту функцию из main.
//=================================================================================================================================================================================

double myarr()
{
    const int size = 5;
    double arr[size] = { 1.123, 2.234, 3.345, 4.456, 5.567 };
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}



int main()
{
    myarr();
    return 0;
}

//=================================================================================================================================================================================
/* 2. Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. 
Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.*/
//=================================================================================================================================================================================

void Trytochange( int *arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i])
        {
            arr[i] = 0;
        }
        else
        {
            arr[i] = 1;
        }
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int size = 10;
    int arr[size] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    Trytochange(arr, size);
    
    return 0;
}

//=============================================================================================================================================================================
/* 3. Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. 
Вывести массив на экран.*/
//=============================================================================================================================================================================

bool IniArray(int* arrempt, const int size)
{
    int elm1 = 1;
    for (size_t i = 0; i < size; i++)
    {
        arrempt[i] = elm1;
        elm1 += 3;
        cout << arrempt[i] << " " << endl;
    }
    cout << endl;
    return true;
}

int main()
{
    const int mysize = 8;
    int myarrempt[mysize];

    IniArray(myarrempt, mysize); 

    return 0;
}

//=============================================================================================================================================================================
/* 4. * Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным), 
при этом метод должен циклически сместить все элементы массива на n позиций.*/
//=============================================================================================================================================================================

void task4()
{
    const int size = 5;
    int arr[size] = { 1,2,3,4,5 };
    int n;
    n = arr[size - 1];
    arr[0] = n;
    for (int i = size - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";

    }

    return ;

}

//=============================================================================================================================================================================
/* 5. Написать функцию, которой передается не пустой одномерный целочисленный массив, она должна вернуть истину если в массиве есть место, 
в котором сумма левой и правой части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false, 
checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти символы в массив не входят.*/
//=============================================================================================================================================================================

bool Checkbalance(int *arr, const int size)
{
    bool balanceExist = false;
    int TotalSumm = 0;
    for (int i = 0; i < size; i++)
    {
        TotalSumm = TotalSumm + arr[i];
    }
    int LeftSumm = 0;
    int RightSumm = 0;

    for (int i = 1; i < size - 1; i++)
    {
        LeftSumm += arr[i - 1];
        RightSumm = TotalSumm - arr[i] - LeftSumm;
        if (LeftSumm == RightSumm)
        {
            bool balanceExist = true;
        }
    }
    return true;
}

int main()
{
    const int mysize = 5;
    int myarr[mysize] = { 1,2,3,4,10 };
    if (Checkbalance(myarr, mysize))
    {
        cout << "true" << endl;
    }
    
    return 0;
}

