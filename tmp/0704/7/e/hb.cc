#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <stack>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
  for (T &in : v)
    is >> in;
  return is;
}

auto chmin = [](auto &a, auto b)
 { a = min(a, b); };

auto chmax = [](auto &a, auto b)
 { a = max(a, b); };

int main(void)
{
  int n, W;
  cin >> n >> W;
  vector<ll> w(n), v(n);
  rep(i, n)
    {
      cin >> w[i] >> v[i];
    }
  ll inf = 1LL << 62;
  vector<map<ll, ll>> dp(n + 1);
  dp[0][0] = 0;
  rep(i, n)
    {
      for (auto &[key, val] : dp[i])
        {
          if (dp[i + 1].count(key) == 0)
            {
              dp[i + 1][key] = inf;
            }
          if (dp[i + 1].count(key + v[i]) == 0)
            {
              dp[i + 1][key + v[i]] = inf;
            }
          chmin(dp[i + 1][key], dp[i][key]);
          chmin(dp[i + 1][key + v[i]], dp[i][key] + w[i]);
        }
    }
  ll ans = 0;
  for (auto &[key, val] : dp[n])
    {
      if (val <= W)
        {
          chmax(ans, key);
        }
    }
  cout << ans << endl;
}
