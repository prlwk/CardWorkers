#include <iostream>
#include <Windows.h>
#include <fstream>
#include "Array.h"
#include "Worker.h"
#include "oldestWorker.h"
#include "sort.h"
#include "string.h"
#include "Date.h"
#include "makeList.h"
#include <iomanip>
int main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
std::ifstream in;    
std::ofstream out;
String nameFile;
std::cout << "Введите имя файла: ";
std::cin >> nameFile;
in.open(nameFile.getStr());
if (!in.is_open())
{
    std::cout << "Ошибка открытия файла!" << std::endl;
    return -1;
}
std::cout << "Файл с данными открыт октрыт!" << std::endl;
int quantity=0;
char a;
while (!in.eof())
{
    in.get(a);
    if (a =='\n')
    quantity++;
}
in.close();
in.open(nameFile.getStr());
std::cout << std::endl;
Array<Worker> Workers(quantity-1);
for (int i = 0; i < quantity-1; i++)
{
    in >> Workers[i];
}
in.close();
String nameFile1;
std::cout << "Введите имя файла для вывода данных: ";
std::cin >> nameFile1;
out.open(nameFile1.getStr());
out << "Таблица полученная из файла: " << '\n';
out << std::setw(20) << "ФИО" << std::setw(15) << "ИНН" << std::setw(25) << "Должность" << std::setw(15) << "Год приёма" << std::setw(20) << "Дата рождения" << std::setw(13) << "Зарплата" << std::endl;

for (int i = 0; i < quantity-1; i++)
{
    out<< Workers[i];
}
oldestWorker(Workers, quantity-1);
out << "Самый старший сотрудник: " << oldestWorker(Workers, quantity).getName() << std::endl << "Его дата рождения: " << oldestWorker(Workers, quantity).getDateOfBirth() << std::endl;
sort(Workers, quantity-1);
out << "Таблица после сортировки: "<<'\n';
out << std::setw(20) << "ФИО" << std::setw(15) << "ИНН" << std::setw(25) << "Должность" << std::setw(15) << "Год приёма" << std::setw(20) << "Дата рождения" << std::setw(13) << "Зарплата" << std::endl;
for (int i = 0; i < quantity-1; i++)
{
out << Workers[i];
}
Array<String> List;
makeList(Workers, List);
out << "Таблица должностей: " << '\n';
out << std::setw(7) << "Код" << std::setw(25) << "Должность" << std::endl;
for (int i = 0; i < List.GetSize(); i++)
{
out << std::setw(7) << i + 1 << std::setw(25) << List[i] << std::endl;
}
out.close();
return 0;
}
