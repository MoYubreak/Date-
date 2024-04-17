#include"Date.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

Date::~Date()
{

}

Date::Date(const Date& date)
{
	_year = date._year;
	_month = date._month;
	_day = date._day;
}

int Date::GetMonthDay(int year, int month)
{
	const int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0))
	{
		return 29;
	}
	else
	{
		return arr[month];
	}
}

bool Date::operator>(const Date& date)
{
	if (_year > date._year)
	{
		return true;
	}
	else if (_year == date._year)
	{
		if (_month > date._month)
		{
			return true;
		}
		else if (_month == date._month)
		{
			if (_day > date._day)
			{
				return true;
			}
		}
	}
	return false;
}
bool Date::operator<(const Date& date)
{
	return !((*this) > date) && !((*this) == date);
}
bool Date::operator>=(const Date& date)
{
	return !((*this) < date);
}
bool Date::operator<=(const Date& date)
{
	return !((*this) > date);
}
bool Date::operator==(const Date& date)
{
	return _year == date._year && _month == date._month && _day == date._day;
}

bool Date::operator!=(const Date& date)
{
	return !((*this) == date);
}

Date Date::operator+(int day)
{
	Date op = *this;
	op += day;
	return op;
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date op = *this;
	op -= day;
	return op;
}
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
Date& Date::operator=(const Date& date)
{
	_year = date._year;
	_month = date._month;
	_day = date._day;
	return *this;
}

int Date::operator-(const Date& date)
{
	Date d = *this;
	return d -= date;
}
int Date::operator-=(const Date& date)
{
	Date max = *this;
	Date min = date;
	int fl = 1;
	if (max < min)
	{
		max = min;
		min = *this;
		fl = -1;
	}

	int n = 0;
	while (min < max)
	{
		min += 1;
		n++;
	}
	return n*fl;
}

Date Date::operator++(int)
{
	Date date = *this;
	*this += 1;
	return date;
}
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
Date Date::operator--(int)
{
	Date date = *this;
	*this -= 1;
	return date;
}
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

ostream& operator<<(ostream& out, const Date& date)
{
	out << date._year << "年 " << date._month << "月 " << date._day << "日 ";
	return out;
}
istream& operator>>(istream& cin, Date& date)
{
	cout << "请依次输入 年  月  日" << endl;
	cin >> date._year >> date._month >> date._day;
	return cin;
}