#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#pragma warning (disable:4996)

using namespace std;

float mean(int* array, int n)
{
    float  sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += array[i];
    }
    sum = sum / n;

    return sum;
}

int main() {
    int size;
    cout << "Enter desired size of the array: ";
    cin >> size;
    int* array = new int[size];
    srand(time(NULL));

    if (size == NULL)
        printf("\nPlease use numbers!");

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    for (int i = 0; i < size; i++) {
        printf("\n%d", array[i]);
    }

    cout << "\n\nMean of numbers: " << mean(array, size);
    printf("\n");

    delete[] array;
}