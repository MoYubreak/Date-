#pragma once
#include<iostream>
using namespace std;



class Date
{

	friend ostream& operator<<(ostream& out, const Date& date);
	friend istream& operator>>(istream& cin,  Date& date);
public:

	Date(int year = 0, int month = 0, int day = 0);

	~Date();

	Date(const Date& date);

	int GetMonthDay(int year, int month);

	bool operator>(const Date& date);
	bool operator<(const Date& date);
	bool operator>=(const Date& date);
	bool operator<=(const Date& date);
	bool operator==(const Date& date);
	bool operator!=(const Date& date);

	Date operator+(int day);
	Date& operator+=(int day);
	Date operator-(int day);
	Date& operator-=(int day);
	Date& operator=(const Date& date);

	int operator-(const Date& date);
	int operator-=(const Date& date);

	Date operator++(int);
	Date& operator++();
	Date operator--(int);
	Date& operator--();

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out , const Date& date);
istream& operator>>(istream& cin, const Date& date);