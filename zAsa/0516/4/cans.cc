#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto f = [&](ll x) -> ll {
    ll ret = 0;
    while (x > 0) {
      ret += x % 10;
      x /= 10;
    }
    return ret;
  };

  ll N; cin >> N;
  ll t = max(1LL, N - 200);
  vector<ll> ans;
  REP(x, t, N) {
    if (x + f(x) == N) ans.push_back(x);
  }
  cout << ssize(ans) << "\n";
  if (ssize(ans) > 0) {
    REPOUT(i, 0, ssize(ans), ans[i], "\n");
  }

  return 0;
}

