#include <iostream>
#include <string>
#pragma warning (disable:4996)


using namespace std;

//starting point code has been modified for easier undertanding.
class Counter
{
	friend ostream& operator<< (ostream& outp, const Counter& ct);
public:
	Counter(int count_full = 0);
	virtual void increase() = 0;
	virtual void decrease() = 0;
	virtual ~Counter() {};
	virtual operator int() = 0;
protected:
	int count_full;
};

Counter::Counter(int count_zero) : count_full(count_zero) {}

class LimitedCounter : public Counter
{
	friend ostream& operator<< (ostream& outp, const LimitedCounter& lct);
public:
	LimitedCounter(int count_zero = 0, int max_tot = 0);
	void increase();
	void decrease();
	operator int();
	virtual ~LimitedCounter() {};
private:
	int max_tot;
};

LimitedCounter::operator int()
{
	return count_full;
}

LimitedCounter::LimitedCounter(int count_zero, int max_zero) : max_tot(max_zero)
{
	count_full = count_zero; //ini
}

void LimitedCounter::increase()
{
	if (count_full < max_tot)
	{
		count_full++;
	}
}

void LimitedCounter::decrease()
{
	if (0 < count_full)
	{
		count_full--;
	}
}

class OverflowCounter : public Counter
{
	friend ostream& operator<< (ostream& outp, const OverflowCounter& oct);
public:
	OverflowCounter(int count_zero = 0, int max_tot = 0);
	void increase();
	void decrease();
	operator int();
	virtual ~OverflowCounter() {};
private:
	int max_tot;
};

OverflowCounter::OverflowCounter(int count_zero, int max_zero) : max_tot(max_zero)
{
	count_full = count_zero;
}

void OverflowCounter::increase()
{
	if (count_full < max_tot)
	{
		count_full++;
	}
	else
	{
		count_full = 0;
	}
}

void OverflowCounter::decrease()
{

	if (count_full > 0)
	{
		count_full--;
	}
	else
	{
		count_full = max_tot;
	}
}

OverflowCounter::operator int()
{
	return count_full;
}

ostream& operator<< (ostream& outp, const Counter& ct)
{
	outp << ct.count_full;
	return outp;
}

ostream& operator<< (ostream& outp, const LimitedCounter& lct)
{
	outp << lct.count_full;
	return outp;
}

ostream& operator<< (ostream& outp, const OverflowCounter& oct)
{
	outp << oct.count_full;
	return outp;
}

void UseCounter(Counter& ctr, int num);

void UseCounter(Counter& ctr, int num)
{
	int count_full = (num < 0) ? num : 0;
	for (count_full; count_full < num; count_full++)
	{
		ctr.increase();
	}
	for (count_full; count_full < 0; count_full++)
	{
		ctr.decrease();
	}
}

int main(int argc, char** argv)
{
	LimitedCounter lc(0, 5);
	OverflowCounter oc(5, 9);

	cout << oc << endl;
	UseCounter(oc, 5);
	cout << oc << endl; // should display zero
	UseCounter(oc, -1);
	cout << oc << endl; // should display 9
	oc.decrease();
	cout << oc << endl; // should display 8

	cout << lc << endl;
	lc.increase();
	cout << lc << endl;
	lc.decrease();
	cout << lc << endl;
	for (int i = 0; i < 10; ++i) lc.increase();
	cout << lc << endl;
	UseCounter(lc, -9);
	cout << lc << endl;

	return 0;
}