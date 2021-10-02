//Exercise 3B

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <string>
#pragma warning (disable:4996)

using namespace std;

void backwards(vector <string> user_input)
{

    for (auto && a:user_input)
    {
        reverse(a.begin(), a.end());
    }
    for (int b = 0; b < user_input.size(); b++)
    {
        sort(user_input.begin(), user_input.end(), greater <>());
        cout << user_input[b] << " " << endl;
    }
}

int main()
{

    vector <string> string_input;
    string user_input;

    printf("This program takes the strings you write, reverses them and then sorts then in descending order.\n");
    printf("The program begins sorting after typing stop.\n");
    printf("\nplease enter a string: ");

    do
    {
        cin >> user_input;
        if (user_input == "stop")
        {
            break;
        }
        else
        {
            printf("Please type another string: ");
            string_input.push_back(user_input);
        }
    } 
    
    while (user_input != "stop");

    printf("\n\nStrings inputted:\n\n");

    for (int i = 0; i < string_input.size(); i++)
    {
        cout << string_input[i] << endl;
    }

    printf("\n\nStrings inputted but reversed and descending:\n\n");
    backwards(string_input);
}
