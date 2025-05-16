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
    // @InpVec(N, A) [ZI87oI86]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [ZI87oI86]
    map<ll, ll> mp;
    REP(i, 0, N) mp[A[i]]++;
    ll prev = -1;
    for (auto [a, n] : mp) {
      if (n >= 4) {
        cout << "Yes\n";
        return;
      }
      if (prev == a - 1) {
        if (n >= 2) {
          cout << "Yes\n";
          return;
        }else {
          prev = a;
        }
      }else {
        if (n >= 2) {
          prev = a;
        }else {
          prev = -1;
        }
      }
    }
    cout << "No\n";
    return;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

