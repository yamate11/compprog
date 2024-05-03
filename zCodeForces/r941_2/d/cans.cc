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

  auto solve = [&]() -> void {
    ll N, K; cin >> N >> K;

    vector<ll> ans;
    ll x = 1;
    while (2 * x <= K) {
      ans.push_back(x);
      x *= 2;
    }
    ll sum = x - 1;
    ll p = K - 1 - sum;
    if (p >= 1) ans.push_back(p);
    ans.push_back(K + 1);
    ans.push_back(3 * K);
    ll y = 2 * K;
    while (y <= N) {
      ans.push_back(y);
      y *= 2;
    }
    cout << ssize(ans) << "\n";
    REPOUT(i, 0, ssize(ans), ans[i], " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

