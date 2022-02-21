

#include <iostream>
#include <fstream>
#include <math.h>

/*
Author: Richard Gotthard
LiuID: ricgo595
*/

using namespace std;

long factorial(int n)
{
    long long mod = 1;
    long long div5 = 0;
    long long div2 = 0;
    for (unsigned int i = 2; i <= n; i++)
    {
        unsigned int d = i;

        while (d % 2 == 0)
        {
            d /= 2;
            div2++;
        }

        while (d % 5 == 0)
        {
            d /= 5;
            div5++;
        }

        // mod with three last digits
        mod = mod * d % 1000;
    }

   // cout << div2 << " " << div5 << endl;

//count number of times division by 5 and subtract
// due to 2 and 5 being multiplises of 10
    int getCount = div2 - div5;

    //get result 

    for (int i = 0; i < getCount; i++)
    {
        mod = mod * 2 % 1000;
    }

    return mod;

    // if (n == 0){
    //     return 1;
    // }
    // unsigned int fac = n * factorial(n - 1);

    // //trim så att det bara är tre kvar
    // //introducera nollor, första värdet är 1, 6, 24 , 120
    // //multiplarar av 5 får in nollor, 10 är det bara att skita i,
}

void threedig(int n)
{
    if (n < 0)
    {
        cout << "";
    }
    else
    {
        long fac = factorial(n);

        string r = to_string(fac);

        if (n < 7)
        {
            printf("%ld\n", fac);
        }
        else
        {
            printf("%03ld\n", fac);
        }
    }
}

int main()
{

    int x;

    //fstream file("threedigits-2.in");

    cin >> x;

    threedig(x);

    return 0;
}