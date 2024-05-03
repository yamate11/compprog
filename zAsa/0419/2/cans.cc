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

template<typename T = ll, typename MAP = unordered_map<T, int>>
class CoordCompr {
  bool built;
  MAP mp;
                       // map from an original value to a compressed value
  vector<T> rev;      // vector of original values

  void build() {
    built = true;
    sort(rev.begin(), rev.end());
    rev.erase(unique(rev.begin(), rev.end()), rev.end());
    mp = MAP();
    for (size_t i = 0; i < rev.size(); i++) mp[rev[i]] = i;
  }

public:

  CoordCompr() : built(false) {}
  CoordCompr(const vector<T>& vec) : built(false), rev(vec) {}
  CoordCompr(vector<T>&& vec) : built(false), rev(move(vec)) {}

  void add(const T& x) {
    rev.push_back(x);
    built = false;
  }

  void add(const vector<T>& vec) {
    for (const T& x : vec) rev.push_back(x);
    built = false;
  }

  int c(const T& x) {
    if (! built) build();
    return mp[x];
  }

  T d(int i) {
    if (! built) build();
    return rev[i];
  }

  int size() {
    if (! built) build();
    return rev.size();
  }

};

// ---- end coordCompr.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  // @InpMVec(N, (A, B)) [gZjifKde]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [gZjifKde]

  CoordCompr cc;
  cc.add(0);
  REP(i, 0, N) cc.add(A[i]);
  ll sz = cc.size();
  vector<ll> C(sz);
  REP(i, 0, N) C[cc.c(A[i])] += B[i];
  ll t = accumulate(ALL(B), 0LL);
  REP(i, 0, sz) {
    t -= C[i];
    if (t <= K) {
      cout << cc.d(i) + 1 << endl;
      return 0;
    }
  }
  return 0;
}

