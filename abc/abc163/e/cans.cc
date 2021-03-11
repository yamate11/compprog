#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:updMaxMin)
// --> f:updMaxMin
// ---- inserted function updMaxMin from util.cc
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
// ---- end updMaxMin
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using Pair = pair<ll, ll>;
  ll N; cin >> N;
  vector<Pair> A;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    A.emplace_back(a, i);
  }
  sort(A.begin(), A.end(), greater<Pair>());
  vector tbl(N+1, vector<ll>(N+1, LLONG_MIN));
  tbl.at(0).at(0) = 0;
  for (ll i = 0; i < N; i++) {
    const auto& prev = tbl.at(i);
    auto& cur = tbl.at(i+1);
    auto [a, k] = A.at(i);
    for (ll j = 0; j <= i; j++) {
      if (j+1 <= N) updMax(cur.at(j+1), prev.at(j) + a * abs(k - (N - j - 1)));
      updMax(cur.at(j), prev.at(j) + a * abs(k - (i-j)));
    }
  }
  ll ans = 0;
  for (ll j = 0; j <= N; j++) updMax(ans, tbl.at(N).at(j));
  cout << ans << endl;

  return 0;
}

