#pragma once
#ifndef DATE_H
#define DATE_H
class Worker;
class Date
{
private:
	int day_;
	int mon_;
	int year_;
public:
	 Date();
	~Date();
	Date& operator =(const Date& d);
	friend Worker;
	friend bool operator ==(const Worker& worker1, const Worker worker2);
	friend void check(Worker& worker);
};
#endif
