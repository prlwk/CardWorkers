#include "Date.h"
Date::Date()
{
	day_ = 0;
	mon_ = 0;
	year_ = 0;
}
Date:: ~ Date(){}
Date& Date:: operator =(const Date& d)
{
	day_ = d.day_;
	mon_ = d.mon_;
	year_ = d.year_;
	return *this;
}