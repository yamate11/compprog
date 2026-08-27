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

// @@ !! LIM(coordCompr)

// ---- inserted library file coordCompr.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/coordCompr.cc

template <class T = ll, class Compare = std::less<T>>
struct CoordCompr {
  mutable bool built = false;
  mutable vector<T> rev;
  Compare comp;

  CoordCompr() = default;
  explicit CoordCompr(Compare c) : built(false), rev(), comp(move(c)) {}
  explicit CoordCompr(vector<T> v, Compare c = Compare{}) : built(false), rev(std::move(v)), comp(move(c)) {}

  void add(const T& x) { rev.push_back(x); built = false; }

  void add(const vector<T>& v) {
    rev.insert(rev.end(), v.begin(), v.end());
    built = false;
  }

  bool equiv(const T& a, const T& b) const { return !comp(a, b) && !comp(b, a); }

  void build() const {
    if (built) return;
    sort(rev.begin(), rev.end(), comp);
    rev.erase(unique(rev.begin(), rev.end(), [this](const T& a, const T& b) { return equiv(a, b); }),
              rev.end());
    built = true;
  }

  int c(const T& x) const {
    build();
    auto it = lower_bound(rev.begin(), rev.end(), x, comp);
    assert(it != rev.end() && equiv(*it, x));
    return (int)(it - rev.begin());
  }

  const T& d(int i) const {
    build();
    assert(0 <= i and i < (int)rev.size());
    return rev[i];
  }

  int size() const {
    build();
    return (int)rev.size();
  }
};

// ---- end coordCompr.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, D, T; cin >> N >> M >> D >> T;
  // @InpVec(N, A) [GmGr8w1P]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [GmGr8w1P]
  // @InpVec(M, B) [Vnb0nufL]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [Vnb0nufL]
  
  CoordCompr cc;
  cc.add(1);
  cc.add(T);
  REP(i, 0, N) {
    cc.add(A[i]);
    cc.add(A[i] + D);
  }
  REP(i, 0, M) {
    cc.add(B[i]);
    cc.add(B[i] + D);
  }
  ll sz = cc.size();
  vector<ll> diff(sz);
  REP(i, 0, N) {
    diff[cc.c(A[i])]++;
    diff[cc.c(A[i] + D)]--;
  }
  REP(i, 0, M) {
    diff[cc.c(B[i])]--;
    diff[cc.c(B[i] + D)]++;
  }
  ll cur = 0;
  ll ans = 0;
  REP(i, 0, sz) {
    if (cc.d(i) > T) break;
    cur += diff[i];
    if (cur > 0) {
      ll t;
      if (cc.d(i) == T) t = T + 1;
      else t = cc.d(i + 1);
      ans += t - cc.d(i);
    }
  }
  cout << ans << "\n";
  return 0;
}

