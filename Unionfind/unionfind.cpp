// Author: Jacob Molin (jacmo699)

// Find if two nodes belong to the same set using Union-Find

// INPUT
// * line 1: n q
// n: [1..1M], number of elements in the base set
// q: [1..1M], number of operations
// * following q lines (one/operation):
// "= a b": the sets containing a and b are joined
// OR
// "? a b": are a and b in the same set?
// OUTPUT
// answer to queries "? a b":
// "yes" if true, "no" if false

#include <bits/stdc++.h> // All std:: in STL

using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        rank.assign(n, 0);
        parent.assign(n, 0);

        for (auto i{ 0 }; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Finds representative of the set where a is included
    // O(1) amortized
    int find_set(int a) {
        return (parent[a] == a) ? a : (parent[a] = find_set(parent[a]));
    }

    // Test whether a and b are in the same set
    // O(1) amortized
    bool same(int a, int b) {
        return find_set(a) == find_set(b);
    }

    // Merge the sets containing elements a and b
    // O(1) amortized
    void make_union(int a, int b) {
        if (!same(a, b)) {      // not in same set
            int x = find_set(a);
            int y = find_set(b);

            if (rank[x] > rank[y]) parent[y] = x;   // keep tree shallow
            else {
                parent[x] = y;
                if (rank[x] == rank[y]) ++rank[y];
            }
        }
    }

private:
    vector<int> parent{}, rank{};

};


int main()
{
    // Improves IO speed without having to use cstdio routines,
    // is are particularly cumbersome for string data. Note the
    // call order, it's important!
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n{}, q{};
    cin >> n >> q;
    UnionFind uf(n);

    char op{};
    int a{}, b{};
    while (q--) {
        cin >> op;

        if (op == '?') {
            cin >> a >> b;
            if (uf.same(a, b)) cout << "yes\n";
            else cout << "no\n";
        }

        if (op == '=') {
            cin >> a >> b;
            uf.make_union(a, b);
        }
    }
    return 0;
}