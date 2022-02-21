#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // std::sort

using namespace std;

struct sort_pred
{
    bool operator()(const std::pair<int, int> &left, const std::pair<int, int> &right)
    {
        return left.second < right.second;
    }
};

int main()
{

    ifstream file("bank-01.in");

    int numP;  // number of people
    int timeB; // time close bank
    vector<pair<int, int> > c_t;

    int c; // amount of money
    int t; // time before leave
    int index = 0;

    cin >> numP >> timeB;

    for (int index = 0; index < numP; index++)
    {

        cin >> c;
        cin >> t;
        c_t.push_back(make_pair(c, t));
        
    }

     sort(c_t.begin(), c_t.end(), sort_pred());

    int sum = 0;

    // // for(auto x: c_t){

    // //     cout << x.first << " " << x.second << endl;

    // }

    for (int min = 0; min <= timeB; min++)
    {

        vector<int> pickLarg;

        for (int i = 0; i < c_t.size(); i++)
        {

            if (c_t[i].second == min)
            {

                pickLarg.push_back(c_t[i].first);
            }
        }
        if (!pickLarg.empty())
        {

            auto it = max_element(begin(pickLarg), end(pickLarg));

            sum += *(it);
        }
    }

    cout << sum;

    return 0;
}
