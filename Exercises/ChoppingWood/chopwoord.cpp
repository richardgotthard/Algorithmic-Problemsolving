
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
#include <map>

using namespace std;

int main(void)
{

    int m;
    int d;

    ifstream file("chopwood.00.in");

    file >> m;

    priority_queue<int, vector<int>, greater<int> > pq;

    vector<int> v;

    map<int, int> counter;

    // constant linear m times
    // create map
    for (int i = 0; i < m; ++i)
    {
        file >> d;

        v.push_back(d);

        if (counter.count(d))
        {
            counter[d]++;
        }
        else
        {
            counter[d] = 1;
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        if (!counter.count(i))
        {

            pq.push(i);
        }
    }

    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    

    //
    cout << v.size() <<endl;

    vector<int> u;
   
    for (int i = 0; i < v.size(); i++)
    {
        if (pq.size() > 0)
        {
            u.push_back(pq.top());
            //temp++;
            //u[temp] = pq.top();
            pq.pop();
        }

        if (counter[v[i]] == 1)
        {
            counter.erase(v[i]);
        }
        else
        {
            counter[v[i]]--;
        }

        if (!counter.count(v[i]))
        {
            pq.push(v[i]);
        }   
    }



      if(u.size() != v.size()){
        cout << "Error\n";
    }
    else{
        for(int i = 0; i < u.size(); i++){
            cout << u[i] << "\n";
        }
    }


    // map(talen som är med, antalet tal)

    // efter 3 har lagts till kan 5 läggas till i sin min heap

    // counter kan användas för att se om något kan läggas till i sin min heap

    // map counter

    // 5 1 //decrement,
    // 1 2
    // 2 2
    // 7 1
    // 3 0
    // 4 0
    // 6 0

    // lägg till i min heap för varje rad

    // när vi går igenom mappen och vad vi ska ta bort
    // när ett värde tas bort ur mappen läggs det till i min heapen



    return 0;
}