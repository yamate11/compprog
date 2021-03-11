#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(binsearch)
// --> binsearch
// ---- inserted library file binsearch.cc

template<typename T>
T binsearch(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / (T)2;
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
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll w, l; cin >> w >> l;
  vector<ll> A(w);
  for (ll i = 1; i < w; i++) cin >> A[i];
  ll n = 0;
  for (ll i = 1; i <= l; i++) n += A[i];
  auto check = [&](ll m) -> bool {
    vector<ll> R(A);
    vector<ll> B(w);
    vector<ll> back(w);
    for (ll i = 1; i < w; i++) back[i] = i - 1;
    B[0] = m;
    for (ll i = 0; i < w - l; i++) {
      while (B[i] > 0) {
        ll j = i + l;
        if (R[j] == 0) {
          ll k = back[j];
          while (k > i && R[k] == 0) k = back[k];
          if (k <= i) return false;
          back[j] = k;
          j = k;
        }
        assert(R[j] > 0);
        ll z = min(R[j], B[i]);
        R[j] -= z;
        B[i] -= z;
        B[j] += z;
      }
    }
    return true;
  };
  ll ans = binsearch<ll>(check, 0, n + 1);
  cout << ans << endl;

  return 0;
}

