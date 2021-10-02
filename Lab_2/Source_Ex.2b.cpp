// Exercise 2B

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#pragma warning (disable:4996)

using namespace std;

vector<string> member()
{
	string user_input;
	int found = 0;
	vector<string> collection;

	printf("This program stores the strings you enter and analyzes them.\n");
	printf("Type stop to analyze and/or to quit the program.\n\n");

	do
	{
		printf("Enter a new string: ");
		getline(cin, user_input);
		found = user_input.find("stop");
		if (found == -1)
		{
			collection.push_back(user_input);
		}

	} while (found == -1);

	return collection;
}

int main()
{
	int position = 0;
	int i = 0;
	int length = 0;
	int total_capacity = 0;
	vector<string> result;

	result = member();

	printf("\nStrings collected:\n\n");
	position = 0;
	length = result[0].size();
	i = 0;

	for (auto re : result)
	{
		cout << re << endl;
		if (result[i].size() > length)
		{
			position = i;
			length = result[position].size();
		}
		total_capacity += result[i].capacity();
		i++;
	}

	cout << "\nLongest string                  =   " << result[position] << endl;
	cout << "Length of the longest string    =   " << length << endl;
	cout << "Number of strings               =   " << result.size() << endl;
	cout << "Capacity of vector              =   " << total_capacity << endl;

	return 0;
}