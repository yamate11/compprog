#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

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

// ---- end binsearch.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, K; cin >> N >> M >> K;
  vector tbl(N, vector(M, 0));
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < M; j++) {
      char c; cin >> c;
      tbl[i][j] = c - '0';
    }
  }
  auto check = [&](ll sz) -> bool {
    for (ll r = 0; r <= N - sz; r++) {
      for (ll c = 0; c <= M - sz; c++) {
	vector<ll> vcnt(10);
	for (ll i = r; i < r + sz; i++) {
	  for (ll j = c; j < c + sz; j++) {
	    vcnt[tbl[i][j]]++;
	  }
	}
	ll vmax = 0;
	for (ll t = 0; t < 10; t++) vmax = max(vmax, vcnt[t]);
	if (vmax + K >= sz * sz) return true;
      }
    }
    return false;
  };
  ll x = binsearch<ll>(check, 1, min(N, M) + 1);
  cout << x << endl;

  return 0;
}

