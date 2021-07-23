#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(binsearch)

// ---- inserted library file binsearch.cc

template<typename T>
T binsearch_i(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / 2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

template<typename T>
T binsearch_r(auto check, T yes, T no, T err, bool rel = true) {
  while (abs(yes - no) > err &&
         (!rel || abs(yes - no) > abs(yes) * err)) {
    T mid = (yes + no) / 2.0;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

ll border_with_hint(ll t, auto pred, auto hint) {
  double y = hint(t);
  double d = floor(y);
  double e = ceil(y);
  bool rd = pred(d, t);
  bool re = pred(e, t);
  if (rd && !re) return d;
  if (!rd && re) return e;
  for (ll i = 1; true; i++) {
    bool rd_i = pred(d - i, t);
    if (rd_i && !rd) return d - i;
    if (!rd_i && rd) return d - (i - 1);
    bool re_i = pred(e + i, t);
    if (re_i && !re) return e + i;
    if (!re_i && re) return e + (i - 1);
  }
}

// ---- end binsearch.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  using sta = pair<ll, ll>;
  vector<sta> RX;
  for (ll i = 0; i < N; i++) {
    ll x, r; cin >> x >> r;
    RX.emplace_back(r, x);
  }
  sort(RX.begin(), RX.end());
  auto rec = vector(0, map<ll, ll>());

  for (auto [r, x] : RX) {
    ll xl = x - r;
    ll xr = x + r;
    auto check = [&](ll k) -> bool {
      auto& mp = rec[k];
      auto it = mp.upper_bound(xl);
      if (it == mp.end()) return false;
      return it->second < xr;
    };
    ll k = binsearch_i<ll>(check, 0, rec.size());
    if (k + 1 >= (ll)rec.size()) rec.resize(k + 2);
    auto& mp = rec[k + 1];
    auto it = mp.find(xl);
    if (it == mp.end()) mp[xl] = xr;
    else it->second = min(it->second, xr);
  }
  cout << rec.size() - 1 << endl;

  return 0;
}

