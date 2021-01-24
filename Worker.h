#ifndef WORKER_H
#define WORKER_H
#pragma once
#include "string.h"
#include "Date.h"
#include "Array.h"
class Worker
{
private:
	String name_;
	long long int INN_;
	String position_;
	int startYear_;
	Date birthDate_;
	String dateOfBirth_;
	double salary_;
	int searchSpace();
	int searchError(int position);
public:
	Worker();
	Worker(String lastname, String name, String birthDate, long long int INN, String position, int startYear, int salary);
	Worker(const Worker& reff);
	~Worker();
	Worker operator + (const double k);
	Worker & operator = (const Worker& worker);
	String getName();
	String getDateOfBirth();
	int getStartYear();
	String getPosition();
	bool operator > (const Worker& worker);
	bool operator < (const Worker& worker);
	Worker & operator ++();
	friend Worker operator ++(Worker&, const int);
	friend Worker operator -(const Worker& worker1, const double k);
	friend bool operator ==(const Worker& worker1, const Worker worker2);
	friend bool operator !=(const Worker& worker1, const Worker worker2);
	friend std::ostream& operator <<(std::ostream& out, const Worker& worker);
	friend std::istream& operator >>(std::istream& in, Worker& worker);
	friend std::ifstream& operator >>(std::ifstream& is, Worker& worker);
	friend std::ofstream& operator << (std::ofstream& out, const Worker& worker);
	friend void check(Worker& worker);
};
#endif