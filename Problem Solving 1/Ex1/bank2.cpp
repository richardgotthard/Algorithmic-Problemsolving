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

    vector<int> c_amount; // amount of money
    vector<int> t_amount; // time before leave
    int index = 0;

    cin >> numP >> timeB;

    for (int index = 0; index < numP; index++)
    {
        int c;
        int t;

        cin >> c;
        cin >> t;
        c_amount.push_back(c);
        t_amount.push_back(t);
        
    }

     sort(c_t.begin(), c_t.end(), sort_pred());

    vector<vector<int> > matrix(numP + 1, vector<int>(timeB + 1, 0));

    int sum = 0;

    for (int i = 1; i <= numP; i++)
    {
        for (int w = 1; w <= timeB; w++)
        {
            if(t_amount[i-1] <= w){
                matrix[i][w] = max(c_amount[i-1] + matrix[i-1][w-t_amount[i-1]], matrix[i-1][w]);
            }
            else{
                matrix[i][w] = matrix[i-1][w];
            }
        }
    }

    cout << sum;

    return 0;
}
