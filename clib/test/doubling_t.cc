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

// @@ !! LIM(doubling)

// ---- inserted library file doubling.cc
#line 40 "/home/y-tanabe/proj/compprog/clib/doubling.cc"

struct DoublingFRel { // from functional relation
  int n;
  vector<vector<int>> tbl;

  void _init(long long lim, auto frel) {
    int K = 64 - __builtin_clzll(lim);
    tbl.resize(K, vector<int>(n));
    for (int i = 0; i < n; i++) tbl[0][i] = frel(i);
    for (int k = 0; k + 1 < K; k++) for (int i = 0; i < n; i++) tbl[k + 1][i] = tbl[k][tbl[k][i]];
  }

  DoublingFRel(long long lim, int n_, auto frel) : n(n_) { _init(lim, frel); }

  int val(long long x, int i) { // Calculates frel^{(x)}(i).  Should be x <= lim.
    for (int k = 0; x > 0; x >>= 1, k++) if (x & 1) i = tbl[k][i];
    return i;
  }
};
  
template <typename T>
struct DoublingCum {
  const DoublingFRel& d;
  vector<vector<T>> tbl;

  void _init(auto mapping) {
    int K = d.tbl.size();
    tbl.resize(K, vector<T>(d.n));
    for (int i = 0; i < d.n; i++) tbl[0][i] = mapping(i);
    for (int k = 0; k + 1 < K; k++) for (int i = 0; i < d.n; i++) tbl[k + 1][i] = tbl[k][i] + tbl[k][d.tbl[k][i]];
  }

  DoublingCum(const DoublingFRel& d_, auto mapping) : d(d_) { _init(mapping); }

  T val(long long x, int i) { // the monoid sum of x objs from i.  i.e. from i to i + x - 1.
    T ret = T();
    for (int k = 0; x > 0; x >>= 1, k++) if (x & 1) {
        ret = ret + tbl[k][i];
        i = d.tbl[k][i];
      }
    return ret;
  }
};

// ---- end doubling.cc

// @@ !! LIM -- end mark --
#line 15 "doubling_skel.cc"

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  
  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  { // ABC179-E  
    using vll = vector<ll>;
    auto func = [&](ll N, ll K, const vll& A) -> ll {
      auto d1 = DoublingFRel(K, N, [&](int i) -> int { return (i + A[i]) % N; });
      auto d2 = DoublingCum<ll>(d1, [&](int i) -> ll { return A[i]; });
      return d2.val(K, 0);
    };
    assert(func(5, 3, vll({2, 1, 6, 3, 1})) == 11);
    assert(func(10, 1000000000000, vll({260522, 914575, 436426, 979445, 648772, 690081, 933447, 190629, 703497, 47202})));
  }

  {
    ll n = 10;
    ll K = 100;
    ll rep = 1000;
    vector<ll> A(n), B(n);
    REP(i, 0, n) {
      A[i] = randrange(0, n);
      B[i] = randrange(0, (ll)1e9);
    }
    auto naive = [&](ll r, ll x) -> ll {
      REP(i, 0, r) x = A[x];
      return x;
    };
    auto naive2 = [&](ll r, ll x) -> ll {
      ll s = 0;
      REP(i, 0, r) {
        s += B[x];
        x = A[x];
      }
      return s;
    };
    auto d = DoublingFRel(K, n, [&](int i) -> int { return A[i]; });
    auto d2 = DoublingCum<ll>(d, [&](int i) -> ll { return B[i]; });
    REP(i, 0, rep) {
      ll r = randrange(0, K + 1);
      ll x = randrange(0, n);
      assert(naive(r, x) == d.val(r, x));
    }
    REP(i, 0, rep) {
      ll r = randrange(0, K + 1);
      ll x = randrange(0, n);
      assert(naive2(r, x) == d2.val(r, x));
    }
    REP(i, 0, rep) {
      ll k = randrange(1, K + 1);
      ll x = randrange(0, n);
      auto d3 = DoublingFRel(k, n, [&](int j) -> int { return A[j]; });
      assert(naive(k, x) == d3.val(k, x));
    }
    REP(i, 0, rep) {
      ll k = randrange(1, K + 1);
      ll x = randrange(0, n);
      auto d4 = DoublingFRel(k, n, [&](int j) -> int { return A[j]; });
      auto d5 = DoublingCum<ll>(d4, [&](int j) -> ll { return B[j]; });
      assert(naive2(k, x) == d5.val(k, x));
    }

  }

  cout << "ok" << endl;
  return 0;
}

