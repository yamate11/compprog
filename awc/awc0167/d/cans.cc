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

// @@ !! LIM(doubling)

// ---- inserted library file doubling.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/doubling.cc
// https://github.com/yamate11/compprog-clib/blob/master/doubling.cc

template<typename INT, typename T = monostate, typename Prod_t = monostate>
struct Doubling {
  constexpr static bool hasT = not is_same_v<T, monostate>;

  T unit{};                    // unit for monoid operation
  Prod_t prod{};               // monoid operation
  ll max_call = 0;             // the max value x for f^x
  int num = 0;                 // f: [0, num) -> [0, num)
  vector<vector<INT>> f_tbl{}; // f_tbl[k][i] = f^{2^k}(i)
  vector<vector<T>> t_tbl{};   // t_tbl[k][i] = \prod_{j = 0}^{2^k - 1} m(f^{j}(i))

  void prepare_tbl(ll max_call_, vector<INT> nxt, vector<T> mapping = vector<T>()) {
    max_call = max_call_;
    num = ssize(nxt);
    int k0 = 64 - countl_zero((u64)max_call);
    f_tbl.resize(k0, vector<INT>(num));
    f_tbl[0] = move(nxt);
    for (int k = 1; k < k0; k++) for (int i = 0; i < num; i++) f_tbl[k][i] = f_tbl[k - 1][f_tbl[k - 1][i]];
    if constexpr (hasT) {
      t_tbl.resize(k0, vector<T>(num));
      t_tbl[0] = move(mapping);
      for (int k = 1; k < k0; k++) for (int i = 0; i < num; i++) {
          t_tbl[k][i] = prod(t_tbl[k - 1][i], t_tbl[k - 1][f_tbl[k - 1][i]]);
        }
    }
  }

  pair<INT, T> val_pair(ll r, int i) const {
    int idx = i;
    T ret{};
    if constexpr (hasT) ret = unit;
    for (int k = 0; r > 0; r >>= 1, k++) {
      if (r & 1) {
        if constexpr (hasT) ret = prod(ret, t_tbl[k][idx]);
        idx = f_tbl[k][idx];
      }
    }
    return make_pair(idx, ret);
  }

  INT f_val(ll r, int i) const { return val_pair(r, i).first; }
  T   t_val(ll r, int i) const { return val_pair(r, i).second; }

  ll binsearch_body(auto check, bool lo_exp, int i, ll lo, ll hi) const {
    if (hi < 0) hi = max_call;
    bool hi_checked = false;
    auto [lo_idx, lo_val] = val_pair(lo, i);
    bool start_check = check(lo_val);
    if (lo_exp and not start_check) return lo - 1;
    if (not lo_exp and start_check) return lo;
    // DLOGKL("    ", lo, i, lo_idx, lo_val.left, lo_val.right, lo_val.numinc);
    for (int h = ssize(f_tbl) - 1; h >= 0; h--) {
      if (lo + (1LL << h) > hi) continue;
      T v_inc = prod(lo_val, t_tbl[h][lo_idx]);
      if (check(v_inc) == lo_exp) {
        lo += 1LL << h;
        lo_idx = f_tbl[h][lo_idx];
        lo_val = v_inc;
      }else {
        hi = lo + (1LL << h);
        hi_checked = true;
      }
    }
    // DLOGKL("   .", lo, hi, lo_idx, lo_val.left, lo_val.right, lo_val.numinc, hi_checked);
    if (lo_exp) return lo;
    else if (hi_checked) return hi;
    else return hi + 1;
  }
  ll binsearch_lo(auto check, int i, ll lo = 0, ll hi = -1) const { return binsearch_body(check, true, i, lo, hi); }
  ll binsearch_hi(auto check, int i, ll lo = 0, ll hi = -1) const { return binsearch_body(check, false, i, lo, hi); }
};

template<typename INT>
auto make_doubling(ll max_call, vector<INT> nxt) {
  Doubling<INT> d;
  d.prepare_tbl(max_call, move(nxt));
  return d;
}

template<typename INT, typename T, typename Prod_t>
auto make_doubling(ll max_call, vector<INT> nxt, vector<T> mapping, T unit, Prod_t prod) {
  Doubling<INT, T, decltype(prod)> d(unit, prod);
  d.prepare_tbl(max_call, move(nxt), mapping);
  return d;
}

// ---- end doubling.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [tLFEpv71]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [tLFEpv71]

  if (N == 1) {
    cout << "1\n";
    return 0;
  }

  vector<ll> vecF(N);
  REP(i, 0, N) {
    if (i == N - 1) vecF[i] = N - 1;
    else if (i == 0) vecF[i] = ((A[0] + A[1]) % 2 == 0) ? 1 : 0;
    else vecF[i] = ((A[i] + A[i + 1]) % 2 == 0) ? i + 1 : i - 1;
  }
  auto dobj = make_doubling(K, vecF);
  ll x = dobj.f_val(K, 0);
  cout << x + 1 << "\n";

  return 0;
}

