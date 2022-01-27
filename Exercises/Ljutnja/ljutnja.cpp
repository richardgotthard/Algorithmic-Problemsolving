

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>  
#include <algorithm>

using namespace std;

int main(){

    unsigned long long n;
    unsigned long long m;

    ifstream file("ljutnja.1.in");

    cin >> m;
    cin >> n;

    vector<unsigned long long> c(n,0);

    unsigned long long sum = 0;

    for(int i = 0; i < n; i++){

        cin >>  c[i];
        sum += c[i];
            
    }

    if(m >= sum || c.size() == 0){
        cout << 0 << endl;
       
    }else{
        //N*log2(N)
        sort(c.begin(), c.end());

        unsigned long long ang = 0;
        unsigned long long totang = 0;

        unsigned long long candysLeft = sum - m;

        // c.size() * O(1)
       for(int i = 0; i < c.size(); i++){
            
            //ang is determined comparing the number of candies left to distribute of children left in the loop and children need
            //amount of candysLeft add to ang
            ang = min(c[i], (unsigned long long)floor(candysLeft/(double)(n-i)));
            totang += ang*ang;
            candysLeft -= ang;

             }

             cout << totang << endl;


        }

        return 0;


    }