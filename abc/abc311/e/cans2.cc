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

// @@ !! LIM(mapget)

// ---- inserted library file mapget.cc

template<typename MP>
struct mgs : MP {
  using Key = typename MP::key_type;
  using T = typename MP::mapped_type;

  T def;

  mgs(const T& def_ = T()) : MP(), def(def_) {}
  mgs(const mgs& o) : MP(o), def(o.def) {}
  mgs(mgs&& o) : MP(move(o)), def(move(o.def)) {}
  mgs& operator =(const mgs& o) {
    MP::operator=(o);
    def = o.def;
    return *this;
  }
  mgs& operator =(mgs&& o) {
    MP::operator=(move(o));
    def = move(o.def);
    return *this;
  }

  const T& get(const Key& k) const {
    auto it = this->find(k);
    if (it == this->end()) return def;
    else return it->second;
  }

  template<typename T1>
  void set(const Key& k, T1&& t) {
    if (t == def) this->erase(k);
    else (*this)[k] = forward<T1>(t);
  }
};

// ---- end mapget.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, N; cin >> H >> W >> N;
  // @InpMVec(N, ((A, dec=1), (B, dec=1))) [Nu6BM0Fj]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
  }
  // @End [Nu6BM0Fj]
  set<pll> ss;
  REP(i, 0, N) ss.emplace(A[i], B[i]);

  vector tbl(H, vector(W, 0LL));
  REP(i, 0, H) REP(j, 0, W) {
    if (ss.contains(pll(i, j))) tbl[i][j] = 0;
    else if (i == 0 or j == 0) tbl[i][j] = 1;
    else {
      ll a = tbl[i - 1][j];
      ll b = tbl[i][j - 1];
      ll c = tbl[i - 1][j - 1];
      if (a == 0 or b == 0 or c == 0) tbl[i][j] = 1;
      else if (a != b) tbl[i][j] = min(a, b) + 1;
      else if (c == a - 1) tbl[i][j] = a;
      else tbl[i][j] = a + 1;
    }
  }
  ll ans = 0;
  REP(i, 0, H) REP(j, 0, W) ans += tbl[i][j];
  cout << ans << endl;
  

  return 0;
}

