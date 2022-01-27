#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>  

/*
Author: Richard Gotthard, ricgo595
Description: 
*/

using namespace std;

int main()
{

    ifstream file("knapsack.in");

    double c;
    long long n;

    while (file >> c)
    {
        file >> n;
        int capacity = (int) floor(c);

        vector<int> vals;
        vector<int> wt;

        for (int i = 0; i < n; i++)
        {
            long long val;
            long long weight;
            file >> val;
            file >> weight;
            vals.push_back(val);
            wt.push_back(weight);
        }
    
    //creates a vector which takes in a matrix with size capacity+1
    //x n+1 filled with zeros
    vector<vector<int> > matrix(n + 1, vector<int>(capacity + 1, 0));


    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= capacity; w++)
        {
            if(wt[i-1] <= w){
                matrix[i][w] = max(vals[i-1] + matrix[i-1][w-wt[i-1]], matrix[i-1][w]);
            }
            else{
                matrix[i][w] = matrix[i-1][w];
            }
        }
    }
    int i = n;
    int itemsPrint = 0;
    int j = capacity;
    string printIndexes = "";
    while(i >= 0 && j > 0){
        if(matrix[i][j] != matrix[i-1][j]){
            printIndexes = " " + to_string(i-1) + printIndexes;
            itemsPrint++;
            j = j - wt[i-1];
        }     
        i--;
    }
    cout << itemsPrint << endl;
    cout << printIndexes.substr(1) << endl;
    }

    return 0;
}