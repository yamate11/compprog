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

// @@ !! LIM(f:updMaxMin)

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  ll lo; cin >> lo;
  ll hi; cin >> hi;
  map<ll, ll> mp;
  REP(i, 0, N - 2) {
    ll a; cin >> a;
    mp[a]++;
  }
  vector<pll> vec;
  for (auto [a, n] : mp) vec.emplace_back(a, n);
  ll p = 0;
  ll q = 0;
  ll x = 0;
  ll ans = 1e18;
  while (q < ssize(vec)) {
    while (q < ssize(vec) and x < M) {
      x += vec[q].second;
      q++;
    }
    if (x < M) break;
    ll val = 0;
    if (vec[p].first < lo) val += lo - vec[p].first;
    if (vec[q - 1].first > hi) val += vec[q - 1].first - hi;
    updMin(ans, val);
    x -= vec[p].second;
    p++;
  }
  cout << ans << endl;
  return 0;
}

