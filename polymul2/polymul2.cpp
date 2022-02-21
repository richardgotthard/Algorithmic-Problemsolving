

#include <bits/stdc++.h> // All std:: in STL

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;

void polymul(const vector<ll>& coeff1,
    const vector<ll>& coeff2, vector<ll>& final_coeff);
ll karatsubas(ll x, ll y);

int main()
{
    // Improves IO speed without having to use cstdio routines,
    // is are particularly cumbersome for string data. Note the
    // call order, it's important!
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t{};
    cin >> t;

    int degree{};
    cin >> degree;

    ll in{};
    vector<ll> pol1_coeff{};
    for (auto i{ 0 }; i <= degree; ++i) {
        cin >> in;
        pol1_coeff.push_back(in);
    }

    // cout << "pol1 coeff:\n";
    // for_each(begin(pol1_coeff), end(pol1_coeff),
    //     [](ll coeff) {cout << coeff << " ";});


    cin >> degree;
    vector<ll> pol2_coeff{};
    for (auto i{ 0 }; i <= degree; ++i) {
        cin >> in;
        pol2_coeff.push_back(in);
    }

    // cout << "\npol2 coeff:\n";
    // for_each(begin(pol2_coeff), end(pol2_coeff),
    //     [](ll coeff) {cout << coeff << " ";});


    vector<ll> final_coeff{  };
    if (pol1_coeff.size() >= pol2_coeff.size()) {
        final_coeff.assign(pol1_coeff.size(), 0);
        polymul(pol1_coeff, pol2_coeff, final_coeff);
    }
    else {
        final_coeff.assign(pol2_coeff.size(), 0);
        polymul(pol2_coeff, pol1_coeff, final_coeff);
    }

    // cout << end(final_coeff)->first << "\n";
    cout << final_coeff.size() << "\n";

    for (auto i{ 0 }; i <= final_coeff.size(); ++i) {
        cout << final_coeff[i];
        if (i != final_coeff.size()) cout << " ";
        else cout << "\n";
    }



    // for_each(begin(final_coeff), end(final_coeff),
    //     [](ll coeff) {cout << coeff << " ";});

    // cout << "\n";
    // cout << karatsubas(123, 4321) << "\n";
    return 0;
}

void polymul(const vector<ll>& coeff1, const vector<ll>& coeff2,
    vector<ll>& final_coeff) {
    int degree_large = coeff1.size();
    int degree_small = coeff2.size();


    for (auto i{ 0 }; i <= degree_large; ++i) {
        for (auto j{ 0 }; j <= degree_small; ++j) {
            //     if (i == 0 || j == 0) k = max(i, j);
                // else k = i + j;
            final_coeff[i + j] += karatsubas(coeff1[i], coeff2[j]);
        }
    }
}




ll karatsubas(ll x, ll y) {
    if (x <= 10 || y <= 10) return x * y;

    int n_x = 0;    // digits in x
    ll temp = x;
    while (temp) {
        temp /= 10;
        ++n_x;
    }

    int n_y = 0;    // digits in y
    temp = y;
    while (temp) {
        temp /= 10;
        ++n_y;
    }

    int m = floor(min(n_x, n_y) / 2);
    ll split = (ll)pow(10, m);


    ll a = x / split;
    ll b = x % (a * split);

    ll c = y / split;
    ll d = y % (c * split);

    // cout << "min(n_x, n_y) = " << min(n_x, n_y) << "\n";
    // cout << "x = " << x << "\n";
    // cout << "m = " << m << "\n";
    // cout << "a = " << a << "\n";
    // cout << "b = " << b << "\n";
    // cout << "c = " << c << "\n";
    // cout << "d = " << d << "\n";

    ll ac = karatsubas(a, c);
    ll bd = karatsubas(b, d);
    ll ad_bc = karatsubas((a + b), (c + d)) - ac - bd;

    // cout << "powl(10, m * 2) = " << powl(10, m * 2) << "\n";

    return ac * powl(10, m * 2) + ad_bc * powl(10, m) + bd;
}
