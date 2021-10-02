//Exercise 3A

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#pragma warning (disable:4996)

using namespace std;

vector <double> number_input;

int main()
{
    printf("This program takes the numbers the user inputs and puts them in order\n");
    printf("from highest to lowest. It also rounds them to three decimal precision.\n");
    printf("To stop the program type in a negative number!\n\n");
    printf("Please type a number: ");

    double user_input = 0;

    do
    {
        cin >> user_input;

        if (user_input < 0)
        {
            break;
        }
        else
        {
            printf("Please type another number: ");
            number_input.push_back(user_input);
        }
    }

    while (user_input >= 0);

    printf("\nNumbers sorted:\n\n");

    for (int i = 0; i < number_input.size(); ++i)
    {
        sort(number_input.begin(), number_input.end());
        cout << fixed;
        cout << setprecision(3) << number_input[i] << endl;
    }

    return 0;
}