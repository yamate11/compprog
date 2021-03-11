#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:nnDivCeil)
// --> f:nnDivCeil
// ---- inserted function nnDivCeil from util.cc
// Natural Number Division and Ceiling
ll nnDivCeil(ll x, ll y) {
  return (x + (y - 1)) / y;
}
// ---- end nnDivCeil
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> C, S, F;
  for (ll i = 0; i < N-1; i++) {
    ll c, s, f; cin >> c >> s >> f;
    C.push_back(c);
    S.push_back(s);
    F.push_back(f);
  }
  for (ll i = 0; i < N; i++) {
    ll t = 0;
    for (ll j = i; j < N-1; j++) {
      ll t1 = nnDivCeil(t, F.at(j)) * F.at(j);
      if (t1 < S.at(j)) t1 = S.at(j);
      t = t1 + C.at(j);
    }
    cout << t << "\n";
  }

  return 0;
}

