
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>  
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>


using namespace std;

int main(){

    unsigned long long m;
    unsigned long long d;

    ifstream file("chopwood.00.in");

    file >> m;

    priority_queue <int, vector<int>, greater<int> > pq;

    for(int i = 0; i < m; i++){

        file >>  d;

        pq.push(d);
      
    }

    



    while (pq.empty() == false)
	{
		cout << pq.top() << " ";
		pq.pop();
	}

    return 0;

}