
#include<iostream>
#include <iomanip>
#include <fstream>
#include "Worker.h"
#include "string.h"
#include "Date.h"
#include "Array.h"
Worker::Worker()
{
	name_ = "NONAME";
	INN_ = 0;
	position_ = "-";
	startYear_ = -1;
	birthDate_.day_ = 0;
	birthDate_.mon_ = 0;
	birthDate_.year_ = 0;
	dateOfBirth_ = "NO DATE";
	salary_ = 0;
}
Worker::Worker(String lastname, String name, String birthDate, long long int INN, String position, int startYear, int salary)
{  
	String space = " ";
	name_ = lastname + space + name;
	String f, n;
	while (searchError(searchSpace()) != 0 || name_[0] > 'Я' || name_[0] < 'А' || name_[searchSpace() + 1]>'Я' || name_[searchSpace() + 3] < 'А' || name_[searchSpace() + 2] != '.' || name_[searchSpace() + 4] != '.' || name_.length() != searchSpace() + 5)
	{
		std::cout << std::endl << "Фамилия и/или инициалы сотрудника " << name_ << " указаны неверно! Введите ещё раз: ";
		std::cin >> f >> n;
		name_ = f + space + n;
	}   
	String inn;
		while (INN < 100000000000 || INN>999999999999)
		{
			std::cout << std::endl << "ИНН " << name_ << " указан неверно! ИНН должен состоять из 12 цифр! Введите ещё раз: ";
			std::cin >> inn;
			INN = MyStoi(inn);
		}
	INN_ = INN;
	position_ = position;
	String StartYear;
	while (startYear < 1900 || startYear>2020)
	{
		std::cout <<std::endl << "Год начала работы сотрудника " << name_ << " указан неверно! Год должен состоять из 4 цифр и быть не меньше 1900 и не больше 2020! Введите ещё раз: ";
			std::cin >> StartYear;
			startYear = MyStoi(StartYear);
	}
	startYear_ = startYear;

	int count = 0;
	while (count != 1)
	{
		if ((birthDate[2] != '.' || birthDate[5] != '.' || birthDate.length() != 10))
		{
			std::cout << std::endl << "Дата рождения сотрудника " << name_ << " введена неверно! Введите еще раз:";
			std::cin >> birthDate;
			continue;

	    }
		dateOfBirth_ = birthDate;
		int day = MyStoi(birthDate);
		birthDate.erase(0, 3);
		int mon = MyStoi(birthDate);
		birthDate.erase(0, 3);
		int year = MyStoi(birthDate);
		if ((year <= 2020 && year >= 1900) && (day > 0 && day <= 31 && (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)) || (day > 0 && day < 31 && (mon == 4 || mon == 6 || mon == 9 || mon == 11)) || (mon == 2 && day > 0 && day < 29) || (mon == 2 && day > 0 && day < 29 && year % 4 == 0))
		{
			birthDate_.day_ = day;
			birthDate_.mon_= mon;
			birthDate_.year_= year;

			count++;
		}
		else
		{
			std::cout << std::endl << "Дата рождения сотрудника " << name_ << " введена неверно! Введите еще раз:";
			std::cin >> birthDate;

		}
	}
	while (salary < 0)
	{
		std::cout << std::endl << "Зарплата сотрудника " << name_ << " введена неверно! Введите еще раз:";
		std::cin >> salary;
	}
	salary_ = salary;
}
Worker::Worker(const Worker&reff)
{
	name_=reff.name_;
	INN_=reff.INN_;
	position_=reff.position_;
	startYear_=reff.startYear_;
	birthDate_=reff.birthDate_;
	dateOfBirth_ = reff.dateOfBirth_;
	salary_=reff.salary_;
}
Worker::~Worker() {};
String Worker::getName()
{
	return this->name_;
}
String Worker:: getDateOfBirth()
{
	return dateOfBirth_;
}
int Worker::getStartYear()
{
	return startYear_;
}
String Worker::getPosition()
{
	return position_;
}
Worker Worker:: operator + (const double k)
{
	Worker time;
	time = *this;
	time.salary_ = this->salary_ + k;
	return time;
}
Worker & Worker:: operator = (const Worker& reff)
{
		name_ = reff.name_;
		INN_ = reff.INN_;
		position_ = reff.position_;
		startYear_ = reff.startYear_;
		birthDate_ = reff.birthDate_;
		dateOfBirth_ = reff.dateOfBirth_;
		salary_ = reff.salary_;
	
	return *this;
}
bool Worker::operator > (const Worker& worker)
{
	if (this->birthDate_.year_ < worker.birthDate_.year_)
		return true;
	else if (this->birthDate_.year_ == worker.birthDate_.year_)
	{
		if (this->birthDate_.mon_ < worker.birthDate_.mon_)
			return true;
		else if (this->birthDate_.mon_ == worker.birthDate_.mon_)
		{
			if (this->birthDate_.day_ < worker.birthDate_.day_)
				return true;
			else
				return false;
		}
		else
		return false;
	}
	else
		return false;
}
bool Worker::operator < (const Worker& worker)
{
	
	return (this->startYear_> worker.startYear_);
}
Worker operator - (const Worker& worker, const double k)
{
	Worker time;
	time = worker;
	time.salary_ = worker.salary_ - k;
	return time;
}
Worker & Worker:: operator ++()
{
	salary_ = salary_ + 1000;
	return *this;
}
Worker operator ++(Worker& worker, const int)
{
	Worker temp = worker;
	worker.salary_ = worker.salary_ + 1000;
	return temp;
}
bool operator ==(const Worker& worker1, const Worker worker2)
{   
return ((worker1.birthDate_.year_ == worker2.birthDate_.year_) && (worker1.birthDate_.mon_ == worker2.birthDate_.mon_) &&(worker1.birthDate_.day_ == worker2.birthDate_.day_));
}
bool operator !=(const Worker& worker1, const Worker worker2)
{
	return !(worker1 == worker2);
}
std::ostream& operator << (std::ostream& out, const Worker& worker)
{
	out << worker.name_ << std::setw(15)<< worker.INN_ << std::setw(25) << worker.position_ << std::setw(8) << worker.startYear_ << std::setw(20) << worker.dateOfBirth_ << std::setw(13) << worker.salary_ << "руб." << std::endl;
	return out;
}
std::ofstream& operator << (std::ofstream& out, const Worker& worker)
{
	out << std::setw(20)<< worker.name_ << std::setw(15) << worker.INN_ << std::setw(25) << worker.position_ << std::setw(15) << worker.startYear_ << std::setw(20) << worker.dateOfBirth_ << std::setw(10) << worker.salary_ << "руб." << std::endl;
	return out;
}
std::istream& operator >>(std::istream& is, Worker& worker)
{
	std::cout << "Введите данные о сотруднике: фамилию и инициалы, ИНН, должность, год начала работы, дату рождения, зарплату: " << std::endl;
	char* BUFF = new char[2048];
	char a = '-';
	int counter = 0;
	int count = 0;
	while (a != '\n')
	{
		a = is.get();
		if (a == ' ' && counter == 0)
			continue;
		if (a == ' ' || a == '\n')
			break;
		BUFF[counter] = a;
		counter++;
	}
	String S = "0";
		BUFF[counter] = ' ';
		counter++;
		BUFF[counter] = '\0';
		S = BUFF;
		S[counter] = '\0';
	count = counter;
	counter = 0;
	while (a != '\n')
	{
		a = is.get();
		if (a == ' ' && counter == 0)
			continue;
		if (a == ' ' || a == '\n')
			break;
		BUFF[counter] = a;
		counter++;
	} 
	String S1 = "0";
	BUFF[counter] = '\0';
	S1 = BUFF;
	worker.name_ = S + S1;
	worker.name_[count+counter] = '\0';
	a = '5';
	counter = 0;
	while (a != '\n')
	{
		a = is.get();
		if (a == ' ' && counter == 0)
			continue;
		if (a == ' ' || a == '\n')
			break;
		BUFF[counter] = a;
		counter++;
	}
	BUFF[counter] = '\0';
	int i = 0;
	String S2 = BUFF;
	worker.INN_ = MyStoi(S2);
	counter = 0;
	while ((a <'1' &&  a>'9' )|| a!='\n')
	{
		a = is.get();
		if (a == ' ' && counter == 0)
			continue;
		if (a >= '1' && a<='9')
			break;
		BUFF[counter] = a;
		counter++;
	}
	BUFF[counter-1] = '\0';
	String S3;
	S3 = BUFF;
	worker.position_ = S3;
	BUFF[0] = a;
	counter = 1;
	while (a != '\n')
	{
		a = is.get();
		if (a == ' ' || a == '\n')
			break;
		BUFF[counter] = a;
		counter++;
	}
	BUFF[counter] = '\0';
	String S4 = BUFF;
	worker.startYear_ = MyStoi(S4);
	counter = 0;
	while (a != '\n')
	{
		a = is.get();
		if (a == ' ' && counter == 0)
			continue;
		if (a == ' ' || a == '\n')
			break;
		BUFF[counter] = a;
		counter++;
	}
	BUFF[counter] = '\0';
	String S5;
	S5 = BUFF;
	worker.dateOfBirth_ = S5;
	counter = 0;
	while (a != '\n')
	{
		a = is.get();
		if (a == ' ' && counter == 0)
			continue;
		if (a == ' ' || a == '\n')
			break;
		BUFF[counter] = a;
		counter++;
	}
	BUFF[counter] = '\0';
	String S6 = BUFF;
	if (S6[0] == '-')
		worker.salary_ = -1*(MyStoi(S6));
	else
		worker.salary_ = MyStoi(S6);
	delete[] BUFF;
	check(worker);
	return is;
}
void check(Worker& worker)
{
	String f, n, space=" ";
	while (worker.searchError(worker.searchSpace()) != 0||worker.name_[0] > 'Я' || worker.name_[0] < 'А' || worker.name_[worker.searchSpace() + 1]>'Я' || worker.name_[worker.searchSpace() + 3] < 'А' || worker.name_[worker.searchSpace() + 2] != '.' || worker.name_[worker.searchSpace() + 4] != '.' || worker.name_.length() != worker.searchSpace() + 5)
			{ 
				std::cout << std::endl << "Фамилия и/или инициалы сотрудника " << worker.name_ << " указаны неверно! Введите ещё раз: ";
				std::cin >> f>>n;
				worker.name_ = f + space + n;
			}
	String INN;
	while (worker.INN_ < 100000000000 || worker.INN_>999999999999)
	{   
		std::cout << std::endl << "ИНН " << worker.name_ << " указан неверно! ИНН должен состоять из 12 цифр! Введите ещё раз: ";
		std::cin >> INN;
		worker.INN_ = MyStoi(INN);
	}
	String SrartYear;
		while (worker.startYear_ < 1900 || worker.startYear_>2020)
		{
			std::cout << std::endl << "Год начала работы сотрудника " << worker.name_ << " указан неверно! Год должен состоять из 4 цифр и быть не меньше 1900 и не больше 2020! Введите ещё раз: ";
			std::cin >> SrartYear;
			worker.startYear_ = MyStoi(SrartYear);
		}
		while (worker.dateOfBirth_[2] != '.' || worker.dateOfBirth_[5] != '.' || worker.dateOfBirth_.length() != 10)
		{
			std::cout << std::endl << "Дата рождения сотрудника " << worker.name_ << " введена неверно! Введите еще раз:";
			std::cin >> worker.dateOfBirth_;
		}
		int count = 0;
		while (count != 1)
		{
			String TIME = worker.dateOfBirth_;
			int day = MyStoi(TIME);
			TIME.erase(0, 3);
			int mon = MyStoi(TIME);
			TIME.erase(0, 3);
			int year = MyStoi(TIME);
			if ((year <= 2020 && year >= 1900) && (day > 0 && day <= 31 && (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)) || (day > 0 && day < 31 && (mon == 4 || mon == 6 || mon == 9 || mon == 11)) || (mon == 2 && day > 0 && day < 29) || (mon == 2 && day > 0 && day < 29 && year % 4 == 0))
			{
				worker.birthDate_.day_ = day;
				worker.birthDate_.mon_ = mon;
				worker.birthDate_.year_ = year;

				count++;
			}
			else
			{
				std::cout << std::endl << "Дата рождения сотрудника " << worker.name_ << " введена неверно! Введите еще раз: ";
				std::cin >> worker.dateOfBirth_;

			}
		}
		String Salary;
		while (worker.salary_ <= 0)
		{
			std::cout << std::endl << "Зарплата сотрудника " << worker.name_ << " введена неверно! Введите еще раз: ";
			std::cin >> Salary;
			if (Salary[0] =='-')
			worker.salary_ = -1*(MyStoi(Salary));
			else 
				worker.salary_ = MyStoi(Salary);
		}
}
int Worker:: searchSpace()
{
	int position = -1;
	for (int i = 0; i < name_.length(); i++)
	{
		if (name_[i] == ' ')
		{
			position = i;
			break;
		}
	}
	return position;
}
int Worker::searchError(int position)
{
	int counter = 0;
	String f, n, space = " ";
	for (int i = 1; i < position; i++)
	{
		if (name_[i] > 'я' || name_[i] < 'а')
			counter++;
	}
	return counter;
}
std::ifstream& operator >>(std::ifstream& is, Worker& worker)
{
	char* BUFF = new char[2048];
	char a = '-';
	int counter = 0;
	int count = 0;
	while (a != '\n')
	{
		is.get(a);
		if (a == ' ' && counter == 0)
			continue;
		if ((a == ' ' || a == '\n'))
			break;
		BUFF[counter] = a;
		counter++;
	}
	String S = "0";
	BUFF[counter] = ' ';
	counter++;
	BUFF[counter] = '\0';
	S = BUFF;
	S[counter] = '\0';
	count = counter;
	counter = 0;
	while (a != '\n')
	{
		is.get(a);
		if (a == ' ' && counter == 0)
			continue;
		if (a == ' ' || a == '\n')
			break;
		BUFF[counter] = a;
		counter++;
	}
	String S1 = "0";
	BUFF[counter] = '\0';
	S1 = BUFF;
	worker.name_ = S + S1;
	worker.name_[count + counter] = '\0';
	a = '5';
	counter = 0;
	while (a != '\n')
	{
		is.get(a);
		if (a == ' ' && counter == 0)
			continue;
		if (a == ' ' || a == '\n')
			break;
		BUFF[counter] = a;
		counter++;
	}
	BUFF[counter] = '\0';
	int i = 0;
	String S2 = BUFF;
	worker.INN_ = MyStoi(S2);
	counter = 0;
	while ((a < '1' && a>'9') || a != '\n')
	{
		is.get(a);
		if (a == ' ' && counter == 0)
			continue;
		if (a >= '1' && a <= '9')
			break;
		BUFF[counter] = a;
		counter++;
	}
	BUFF[counter - 1] = '\0';
	String S3;
	S3 = BUFF;
	worker.position_ = S3;
	BUFF[0] = a;
	counter = 1;
	while (a != '\n')
	{
		is.get(a);
		if (a == ' ' || a == '\n')
			break;
		BUFF[counter] = a;
		counter++;
	}
	BUFF[counter] = '\0';
	String S4 = BUFF;
	worker.startYear_ = MyStoi(S4);
	counter = 0;
	while (a != '\n')
	{
		is.get(a);
		if (a == ' ' && counter == 0)
			continue;
		if (a == ' ' || a == '\n')
			break;
		BUFF[counter] = a;
		counter++;
	}
	BUFF[counter] = '\0';
	String S5;
	S5 = BUFF;
	worker.dateOfBirth_ = S5;
	counter = 0;
	while (a != '\n')
	{
		is.get(a);
		if (a == ' ' && counter == 0)
			continue;
		if (a == ' ' || a == '\n')
			break;
		BUFF[counter] = a;
		counter++;
	}
	BUFF[counter] = '\0';
	String S6 = BUFF;
	if (S6[0] == '-')
		worker.salary_ = -1*(MyStoi(S6));
	else
		worker.salary_ = MyStoi(S6);
	delete[] BUFF;
	check(worker);
	return is;
}