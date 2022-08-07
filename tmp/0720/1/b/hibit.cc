#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

int main(void)
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    map<int, int> mp;
    mp[a]++;
    mp[b]++;
    mp[c]++;
    mp[d]++;
    if (a == b)
    {
        mp[a]--;
    }
    if (c == d)
    {
        mp[c]--;
    }
    for (auto [key, val] : mp)
    {
        if (val > 1)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}

