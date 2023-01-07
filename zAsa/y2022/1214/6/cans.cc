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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM(UnionFind)

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

// @@ !! LIM -- end mark --

struct Fp2 {
  int v;
  Fp2(int v_ = 0) : v(v_) {}
  Fp2 operator +(const Fp2& o) const { return Fp2(v ^ o.v); }
  Fp2 operator -() const { return Fp2(v); }
  Fp2 operator -(const Fp2& o) const { return Fp2(v ^ o.v); }
  bool operator ==(const Fp2& o) const { return v == o.v; }
  bool operator !=(const Fp2& o) const { return v != o.v; }
};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpMVec(M, ((A, dec=1), (B, dec=1))) [2dfVihTb]
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
  }
  // @End [2dfVihTb]
  UnionFind<Fp2> uf(N);
  vector<bool> inconsis(N, false);
  REP(i, 0, M) if (uf.merge(A[i], B[i], 1) == -1) inconsis[A[i]] = true;
  REP(i, 0, N) if (inconsis[i]) inconsis[uf.leader(i)] = true;
  ll cnt = 0;
  REP(i, 0, N) if (uf.leader(i) == i) {
    ll t = uf.groupSize(i);
    if (inconsis[i]) cnt += t * (t - 1) / 2;
    else {
      ll t0 = 0, t1 = 0;
      for (int n : uf.group(i)) if (uf.pot(n).second == 0) t0++; else t1++;
      cnt += t0 * t1;
    }
  }
  cout << cnt - M << endl; 

  return 0;
}

