#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

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
  vector<ll> A(N + 1), S(N + 1);
  for (ll i = 1; i <= N; i++) {
    cin >> A[i];
    S[i] = S[i - 1] + A[i];
  }
  using sta = tuple<ll, ll, ll>;
  vector<sta> P;
  for (ll i = 0; i < M; i++) {
    ll l, r, c; cin >> l >> r >> c;
    P.emplace_back(l, r, c);
  }
  sort(P.begin(), P.end());
  ll i = 1;
  vector<ll> tbl(N + 1);
  for (auto [l, r, c] : P) {
    for (; i < l; i++) updMax(tbl[i + 1], tbl[i]);
    updMax(tbl[r], tbl[l] + S[r] - S[l - 1] - c);
  }
  for (; i < N; i++) updMax(tbl[i + 1], tbl[i]);
  cout << tbl[N] << endl;

  return 0;
}

