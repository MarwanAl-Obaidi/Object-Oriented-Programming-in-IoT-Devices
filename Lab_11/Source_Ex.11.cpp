#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#pragma warning (disable:4996)


using namespace std;

class Counter;

class Observer
{
public:
	virtual void HandleLimitReached(Counter* ctr) = 0;
};

class Counter
{
public:
	virtual void inc() = 0;
	virtual void dec() = 0;
	virtual operator int() = 0;
	virtual void SetObserver(Observer* obs) = 0;
	virtual ~Counter() {};
	virtual int GetInitial() = 0;

};

class CounterObserver : public Observer
{
public:

	void HandleLimitReached(Counter* ctr);

};

class OverflowCounter : public Counter
{
public:

	OverflowCounter(int u = 0);

	int GetInitial();

	vector <Observer*> obs;

	~OverflowCounter();

	void inc();
	void dec();
	operator int();

	void SetObserver(Observer* obs);

protected:

	int initial = 0;
	int final = 0;

private:

	void Notify();

};

class counter_limit : public Counter
{
public:

	counter_limit(int u = 0);

	int GetInitial();

	vector <Observer*> obs;

	~counter_limit();

	void SetObserver(Observer* obs);

	void inc();
	void dec();
	operator int();

protected:

	int initial = 0;
	int final = 0;

private:

	void Notify();

};


class CounterUser : public OverflowCounter
{
public:

	CounterUser(int num = 0);
	void IncrementBy(int n);

};

void UseCounter(Counter& ctr, int num);

int main(int argc, char** argv)
{
	printf("Ex.11.a\n\n");
	CounterUser cu(5);
	cu.SetObserver(new CounterObserver());
	cu.IncrementBy(12); //OUTPUT: twotimes "Limit has been reached"

	CounterUser cu2(9);
	cu2.SetObserver(new CounterObserver());
	cu2.IncrementBy(9);
	cout << "Just passing time" << endl;
	cu2.IncrementBy(1); //OUTPUT: "Limit has been reached"

	printf("\nEx.11.b\n\n");

	CounterObserver* first_observation = new CounterObserver();
	CounterObserver* second_observation = new CounterObserver();
	CounterObserver* third_observation = new CounterObserver();

	counter_limit limit_count(10);
	OverflowCounter over_count(10);

	limit_count.SetObserver(first_observation);
	over_count.SetObserver(second_observation);

	limit_count.SetObserver(third_observation);
	over_count.SetObserver(third_observation);


	printf("Limited\n\n");
	UseCounter(limit_count, 12);

	printf("\nOverflow\n\n");
	UseCounter(over_count, 12);

	return 0;

}
//UserCounter funct
void UseCounter(Counter& ctr, int num)
{
	if (num > 0)
	{
		for (int i = 0; i < num; i++)
		{
			ctr.inc();
		}
	}
	if (num < 0)
	{
		for (int i = 0; i > num; i--)
		{
			ctr.dec();
		}
	}

}

CounterUser::CounterUser(int n)
{
	final = n;
}

void OverflowCounter::SetObserver(Observer* obs)
{
	this -> obs.push_back(obs);
}

void CounterObserver::HandleLimitReached(Counter* ctr)
{
	printf("Limit has been reached. count: ");
	cout << ctr -> GetInitial() << endl;
}

void CounterUser::IncrementBy(int n)
{

	for (int i = 0; i < n; i++)
	{
		inc();
	}
}

OverflowCounter::OverflowCounter(int upper)
{
	final = upper;
}

void OverflowCounter::Notify()
{
	for (vector<Observer*> :: iterator it = obs.begin();
		it != obs.end(); it++)
	{
		(*it) -> HandleLimitReached(this);
	}
}

void OverflowCounter::inc()
{
	if (initial < final)
	{
		initial++;
	}
	else
	{
		initial = 0;
		Notify();
	}
}

void OverflowCounter::dec()
{
	if (initial > final)
	{
		initial--;
	}
	else
	{
		initial = final;
	}
}

OverflowCounter:: operator int()
{
	return initial;
}

OverflowCounter :: ~OverflowCounter()
{
	obs.clear();
}

int OverflowCounter::GetInitial()
{
	return initial;
}

counter_limit :: counter_limit(int upper)
{
	final = upper;
}

void counter_limit :: SetObserver(Observer* obs)
{
	this -> obs.push_back(obs);
}

void counter_limit :: Notify()
{
	for (vector<Observer*> :: iterator it = obs.begin();
		it != obs.end();
		it++)
	{
		(*it)->HandleLimitReached(this);
	}
}

void counter_limit :: inc()
{

	if (final > initial)
	{
		initial++;
	}
	else
	{
		Notify();
	}
}

void counter_limit :: dec()
{
	if (initial > 0)
	{
		initial--;
	}
}

counter_limit :: operator int()
{
	return initial;
}

counter_limit :: ~counter_limit()
{
	obs.clear();
}

int counter_limit :: GetInitial()
{
	return initial;
}