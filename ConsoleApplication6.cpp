﻿#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

//=======================================================================================================================================================================
/* 1. Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции: 
для инициализации массива (типа float), печати его на экран и подсчета количества отрицательных и положительных элементов. 
Вызывайте эти 3-и функции из main для работы с массивом.*/
/* 5. * Сделайте задание 1 добавив свой неймспейс во втором модуле (первое задание тогда можно не делать).*/
//=======================================================================================================================================================================

void task1()
{
    const int mysize = 10;
    float myarr[mysize];

    MyLib::InitArr(myarr, mysize);
    MyLib::PrintArr(myarr, mysize);
    MyLib::CountDigits(myarr, mysize);

    return;
}

//=======================================================================================================================================================================
/* 2. Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры) в диапазон от нуля 
(включительно) до переданного ей второго аргумента (исключительно) и возвращает true или false, вывести на экран «true» или «false».*/
//=======================================================================================================================================================================

void task2()
{
    size_t n1, n2;
    cout << "Enter the first number: ";
    cin >> n1;
    cout << "Enter the second number: ";
    cin >> n2;

    COMPARE(n1, n2);

    return;
}

//=======================================================================================================================================================================
/* 3. Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. Инициализируйте его через ввод с клавиатуры. 
Напишите для него свою функцию сортировки (например Пузырьком). Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). 
Вызывайте ее из цикла сортировки.*/
//=======================================================================================================================================================================



void task3()
{
    size_t size;
    SIZING(size);
    int* array = new int[size];
    cout << "Please, enter " << size << " values: " << endl;;
    for (size_t i = 0; i < size; i++) 
    {
        cin >> array[i];
    }
    cout << "Initialized array: ";
    PrintIntArray(array, size);
    SortMass(array, size);
    cout << "Sorted array: ";
    PrintIntArray(array, size);
    delete[] array;
    return;
}

//=======================================================================================================================================================================
/* 4. * Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack. 
Выделите динамически переменную этого типа. Инициализируйте ее. Выведите ее на экран и ее размер с помощью sizeof. 
Сохраните эту структуру в текстовый или двоичный файл.*/
//=======================================================================================================================================================================

struct Employee1 
{ 
    long id; 
    unsigned short age; 
    double salary;
};

#pragma pack(push, 1)
struct Employee2
{
    long id;
    unsigned short age;
    double salary;
};
#pragma pack(pop)

void task4()
{
    Employee2* e1 = new Employee2;
    *e1 = { 12354321, 32, 120'000.0 };

    cout << "ID: " << e1->id << endl;
    cout << "Age: " << e1->age << endl;
    cout << "Salary: " << e1->salary << endl;
    cout << "The size is " << sizeof(e1) << endl;

    const string file = "1.bin";
    ofstream f1(file, ios_base::binary);
    if (f1.is_open())
    {
        f1.write((char*)&e1, sizeof(e1));
        f1.close();
    }

    delete e1;
    return;

}