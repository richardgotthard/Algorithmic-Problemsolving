// // Author: Jacob Molin (jacmo699)
// #include <algorithm>
// #include <bitset>
// #include <complex>
// #include <deque>
// #include <exception>
// #include <fstream>
// #include <functional>
// #include <iomanip>
// #include <ios>
// #include <iosfwd>
// #include <iostream>
// #include <istream>
// #include <iterator>
// #include <limits>
// #include <list>
// #include <locale>
// #include <map>
// #include <memory>
// #include <new>
// #include <numeric>
// #include <ostream>
// #include <queue>
// #include <set>
// #include <sstream>
// #include <stack>
// #include <stdexcept>
// #include <streambuf>
// #include <string>
// #include <typeinfo>
// #include <utility>
// #include <valarray>
// #include <vector>

// #if __cplusplus >= 201103L
// #include <array>
// #include <atomic>
// #include <chrono>
// #include <condition_variable>
// #include <forward_list>
// #include <future>
// #include <initializer_list>
// #include <mutex>
// #include <random>
// #include <ratio>
// #include <regex>
// #include <scoped_allocator>
// #include <system_error>
// #include <thread>
// #include <tuple>
// #include <typeindex>
// #include <type_traits>
// #include <unordered_map>
// #include <unordered_set>
// #endif

// using namespace std;

// typedef long long ll;
// typedef unsigned long long ull;
// typedef vector<ll> vll;


// // Count k-digit numbers with digit sum = s
// // (the number has exactly k digits, ex: 132 has k=3 digits)
// ll count_digit_sums(int k, int sum, vector<vector<ll>>& lookup) {
//     if (sum < 0) return 0;
//     if (k == 0) return (ll)(sum == 0 ? 1 : 0);
//     if (lookup[k][sum] != -1) return lookup[k][sum];

//     ll result = 0;

//     for (auto i=0; i <= 9; ++i) {
//         if (sum - i < 0) {
//             break;
//         }
//         result += count_digit_sums(k - 1, sum - i, lookup);
//     }

//     lookup[k][sum] = result;
//     return result;
// }

// ll count_sums(ll x, int sum, vector<vector<ll>>& lookup) {
//     int nr_digs = (int)floor(log10(x)) + 1;

//     ll num = x;
//     vector<int> digits;
//     while (num) {
//         digits.push_back((int)num % 10);
//         num /= 10;
//     }
//     reverse(begin(digits), end(digits));

//     int count = 0;
//     int idx_dig = nr_digs;
//     for (auto i= 0; i < nr_digs; ++i) {
//         --idx_dig;
//         if (digits[i] == 0) continue;

//         int dig = digits[i];
//         for (auto j=0; j < dig; ++j) {
//             if (sum - j >= 0) {
//                 count += count_digit_sums(idx_dig, sum - j, lookup);
//             }
//         }
//         sum -= dig;
//     }
//     return count;
// }

// ll sum_of_digits(ll x) {
//     if (x == 0) return 0;
//     else return x % 10 + sum_of_digits(x / 10);
// }


// ll smallest_number(ll n, int sum) {
//     vector<ll> result(0);
//     sum -= 1;
//     for (auto i{ n - 1 }; i > 0; --i) {
//         if (sum > 9) {
//             result[i] = 9;
//             sum -= 9;
//         }
//         else {
//             result[i] = sum;
//             sum = 0;
//         }
//         cout << "result[" << i << "] = " << result[i] << "\n";
//     }
//     result[0] = sum + 1;

//     ll number{};
//     for (auto i{ 0 }; i < n; ++i) {
//         number += result[i];
//     }
//     return number;
// }




// int main()
// {
//     // Improves IO speed without having to use cstdio routines,
//     // is are particularly cumbersome for string data. Note the
//     // call order, it's important!
//     ios_base::sync_with_stdio(false);
//     fstream file("cudak.1.in");
//     file.tie(NULL);

//     ll a{}, b{}, s{}, first{ 0 };
//     file >> a;
//     file >> b;
//     file >> s;

//     vector<vector<ll>> lookup(15 + 1, vector<ll>(s + 1, -1));
//     // cout << count_sums(b + 1, s, lookup) - count_sums(a, s, lookup) << "\n";
//     ll upper = count_sums(b + 1, s, lookup);
//     ll lower = count_sums(a, s, lookup);
//     ll tot = upper - lower;

//     for (size_t i = 0; i < lookup[0].size(); i++)
//     {
//         cout << i << "  ";
//         /* code */
//     }
//     cout << "\n";
//     for (size_t i = 0; i < lookup.size(); i++)
//     {
//         for (size_t j = 0; j < lookup[0].size(); j++)
//         {
//             if (lookup[i][j] >= 0) cout << " ";
//             cout << lookup[i][j] << " ";
//         }
//         cout << "\n";
//     }


//     cout << tot << "\n";
//     cout << smallest_number(3, s) << "\n";
//     ll k{ a };
//     bool found = false;
//     while (!found) {
//         ++k;
//         if (sum_of_digits(k) == s) {
//             found = true;
//             first = k;
//         }
//     }
//     cout << first << "\n";

//     return 0;
// }