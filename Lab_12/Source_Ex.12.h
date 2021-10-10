#include <set>
#pragma once


class UniqueRng
{
public:
	UniqueRng(int start = 0, int end = 0) : start(start), end(end), number_gen() {};
	int operator()();

private:
	std :: set<int> number_gen;
	int start;
	int end;
};