#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include "Worker.h"
#include "string.h"
template <typename T>
class Array
{
private:
    size_t size;
    T* arr;
public:
    Array();
    Array(size_t);
    Array(Array<T>&);
    ~Array();
    size_t GetSize()const;
    void Setarr();
    void GetArr();
    Array& operator=(const Array&);
    T& operator[](size_t);
};
template <typename T>
Array<T>::Array()
{
    arr = nullptr;
    size = 0;
}

template <typename T>
Array<T>::Array(size_t size)
{
    this->size = size;
    arr = new T[size];
}

template <typename T>
Array<T>::Array(Array<T>& ArrToCopy)
{
    arr = new T[ArrToCopy.size];
    for (size_t i = 0; i < ArrToCopy.size; i++) {
        arr[i] = ArrToCopy.arr[i];
    }
}
template <typename T>
Array<T>::~Array()
{
        delete[]arr;
}

template <typename T>
size_t Array<T>::GetSize()const
{
    return size;
}

template <typename T>
void Array<T>::Setarr()
{
    std::cout << "¬ведите " << size << " элементов через пробел: ";
    for (size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    std::cin.ignore();
}

template <typename T>
void Array<T>::GetArr()
{
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (&other != this)
    {
        if (size != other.size)
        {
            if (arr)
                delete[] arr;
            size = other.size;
            arr = new T[size];
        }

        for (size_t i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }

    return *this;
}
template <typename T>
T& Array<T>::operator[](size_t i)
{
    if (i<0 || i>size)
        std::cout << "ќшибочный индекс!" << std::endl;
    return arr[i];
}

#endif
