#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#include <boost/range/irange.hpp>

// @@ !! LIM()

bool subseteq(ll x, ll y) { return (x & y) == x; }

int main(void)
{
    int n;
    cin >> n;
    vector<int> honest(n), unkind(n);
    rep(i, n)
    {
        int a;
        cin >> a;
        rep(j, a)
        {
            int x, y;
            cin >> x >> y;
            x--;
            honest[i] |= (y == 1) << x;
            unkind[i] |= (y == 0) << x;
        }
    }
    int ans = 0;
    rep(i, 1 << n)
    {
      auto solve = [&](int i) -> int {
        auto subseteq = [&](int x, int y) -> bool { return (x & y) == x; };
        auto consis = [&](int j) -> bool {
          
        }

        if (i
        
      };



        auto solve = [&](int i)
        {
            rep(j, n)
            {
                bool bit = (i >> j) & 1;
                if (!bit)
                {
                    continue;
                }
                if ((i & honest[j]) != honest[j])
                {
                    return 0;
                }
                if ((i & unkind[j]) != 0)
                {
                    return 0;
                }
            }
            return __builtin_popcount(i);
        };
        auto chmax = [](auto &a, auto b) { a = max(a, b); };

        chmax(ans, solve(i));
    }
    cout << ans << endl;
    return 0;
}

