#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
#include <atcoder/dsu>
using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(f:perfmeas UnionFind)

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas


// @@ !! LIM -- end mark --

// ---- inserted library file UnionFind.cc

template<typename T = ll, typename oplus_t = decltype(plus<T>()), typename onegate_t = decltype(negate<T>())>
struct UnionFind {
  int size;
  vector<int> _leader;   // If i is a leader, _leader[i] is not i but -1; for performance reasons.
  vector<int> _gsize;
  bool built_groups;
  int _num_groups;
  vector<vector<int>> _groups;
  
  UnionFind(int size_)
    : size(size_), _leader(size, -1), _gsize(size, 1), built_groups(false) {
  }

  int merge(int i, int j) {
    built_groups = false;
    ll li = leaderpot(i);
    ll lj = leaderpot(j);
    if (li == lj) return li;
    if (_gsize[li] < _gsize[lj]) swap(li, lj);
    _gsize[li] += _gsize[lj];
    _leader[lj] = li;
    return li;
  }

  int leaderpot(int i) {
    int ol = _leader[i];
    if (ol < 0) return i;
    _leader[i] = leaderpot(ol);
    return _leader[i];
  }

  int leader(int i) { return leaderpot(i); }

  int groupSize(int i) { return _gsize[leader(i)]; }

  void build_groups() {
    if (not built_groups) {
      _num_groups = 0;
      for (int j = 0; j < size; j++) if (leader(j) == j) _num_groups++;
      _groups.resize(size);
      for (int j = 0; j < size; j++) _groups[j].resize(0);
      for (int j = 0; j < size; j++) _groups[leader(j)].push_back(j);
      built_groups = true;
    }
  }

  int numGroups() {
    build_groups();
    return _num_groups;
  }

  const vector<int>& group(int i) {
    build_groups();
    return _groups[leader(i)];
  }

};

template<typename T = ll>
auto makeUnionFind(int size, T zero, auto oplus, auto onegate) {
  return UnionFind<T, decltype(oplus), decltype(onegate)>(size, zero, oplus, onegate);
}

// ---- end UnionFind.cc

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  // @InpMVec(K, (A, B)) [yVHjiWib]
  auto A = vector(K, ll());
  auto B = vector(K, ll());
  for (int i = 0; i < K; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [yVHjiWib]

  double t1 = get_time_sec();
  UnionFind uf(N);
  ll ans = 0;
  REP(i, 0, K) {
    ll a = uf.leader(A[i]);
    ll b = uf.leader(B[i]);
    if (a == b) ans++;
    else uf.merge(a, b);
  }
  double t2 = get_time_sec();
  cout << t2 - t1 << endl;

  cerr << ans << endl;

  return 0;
}

