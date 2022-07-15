#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

int main() {
    int n;
    cin >> n;
    V<ll> a(n), b(n);
    ll as = 0, bs = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        as += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        bs += b[i];
    }

    ll c = bs - as;
    if (c < 0) {
        cout << "No" << endl;
        return 0;
    }

    ll oneuse = 0, twouse = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            twouse += (b[i] - a[i] + 1) / 2;
        } else {
            oneuse += a[i] - b[i];
        }
    }
    if (twouse <= c && oneuse <= c) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
