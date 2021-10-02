// Exercise 2A

#include <iostream>
#include <fstream>
#include <string>
#pragma warning (disable:4996)

using namespace std;

string find_field(const string &xml, string tag_name);

int main() {
	string page, line, location, temperature, input, output;
	ifstream file("weather.xml");

	while (getline(file, line)) {
		page.append(line);
		line.erase();
	}

	location = find_field(page, "location");
	temperature = find_field(page, "temp_c");

	cout << "Location: " << location << endl;
	cout << "Temperature: " << temperature << endl;

	do
	{
		printf("\nType what data you would like to look at");
		printf("\nor type EXIT (in capitals) to close the program!");
		printf("\n\nInput: ");
		cin >> input;

		if (input != "EXIT")
		{
			output = find_field(page, input);
			cout << "\nOutput: " << output << endl;
		}
		else
		{
			printf("\nExiting\n");
		}
	}

	while (input != "EXIT");
	
}


string find_field(const string &xml, string tag_name)
{
	auto a = xml.find("<" + tag_name + ">") + tag_name.length() + 2;
	auto b = xml.find("</" + tag_name + ">");
	if ((a - 2 - tag_name.length()) != b)
	{
		return xml.substr(a, b - a);
	}
	else
	{
		return "\n\nString not found, please type in something else";
	}

}
