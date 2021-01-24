#pragma once
#ifndef SORT_H
#define SORT_H
#include "Array.h"
#include <iostream>
template<class T>
void sort(Array<T>&array, const int& count)
{
    for (int i = 1; i < count; i++)
        for (int j = i; j > 0 && array[j] < array[j - 1]; j--)
            std::swap(array[j - 1], array[j]);
}
#endif