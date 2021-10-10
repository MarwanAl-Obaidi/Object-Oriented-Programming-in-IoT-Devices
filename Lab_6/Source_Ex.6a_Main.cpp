#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Time.h"
#include "Source_Ex.6a_Header.h"
#pragma warning (disable:4996)
#pragma once


using namespace std;

void print(const vector<Time>& v)
{
	for (auto& t : v)
	{
		cout << t << endl;
	}
}

int main()
{
	Time time1 = Time(0, 0), time2 = Time(0, 0), duration = Time(0, 0);
	time1.read("Enter time 1");
	time2.read("Enter time 2");
	if (time1 < time2)
	{
		duration = time2 - time1;
		cout << "Starting time was (time 2 larger) " << time1 << endl;
	}
	else if (time1 > time2)
	{
		duration = time1 - time2;
		cout << "Starting time was (time 1 larger) " << time2 << endl;
	}
	else if (time1 == time2)
	{
		duration = time1 - time2;
		cout << "Starting time was (time 1 & 2  are equal) " << time2 << endl;
	}

	cout << "Duration was " << duration << endl;

	vector<Time> tv(5);
	for (auto& t : tv)
	{
		t.read("Enter the Time");
	}

	cout << "Times: " << endl;
	print(tv);

	Time sum = Time(0, 0);
	for (auto t : tv)
	{
		sum = sum + t;
	}

	cout << "Sum of times: " << sum << endl;

	cout << "Post-increment: " << endl;

	for (auto& t : tv)
	{
		cout << t++ << endl;
	}
	cout << "----" << endl;
	print(tv);

	cout << "Pre-increment: " << endl;
	for (auto& t : tv)
	{
		cout << ++t << endl;
	}

	sort(tv.begin(), tv.end());

	cout << "Sorted times: " << endl;
	print(tv);

	return 0;
}

void Time::read(const char* input)
{
	int found = 1;
	do
	{
		cout << input << " [HH MM] : ";
		cin >> *this;

		if (hour < 24 && hour >= 0 && minute < 60 && minute >= 0)
		{
			found = 0;
		}
		else
		{
			printf("\nWrongly inputted, restart the application and try again!");
		}
	} while (found != 0);
}

istream& operator>>(istream& in, Time& time)
{
	cin >> time.hour >> time.minute;
	return in;
}

ostream& operator<<(ostream& out, const Time& time)
{
	out << setiosflags(ios::right) << setfill(' ') <<
		setw(2) << time.hour << ":" << setfill('0')
		<< setw(2) << time.minute;
	return out;
}

Time::Time(int hh, int mm) : hour(hh), minute(mm)
{
	//empty for start
}

Time& Time::operator++()
{
	minute = hour * 60 + minute;
	minute++;
	hour = minute / 60;
	hour = hour % 24;
	minute = minute % 60;
	return *this;
}

Time Time::operator++(int)
{
	Time rev = *this;
	minute = hour * 60 + minute;
	minute++;
	hour = minute / 60;
	hour = hour % 24;
	minute = minute % 60;
	return rev;
}

Time Time::operator+(const Time& mr_thn) const
{
	int minutes_o;
	int minutes_t;
	int time_f;
	Time return_calc = Time(0, 0);
	minutes_o = hour * 60 + minute;
	minutes_t = mr_thn.hour * 60 + mr_thn.minute;
	time_f = minutes_o + minutes_t;
	return_calc.hour = time_f / 60;
	return_calc.hour = return_calc.hour % 24;
	return_calc.minute = time_f % 60;
	return return_calc;
}

Time Time::operator-(const Time& lss_thn) const
{
	int minutes_o;
	int minutes_t;
	int time_f;
	Time return_calc = Time(0, 0);
	minutes_o = hour * 60 + minute;
	minutes_t = lss_thn.hour * 60 + lss_thn.minute;
	time_f = minutes_o - minutes_t;
	return_calc.hour = time_f / 60;
	return_calc.hour = return_calc.hour % 24;
	return_calc.minute = time_f % 60;

	return return_calc;
}

bool Time::operator<(const Time& lss_thn) const
{
	int minutes_o;
	int minutes_t;
	int time_f;
	minutes_o = hour * 60 + minute;
	minutes_t = lss_thn.hour * 60 + lss_thn.minute;
	time_f = minutes_t - minutes_o;

	if (time_f > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Time::operator>(const Time& mr_thn) const
{
	int minutes_o;
	int minutes_t;
	int time_f;
	minutes_o = hour * 60 + minute;
	minutes_t = mr_thn.hour * 60 + mr_thn.minute;
	time_f = minutes_o - minutes_t;
	if (time_f > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Time::operator==(const Time& equal) const
{
	int minutes_o;
	int minutes_t;
	int time_f;
	minutes_o = hour * 60 + minute;
	minutes_t = equal.hour * 60 + equal.minute;
	time_f = minutes_o - minutes_t;
	if (time_f == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}