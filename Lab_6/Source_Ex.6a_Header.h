#include <iostream>
#pragma warning (disable:4996)
#pragma once


using namespace std;

class Time
{
public:
	void read(const char* number);
	Time operator+(const Time& mr_than) const;
	Time operator-(const Time& lss_thn) const;
	Time& operator++();
	Time operator++(int);
	bool operator<(const Time& lss_thn) const;
	bool operator>(const Time& mr_thn) const;
	bool operator==(const Time& equal) const;
	Time(int hh = 0, int mm = 0);

private:
	int hour;
	int minute;

	friend istream& operator>>(istream& in, Time& time);
	friend ostream& operator<<(ostream& out, const Time& time);
};