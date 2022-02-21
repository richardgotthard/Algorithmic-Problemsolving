
// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <complex>
// #include <utility>
// #include <iomanip>

    


#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <map>
#include <algorithm>


using namespace std;

template <typename T>
bool getInterval(T& input, pair<double, double>& p){
    string start;
    string end;
    if(!(input >> start)){
        return false;
    }
    input >> end;
    p.first = stod(start);
    p.second = stod(end);
    return true;
}

/*
3 possibilites
LEFT = 0
RIGHT = 0

//EXTEND
IF FIRST >= LEFT AND SECOND > RIGHT
    LEFT = FIRST
    RIGHT = SECOND
    ADD INDEX

//REPLACE
ELIF SECOND > RIGHT
    RIGHT = SECOND
    REPLACE INDEX

//DO NOTHING
*/

bool compareIntervals(pair<double, double> l, pair<double, double> r){
    return (l.first < r.first);
}

void intervalChecker(pair<double, double> interval,vector<pair<double, double> >& vec_pairs){
    vector<int> indexes(1, 0);
    //current looks at start interval
    double current = interval.first;
    //condition if interval not valid
    if(interval.first > interval.second){
        cout << "impossible\n";
        return;
    }
    //creates index position before sorting
    map<pair<double, double>,int > indexPositions;
    for(int i = 0; i < vec_pairs.size(); i++){
        indexPositions[vec_pairs[i]] = i;
    }
    //sorts all pairs looking at start interval, n log n time complexity
    sort(vec_pairs.begin(), vec_pairs.end(), compareIntervals);
    for(int i = 0; i < vec_pairs.size(); i++){
        //these if cases might not work fully

        //interval first checks
        if(current >= interval.second) break;
        
        //looks at first pair in vector vec_pairs, compares first with interval
        if(vec_pairs[i].first <= interval.first &&){

            if(vec_pairs[i].second > current){
                indexes[0] = i;
                current = vec_pairs[i].second;
            }
        //if current && vec second is bigger then vec first 
        }else if(vec_pairs[i].first <= current && vec_pairs[i].second > current){
            indexes.push_back(i);
            current = vec_pairs[i].second;
        }
    }
    // after having found needed intervals print their original index by using hashmap
    if(current >= interval.second){
        // print number of indexes needed
        cout << indexes.size() << endl;
        for(int i = 0; i < indexes.size(); i++){
            // print original index of intervals
            cout << indexPositions[vec_pairs[indexes[i]]] << " ";
        }
        cout << endl;
    }else{
        cout << "impossible\n";
    }
}

int main(void){

    ifstream file("intervalcover.in");

    while(true){
        pair<double, double> intervalPair;
        //change file to cin
        if(!getInterval(file, intervalPair)){
            break;
        }

        int n_testcases;
        //change file to cin
        file >> n_testcases;

        vector<pair<double, double> > pairs;
        while(n_testcases--){
            pair<double, double> intervalPair;
            //change file to cin
            getInterval(file, intervalPair);
            pairs.push_back(intervalPair);
        }

        sort(begin(intervalPair), end(intervalPair),
        [](pair<double, double> x, pair<double, double> y){

            return x.second < y.second;
        });

        intervalChecker(intervalPair, pairs);

    }
    return 0;
}
