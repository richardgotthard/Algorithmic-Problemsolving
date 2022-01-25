

#include <iostream>
#include <string>

using namespace std;

void(unsigned long long n, std::vector<unsigned long long> c){


    unsigned long long totalneed = 0;
    unsigned long long totalAnger = 0;

    for(auto i : c){
        totalneed += i;
    }

     unsigned long long remainingCandies = totalneed - n;
    //special case for having more candy then what children want

    int counter = c.size();

    while(remainingCandies != 0){

        remainingCandies--;
    }

    
}


int main(){

    unsigned long long n;
    unsigned long long m;

    //unsigned long long word;

    //std::vector<unsigned long long> myCandy;

    std::vector<unsigned long long> c;

    ifstream file("knapsack.in");

    file >> m;

    file >> n;

    for(int i = 0; i < n; i++){

        file >> d
        c.pushback(d);
            
    }

    c.sort();

    solve






    

    while(file >> word){
    
        myCandy.push_back((word));
    }


    string input;

    while(getline(file, input)){

        //int k = input.find(' ');
        // unsigned long long m = input.substr(0,k);
        //unsigned long long n = input.substr(k+1);

        std::vector childneeds

        getline(file, input);

        for(int i = 0; i < n; i++){
            
            getline(f,input);

            unsigned long long c = input.substr(i);
        
            
        }








    }



    /*
    M = 5 , N = 3



    List: 
    1
    3
    2

    Sort,
    Add up list and check first if its satisfies. 
    Look at the difference between M 
    and all values together



    */

    return 0;


}