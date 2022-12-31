#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM(f:>> input)

// ---- inserted function f:>> from util.cc
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
// ---- end f:>>

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --


struct T_t {
  ll x;
  ll l;
  T_t() {}
  T_t(ll x_, ll l_) : x(x_), l(l_) {}
  friend istream& operator>>(istream& istr, T_t& t) {
    istr >> t.x >> t.l;
    return istr;
  }
  bool operator<(const T_t& o) const {
    if (x + l < o.x + o.l) return true;
    return false;
  }
};
// @@DefStruct(T, (x, l), ord=(x, l))

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, T, type=T_t) [f9nrCR0s]
  auto T = vector(N, T_t());
  for (int i = 0; i < N; i++) { T_t v; cin >> v; T[i] = v; }
  // @End [f9nrCR0s]
  sort(ALL(T));
  ll ans = 0;
  ll cur = -1e18;
  for (auto [x, l] : T) {
    if (x - l < cur) continue;
    ans++;
    cur = x + l;
  }
  cout << ans << endl;

  return 0;
}

