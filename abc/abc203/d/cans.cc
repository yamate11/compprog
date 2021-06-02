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

  ll N, K; cin >> N >> K;
  vector<vector<ll>> A(N, vector<ll>(N));
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }
  auto check = [&](ll m) -> bool {
    vector<vector<ll>> B(N, vector<ll>(N));
    for (ll i = 0; i < N; i++) {
      for (ll j = 0; j < N; j++) {
        if (A[i][j] <= m) B[i][j] = 1;
        else              B[i][j] = 0;
      }
    }
    vector<vector<ll>> S(N + 1, vector<ll>(N + 1));
    for (ll i = 1; i <= N; i++) {
      for (ll j = 1; j <= N; j++) {
        S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + B[i - 1][j - 1];
      }
    }
    ll lim;
    if (K % 2 == 0) lim = K * K / 2;
    else            lim = K * K / 2 + 1;
    for (ll i = 0; i <= N - K; i++) {
      for (ll j = 0; j <= N - K; j++) {
        ll t = S[i + K][j + K] - S[i][j + K] - S[i + K][j] + S[i][j];
        if (t >= lim) { return true; }
      }
    }
    return false;
  };

  ll m = binsearch_i<ll>(check, 1e9, -1);
  cout << m << endl;


  return 0;
}

