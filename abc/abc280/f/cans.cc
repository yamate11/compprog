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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(UnionFind input)

// ---- inserted library file UnionFind.cc

template<typename T = int>
struct UnionFind {
  int size;
  bool built;
  vector<pair<int, T>> _leader;
  vector<int> _gsize;
  unordered_map<int, vector<int>> _groups;
  
  UnionFind(int size_) : size(size_), built(false), _leader(), _gsize(size, 1) {
    for (int i = 0; i < size; i++) _leader.emplace_back(i, (T)0);
  }

  int merge(int i, int j, const T& p = (T)0) {
    built = false;
    auto [li, pi] = pot(i);
    auto [lj, pj] = pot(j);
    if (li == lj) {
      if (p + pj == pi) return li;
      else return -1;
    }
    int new_leader;
    if (_gsize[li] < _gsize[lj]) {
      new_leader = lj;
      _gsize[new_leader] += _gsize[li];
      _leader[li].first = new_leader;
      _leader[li].second = p + pj - pi;
    }else {
      new_leader = li;
      _gsize[new_leader] += _gsize[lj];
      _leader[lj].first = new_leader;
      _leader[lj].second = - (p + pj - pi);
    }
    return new_leader;
  }

  pair<int, T> pot(int i) {
    int cur = i;
    vector<pair<int, T>> seen;
    {
      auto [nxt, p] = _leader[cur];
      while (cur != nxt) {
        seen.emplace_back(cur, p);
        cur = nxt;
        tie(nxt, p) = _leader[cur];
      }
    }
    T pp = (T)0;
    while (not seen.empty()) {
      auto [j, p] = seen.back(); seen.pop_back();
      pp = pp + p;
      _leader[j] = {cur, pp};
    }
    return {cur, pp};
  }

  int leader(int i) { return pot(i).first; }

  int groupSize(int i) { return _gsize[leader(i)]; }

  unordered_map<int, vector<int>>& groups() {
    if (not built) {
      for (int i = 0; i < size; i++) _groups[i].resize(0);
      for (int i = 0; i < size; i++) _groups[leader(i)].push_back(i);
      built = true;
    }
    return _groups;
  }

  const vector<int>& group(int i) { return groups()[leader(i)]; }

};

// ---- end UnionFind.cc

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, Q; cin >> N >> M >> Q;
  // @InpMVec(M, ((A, dec=1), (B, dec=1), C)) [jObx95j4]
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
    ll v3; cin >> v3; C[i] = v3;
  }
  // @End [jObx95j4]
  UnionFind<ll> uf(N);
  vector hasLoop(N, false);
  REP(i, 0, M) {
    ll rc = uf.merge(B[i], A[i], C[i]);
    if (rc < 0) hasLoop[uf.leader(A[i])] = true;
  }
  REP(_q, 0, Q) {
    ll x, y; cin >> x >> y; x--; y--;
    ll lx = uf.leader(x);
    ll ly = uf.leader(y);
    if (lx != ly) cout << "nan\n";
    else if (hasLoop[lx]) cout << "inf\n";
    else cout << uf.pot(y).second - uf.pot(x).second << endl;
  }

  return 0;
}

