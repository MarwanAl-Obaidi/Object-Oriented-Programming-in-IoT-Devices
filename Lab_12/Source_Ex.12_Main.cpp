#include <iostream>
#include <ctime>
#include <random>
#include "Source_Ex.12.h"
#pragma warning (disable:4996)


void test_generator(UniqueRng UniqueRng, int count);

int main(void)
{
    std::srand(time(NULL));
    UniqueRng randGen(5, 13);

    test_generator(randGen, 6);
    test_generator(randGen, 9);
    test_generator(randGen, 13);

    UniqueRng randGen2(1, 35);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 70);

    return 0;
}

void test_generator(UniqueRng UniqueRng, int count)
{
    int i = 0;
    try
    {
        printf("Generating numbers:\n");

        for (i; count > i; i++)
        {
            std :: cout << UniqueRng() << std :: endl;
        }
    }
    catch (std :: runtime_error& a)
    {
        std :: cout << a.what() << std :: endl;
        std ::cout << "Tried to generate " << count << " random numbers. Got only " << i << std :: endl;
    }

    printf("End of generator");
    std :: cout << std :: endl;
}