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
    ll N; cin >> N;
    if (N == 2 or N == 3 or N == 5) {
      cout << "No\n";
      return;
    }
    cout << "Yes\n";
    if (N == 1) {
      cout << "1\n";
      return;
    }
    if (N == 4) {
      cout << "2 2 2 2\n";
      return;
    }
    if (N == 17) {
      cout << "2 2 3 3 4 4 5 5 6 7 10 14 20 20 21 30 30\n";
      return;
    }
    ll x = 1;
    for (; 16 * x * x < N; x++);
    ll n = 2 * x;
    ll m = N - n * n;
    ll a3 = m / 3;
    ll r = m % 3;
    ll a2 = 0;
    if (r == 2) a2 = 1;
    else if (r == 1) { a2 = 2; a3--; }
    assert(a3 >= 0);
    ll a0 = N - (3 * a2 + 4 * a3);
    vector<ll> ans;
    REP(i, 0, a0) ans.push_back(n);
    REP(i, 0, a2) {
      ans.push_back(3 * x);
      ans.push_back(3 * x);
      ans.push_back(6 * x);
    }
    REP(i, 0, a3) {
      ans.push_back(4 * x);
      ans.push_back(4 * x);
      ans.push_back(4 * x);
      ans.push_back(4 * x);
    }
    REPOUT(i, 0, ssize(ans), ans[i], " ");
  };

  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

