#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(f:>>)
// --> f:>>
// ---- inserted function >> from util.cc
template <typename T1, typename T2>
istream& operator>> (istream& is, pair<T1,T2>& p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T1, typename T2, typename T3>
istream& operator>> (istream& is, tuple<T1,T2,T3>& t) {
  is >> get<0>(t) >> get<1>(t) >> get<2>(t);
  return is;
}

template <typename T1, typename T2, typename T3, typename T4>
istream& operator>> (istream& is, tuple<T1,T2,T3,T4>& t) {
  is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t);
  return is;
}

template <typename T>
istream& operator>> (istream& is, vector<T>& v) {
  for (size_t i = 0; i < v.size(); i++) { is >> v[i]; }
  return is;
}

template <typename T>
vector<T> read_vector_n(istream& is, size_t n) {
  vector<T> ret(n);
  for (size_t i = 0; i < n; i++) {
    is >> ret[i];
  }
  return ret;
}

template <typename T>
vector<T> read_vector(istream& is) {
  size_t n; is >> n;
  return read_vector_n<T>(is, n);
}
// ---- end >>
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> W(N), B(N); cin >> W >> B;
  auto memo = vector(51, vector(2000, -1LL));
  auto func = [&](auto rF, ll w, ll b) -> ll {
    ll& ret = memo[w][b];
    if (ret < 0) {
      vector<bool> g(2000);
      if (w > 0) { g[rF(rF, w - 1, b + w)] = true; }
      for (ll k = 1; k <= b / 2; k++) { g[rF(rF, w, b - k)] = true; }
      ll x = 0;
      while (g[x]) { x++; }
      ret = x;
    }
    return ret;
  };
  ll gn = 0;
  for (ll i = 0; i < N; i++) { gn ^= func(func, W[i], B[i]); }
  if (gn) { cout << "First\n"; }
  else { cout << "Second\n"; }

  return 0;
}

