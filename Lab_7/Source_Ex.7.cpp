#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>


using namespace std;

class gambling_rand
{
public:
    gambling_rand(int range = 0, int num = 0);
    gambling_rand() :numbs()
    {
        srand(time(NULL));
    }
    int operator () ();

private:
    vector < int >numbs;
    int range;
    int num;
};

gambling_rand::gambling_rand(int range_f, int num_f)
{
    range = range_f;
    num = num_f;
}

int gambling_rand::operator () ()
{
    int num_f;
    do
    {
        num_f = rand() % range + 1;
        num--;
    }

    while (find(numbs.begin(), numbs.end(), num_f) != numbs.end());
    numbs.push_back(num_f);

    return num_f;
}

int num_gen_o(int numbs)
{
    return rand() % numbs + 1;
}

int main(void)
{

    char c = 'n';
    do
    {
        srand(time(NULL));
        ostream_iterator < int >comp(cout, " ");
        vector < int >levia;
        vector < int >garuda;

        vector < int >lotto_gamb(7);
        gambling_rand num_gen_o(40, 7);
        generate(lotto_gamb.begin(), lotto_gamb.end(), num_gen_o);
        printf("Lotto: ");
        copy(lotto_gamb.begin(), lotto_gamb.end(), comp);

        vector < int >vik_gamb(7);
        gambling_rand num_gen_t(48, 6);
        generate(vik_gamb.begin(), vik_gamb.end(), num_gen_t);
        printf("\nViking lotto: ");
        copy(vik_gamb.begin(), vik_gamb.end(), comp);

        printf("\nMatching numbers: ");
        sort(lotto_gamb.begin(), lotto_gamb.end());
        sort(vik_gamb.begin(), vik_gamb.end());
        set_intersection(lotto_gamb.begin(), lotto_gamb.end(),
            vik_gamb.begin(), vik_gamb.end(),
            back_inserter(levia));
        int total = 0;
        for_each(levia.begin(), levia.end(), [&total](int x)
            {
                total = total + 1;
                cout << "#" << total << ":" << x << endl; });

        vector < int >pot_gamb(5);
        gambling_rand num_gen_th(50, 5);
        generate(pot_gamb.begin(), pot_gamb.end(), num_gen_th);
        printf("Eurojackport: ");
        copy(pot_gamb.begin(), pot_gamb.end(), comp);

        printf("\nMatching numbers in the three sets: ");
        total = 0;
        sort(levia.begin(), levia.end());
        sort(pot_gamb.begin(), pot_gamb.end());
        set_intersection(levia.begin(), levia.end(),
            pot_gamb.begin(), pot_gamb.end(),
            back_inserter(garuda));
        for_each(garuda.begin(), garuda.end(), [&total](int x)
            {
                total = total + 1;
                cout << "#" << total << ":" << x << endl; });

        do
        {
            printf("\nTo try again type Y.");
            printf("\nIf you quit type N.\n");
            cin >> c;
            printf("\n");
            if (toupper(c) != 'Y' && toupper(c) != 'N')
            {
                printf("\nInvalid answer. Try gain!");
            }
        }
        
        while (toupper(c) != 'Y' && toupper(c) != 'N');

    }
    
    while (toupper(c) == 'Y');
}