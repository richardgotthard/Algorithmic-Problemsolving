
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

/*
Author: Richard Gotthard
Date: 5 february 2022
*/

using namespace std;

//#define gt_pr_gt_nxt(j) (j & (-j))

//using ll = long long;

struct FenwickTree
{
private:
    vector<int> data;
    int n;

public:
    FenwickTree(int n) : n(n)
    {
        data.assign(n + 1, 0);
    }

    long numSum(int i) const
    {
        int sum = 0;
        int end = 1 + i;

        for(;end> 0; end -= (end & (-end)))
        {
            sum += data[end];
           
        }
        return sum;
    }

    void add(int ind, int val)
    {
        ++ind;
        for (; ind <= n; ind += (ind & (-ind)))
        {
            data[ind] += val;
            
        }
    }
};

int main()
{

    std::fstream file("fenwick2.in");

    int length;
    int n_op;

    char var;

    file >> length;

    file >> n_op;

    FenwickTree f(length);

    // Time complexity Olog(n_op)
    for (int i = 0; i < n_op; ++i)
    {

        file >> var;

        if (var == '+')
        {

            int ind;
            int delta;

            file >> ind >> delta;

            f.add(ind, delta);
        }
        else 
        {

            int s;

            file >> s;

            if (s == 0)
            {
                cout << "0" << endl;
            }
            else
            {
                cout << f.numSum(s) << endl;
            }
        }
    }
    return 0;
}
