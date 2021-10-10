#include <set>
#include <exception>
#include <iostream>
#include <random>
#include "Source_Ex.12.h"


int UniqueRng :: operator()()
{
	std :: random_device rd;
	std :: mt19937 gen(rd()); //gen 32-bit
	std :: uniform_int_distribution<> distr(start, end);

	if (number_gen.size() >= end - start + 1)
	{
		throw std::runtime_error("Unable to produce random number");
	}

	int number = 0;
	do
	{
		number = distr(gen);
	}

	while (number_gen.count(number) > 0);
	number_gen.insert(number);
	return number;
}