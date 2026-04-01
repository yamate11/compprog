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

// @@ !! LIM(fastTransform)

// ---- inserted library file fastTransform.cc

template <typename T>
int trans_resize(vector<T>& x, vector<T>& y) {
  int n = max(x.size(), y.size());
  int p = 31 - __builtin_clz(n);
  int t = 1 << p;
  if (n > t) t *= 2;
  x.resize(t);
  y.resize(t);
  return t;
}

template<typename T>
int trans_resize(vector<T>& x) { return trans_resize(x, x); }

template<typename T, int p1, int p2, int p3, int p4, int div>
void _trans_form(vector<T>& f) {
  int n = f.size();
  for (int i = 1; i < n; i *= 2) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        T x = f[j];
        T y = f[j | i];
        f[j    ] = (p1 * x + p2 * y) / div;
        f[j | i] = (p3 * x + p4 * y) / div;
      }
    }
  }
}

template <typename T>
void hadamard(vector<T>& f) { _trans_form<T, 1, 1, 1, -1, 1>(f); }

template <typename T>
void inv_hadamard(vector<T>& f) { _trans_form<T, 1, 1, 1, -1, 2>(f); }

template<bool IS_LOWER, bool IS_ZETA>
void gen_zeta(auto& vec) {
  int n = countr_zero(vec.size());
  assert(ssize(vec) == (1LL << n));
  for (int i = 0; i < n; i++) {
    for (int x = 0; x < ssize(vec); x++) {
      if ((x >> i & 1) == IS_LOWER) { vec[x] += (IS_ZETA ? 1 : -1) * vec[x ^ 1LL << i]; }
    }
  }
}
void zeta_lower(   auto& vec) { return gen_zeta<true,  true >(vec); }
void moebius_lower(auto& vec) { return gen_zeta<true,  false>(vec); }
void zeta_upper(   auto& vec) { return gen_zeta<false, true >(vec); }
void moebius_upper(auto& vec) { return gen_zeta<false, false>(vec); }

template<typename T>
void _conv_dest_form(vector<T>& x, vector<T>& y,
                     void fwd(vector<T>&), void bwd(vector<T>&)) {
  int t = trans_resize(x, y);
  fwd(x);
  fwd(y);
  for (int i = 0; i < t; i++) x[i] *= y[i];
  bwd(x);
}

template<typename T>
void xor_conv_dest(vector<T>& x, vector<T>& y) {
  _conv_dest_form(x, y, hadamard, inv_hadamard);
}

template<typename T>
void and_conv_dest(vector<T>& x, vector<T>& y) {
  _conv_dest_form(x, y, zeta_upper, moebius_upper);
}

template<typename T>
void or_conv_dest(vector<T>& x, vector<T>& y) {
  _conv_dest_form(x, y, zeta_lower, moebius_lower);
}

template <typename T>
vector<T> xor_conv(vector<T> x, vector<T> y) {
  xor_conv_dest(x, y);
  return x;
}

template <typename T>
vector<T> and_conv(vector<T> x, vector<T> y) {
  and_conv_dest(x, y);
  return x;
}

template <typename T>
vector<T> or_conv(vector<T> x, vector<T> y) {
  or_conv_dest(x, y);
  return x;
}

// ---- end fastTransform.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpVec(N, W) [0Ji2yTtt]
  auto W = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; W[i] = v; }
  // @End [0Ji2yTtt]
  // @InpVec(M, C) [mOFKTGEn]
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; C[i] = v; }
  // @End [mOFKTGEn]

  vector<ll> V(1LL << N, 0LL);
  REP(x, 0, 1LL << N) {
    ll s = 0;
    REP(i, 0, N) if (x >> i & 1) s += W[i];
    V[x] = s;
  }

  vector<ll> tbl(1LL << N, 0);
  tbl[0] = 1;
  REP(i, 0, M) {
    vector loc(1LL << N, 0LL);
    REP(x, 0, 1LL << N) if (V[x] <= C[i]) loc[x] = 1;
    tbl = or_conv(tbl, loc);
    REP(x, 0, 1LL << N) if (tbl[x] > 0) tbl[x] = 1;
  }
  cout << (tbl[(1LL << N) - 1] > 0 ? "Yes\n" : "No\n");
  return 0;
}

