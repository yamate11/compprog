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

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [jhxtogGM]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [jhxtogGM]

  vector<ll> D(N + 1, 0LL);
  REP(i, 0, M) {
    ll l, r, d; cin >> l >> r >> d; l--;
    D[l] += d;
    D[r] -= d;
  }
  ll cur = 0;
  REP(i, 0, N) {
    cur += D[i];
    cout << A[i] + cur << "\n";
  }

  return 0;
}

