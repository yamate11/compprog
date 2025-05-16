#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(f:>>)

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

// This is a very ad-hoc implementation...
istream& operator>>(istream& is, __int128& o) {
  string s; is >> s;
  o = 0;
  int sign = 1;
  for (int i = 0; i < ssize(s); i++) {
    if (s[i] == '-') {
      if (i == 0) sign = -1;
      else throw runtime_error(">>: misplaced minus sign");
    }else {
      int d = s[i] - '0';
      if (0 <= d and d <= 9) {
        o = 10 * o + d;
      }else throw runtime_error(">>: not a digit");
    }
  }
  o = sign * o;
  return is;
    
}

// ---- end f:>>

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, A) [h9lYzKab]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [h9lYzKab]
  using sta = tuple<ll, ll, ll>;
  auto RXI = vector(Q, sta());
  for (int i = 0; i < Q; i++) {
    ll r, x; cin >> r >> x;
    RXI[i] = sta(r, x, i);
  }
  sort(ALL(RXI));
  vector<ll> ans(Q);
  vector<ll> vec;
  ll idx = 0;
  for (auto [r, x, i] : RXI) {
    for (; idx < r; idx++) {
      auto k = lower_bound(ALL(vec), A[idx]) - vec.begin();
      if (k == ssize(vec)) vec.push_back(A[idx]);
      else vec[k] = A[idx];
    }
    ll m = lower_bound(ALL(vec), x + 1) - vec.begin();
    ans[i] = m;
  }
  REPOUT(i, 0, Q, ans[i], "\n");
  

  return 0;
}

