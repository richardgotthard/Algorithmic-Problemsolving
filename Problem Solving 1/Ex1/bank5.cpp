#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // std::sort

using namespace std;

struct sort_pred
{
    bool operator()(const std::pair<int, int> &left, const std::pair<int, int> &right)
    {
        return left.first >= right.first;
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

    file >> numP >> timeB;

    for (int index = 0; index < numP; index++)
    {

        file >> c;
        file >> t;
        c_t.push_back(make_pair(c, t));
        
    }

     sort(c_t.begin(), c_t.end(), sort_pred());

    int sum = 0;

    // // for(auto x: c_t){

    // //     cout << x.first << " " << x.second << endl;

    // }

    vector<int> pickLarg(timeB);

    for(int i = 0; i < c_t.size(); i++){

        int min = timeB;

        if()

        sum += 

        int que = c_t[i].second;

        

        while(que >= 0){
            if(pickLarg[que] ==0){
                
            pickLarg[que] = c_t[i].first;
            break;

            }
            que--;

        }
        

    }

   for(int i = 0; i < pickLarg.size(); i++){
        sum += pickLarg[i];
        cout << pickLarg[i] << endl;
    }

    cout << sum;

    return 0;
}
