

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

/*
Author : Richard Gotthard 
liuid: ricgo595

*/

int solve(double x)
{
    int highest_p;
    double root;
    int p = 32;
    const double epsilon = pow(10, -12);

    int i = 1;

    //checks for negative and looks for nearest positive root

    if (x < 0)
    {
        x = -x;
        i= 2;
        p = 31;
    }

    if(x==1){

        return 1;
    }

    for (; p >= 1; p-=i)
    {
    //looks from highest p and goes down, changes depending on negative numbers

        root = (pow(x, 1.0 / p));

    //rounding errors to compare root, fixed for -125
        if (root - floor(root + epsilon) < epsilon )
        {
            break;
        }
    //rounding errors to compare root, fixed for -64
        else if(ceil(root + epsilon) - root  < epsilon )
        {
            break;
        }
    
    }
    return p;
}

int main()
{

    int x;

    fstream file("perfectpowers.in");

    while (file)
    {
        file >> x;

        //looks until last case which is zero

        if (x == 0)
        {
            return 0;
        }

        int p = solve((x));
        cout << p << endl;
    }

    return 0;
}

