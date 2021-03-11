#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

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

ll N;
vector<vector<vector<ll>>> tbl;
vector<ll> A;

ll gg(ll l, ll r, ll n) {
  ll& ret = tbl[l][r][n];
  if (ret < 0) {
    ll t = 0;
    if (0 < l || r <= N) {
      if (n < N - (r - l - 1)) {
        ll ov = (A[l] < A[r]) ? gg(l, r + 1, n + 1) : gg(l - 1, r, n + 1);
        if (t < ov) t = ov;
      }
      if (n-1 >= 0 && l-1 >= 0 )  {
        ll ov = A[l] + gg(l-1, r, n-1);
        if (t < ov) t = ov;
      }
      if (n-1 >= 0 && r+1 < N+2)  {
        ll ov = A[r] + gg(l, r+1, n-1);
        if (t < ov) t = ov;
      }
    }
    ret = t;
  }
  return ret;
};

/*
ll gg(ll l, ll r, ll n) {
  ll& ret = tbl[l][r][n];
  if (ret < 0) {
    ll t = 0;
    if (0 < l || r <= N) {
      if (n < N - (r - l - 1)) {
        if (A[l] < A[r]) updMax(t, gg(l, r + 1, n + 1));
        else             updMax(t, gg(l - 1, r, n + 1));
      }
      if (n-1 >= 0 && l-1 >= 0 )  updMax(t, A[l] + gg(l-1, r, n-1));
      if (n-1 >= 0 && r+1 < N+2)  updMax(t, A[r] + gg(l, r+1, n-1));
    }
    ret = t;
  }
  return ret;
};
*/

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  cin >> N;
  tbl = vector(N + 1, vector(N + 2, vector(N + 1, -1LL)));
  A = vector(N + 2, 0LL);
  for (ll i = 1; i <= N; i++) cin >> A[i];
  A[0] = A[N+1] = -1;
  /*
  auto func = [&](auto rF, ll l, ll r, ll n) -> ll {
    ll& ret = tbl[l][r][n];
    if (ret < 0) {
      ll t = 0;
      if (0 < l || r <= N) {
        if (n < N - (r - l - 1)) {
          if (A[l] < A[r]) updMax(t, rF(rF, l, r + 1, n + 1));
          else             updMax(t, rF(rF, l - 1, r, n + 1));
        }
        if (n-1 >= 0 && l-1 >= 0 )  updMax(t, A[l] + rF(rF, l-1, r, n-1));
        if (n-1 >= 0 && r+1 < N+2)  updMax(t, A[r] + rF(rF, l, r+1, n-1));
      }
      ret = t;
    }
    return ret;
  };
  */
  for (ll i = 0; i <= N; i++) {
    // cout << func(func, i, i + 1, 1) << "\n";
    cout << gg(i, i + 1, 1) << "\n";
  }

  return 0;
}

