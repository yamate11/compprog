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

  map<ll, ll> mp;
  ll N; cin >> N;
  ll x0; cin >> x0;
  mp[0] = x0;
  mp[x0] = x0;
  ll cur = 2 * x0;
  cout << cur << "\n";
  REP(i, 1, N) {
    ll x; cin >> x;
    auto [it, b] = mp.emplace(x, 0);
    if (next(it) == mp.end()) {
      auto itL = prev(it);
      auto& [xL, dL] = *itL;
      ll d = x - xL;
      it->second = d;
      cur += d;
      if (x - xL < dL) {
        cur -= dL - (x - xL);
        dL = x - xL;
      }
    }else {
      auto itH = next(it);
      auto itL = prev(it);
      auto& [xH, dH] = *itH;
      auto& [xL, dL] = *itL;
      ll d = min(xH - x, x - xL);
      it->second = d;
      cur += d;
      if (xH - x < dH) {
        cur -= dH - (xH - x);
        dH = xH - x;
      }
      if (x - xL < dL) {
        cur -= dL - (x - xL);
        dL = x - xL;
      }
    }
    cout << cur << "\n";
  }

  return 0;
}

