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

// @@ !! LIM(UnionFind)

// ---- inserted library file UnionFind.cc

struct UFDummyAlg {
  static UFDummyAlg zero;
  UFDummyAlg(int x = 0) {}
  UFDummyAlg operator -() const { return *this; }
  UFDummyAlg operator +(const UFDummyAlg& o) const { return *this; }
};
UFDummyAlg UFDummyAlg::zero;

template<typename T = UFDummyAlg, typename oplus_t = decltype(plus<T>()), typename onegate_t = decltype(negate<T>())>
struct UnionFind {

  struct GroupInfo {
    UnionFind& uf;
    vector<vector<int>> _groups;
    GroupInfo(UnionFind& uf_) : uf(uf_), _groups(uf.size) {
      for (int j = 0; j < uf.size; j++) {
        if (uf.leader(j) == j) {
          _groups[j].resize(uf.group_size(j));
          _groups[j].resize(0);
        }
      }
      for (int j = 0; j < uf.size; j++) _groups[uf.leader(j)].push_back(j);
    }
    const vector<int>& group(int i) { return _groups[uf.leader(i)]; }
  };

  int size;
  T zero;
  oplus_t oplus;
  onegate_t onegate;
  vector<int> _leader;
  vector<optional<T>> _pot;
  vector<int> _gsize;
  int _num_groups;
  static constexpr bool _with_pot = not is_same_v<T, UFDummyAlg>;
  
  UnionFind() : size(0), zero((T)0), oplus(plus<T>()), onegate(negate<T>()),
                _leader(0), _pot(0), _gsize(0), _num_groups(0) {}

  UnionFind(int size_, T zero_ = (T)0, oplus_t oplus_ = plus<T>(), onegate_t onegate_ = negate<T>())
    : size(size_), zero(zero_), oplus(oplus_), onegate(onegate_),
      _leader(size, -1), _pot(0), _gsize(size, 1), _num_groups(size) {
    if constexpr (_with_pot) _pot.resize(size, zero);
  }

  void set_size(int size_) {
    size = size_;
    _leader.resize(size, -1);
    if constexpr (_with_pot) _pot.resize(size, zero);
    _gsize.resize(size, 1);
  }

  int merge(int i, int j, T p) {
    int li = leader(i);
    int lj = leader(j);
    optional<T> ld_p;
    if constexpr (_with_pot) {
      if (_pot[i] and _pot[j]) ld_p = oplus(p, oplus(*_pot[j], onegate(*_pot[i])));
      else                     ld_p = nullopt;
    }
    if (li == lj) {
      if constexpr (_with_pot) { if (not (ld_p and *ld_p == zero)) _pot[li] = nullopt; }
      return lj;
    }
    _num_groups--;
    if (_gsize[lj] < _gsize[li]) {
      swap(li, lj);
      if constexpr (_with_pot) if (ld_p) ld_p = onegate(*ld_p);
    }
    // lj is the newleader
    _gsize[lj] += _gsize[li];
    _leader[li] = lj;
    if constexpr (_with_pot) {
      if (_pot[lj] and _pot[li]) _pot[li] = ld_p;
      else _pot[lj] = nullopt;
    }
    return lj;
  }

  template<typename U = T>
  enable_if_t<is_same_v<U, UFDummyAlg>, int> merge(int i, int j) { return merge(i, j, zero); }

  void _leaderpot(int i) {
    int oj = _leader[i];
    if (oj < 0) return;
    int nj = _leader[i] = leader(oj);
    if constexpr (_with_pot) {
      if (_pot[nj]) _pot[i] = oplus(*_pot[i], *_pot[oj]);
      else _pot[i] = nullopt;
    }
  }
  int leader(int i) {
    _leaderpot(i);
    return _leader[i] < 0 ? i : _leader[i];
  }
  optional<T> pot(int i)  { _leaderpot(i); return _pot[i]; }

  int group_size(int i) { return _gsize[leader(i)]; }

  int num_groups() { return _num_groups; }

  GroupInfo group_info() { return GroupInfo(*this); }

};

template<typename T = UFDummyAlg>
auto makeUnionFind(int size, T zero, auto oplus, auto onegate) {
  return UnionFind<T, decltype(oplus), decltype(onegate)>(size, zero, oplus, onegate);
}

// ---- end UnionFind.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    ll H, W; cin >> H >> W;
    // @InpVec(H, S, type=string) [CsvozEBA]
    auto S = vector(H, string());
    for (int i = 0; i < H; i++) { string v; cin >> v; S[i] = v; }
    // @End [CsvozEBA]

    ll sz = (H + 1) * (W + 1) * 2;
    UnionFind uf(sz);
    ll big = 1e18;
    auto enc = [&](ll r, ll c, ll isVert) -> ll { return isVert + 2 * (c + (W + 1) * r); };
    REP(i, 0, H) REP(j, 0, W) {
      ll left = enc(i, j, 1), right = enc(i, j + 1, 1), up = enc(i, j, 0), down = enc(i + 1, j, 0);
      if (S[i][j] == 'A') {
        uf.merge(left, right);
        uf.merge(up, down);
      }else if (S[i][j] == 'B') {
        uf.merge(left, down);
        uf.merge(up, right);
      }else if (S[i][j] == 'C') {
        uf.merge(left, up);
        uf.merge(down, right);
      }else assert(0);
    }
    ll start = uf.leader(enc(0, 0, 1)), goal = uf.leader(enc(H - 1, W, 1));
    vector<vector<ll>> nbr(sz);
    REP(i, 0, H) REP(j, 0, W) {
      ll left  = uf.leader(enc(i, j, 1));
      ll right = uf.leader(enc(i, j + 1, 1));
      ll up =    uf.leader(enc(i, j, 0));
      if (S[i][j] == 'A') {
        if (left != up) {
          nbr[left].push_back(up);
          nbr[up].push_back(left);
        }
      }else if (S[i][j] == 'B' or S[i][j] == 'C') {
        if (left != right) {
          nbr[left].push_back(right);
          nbr[right].push_back(left);
        }
      }else assert(0);
    }
    queue<ll> que;
    vector<ll> dist(sz, big);
    dist[start] = 0;
    que.push(start);
    while (not que.empty()) {
      ll nd = que.front(); que.pop();
      for (ll peer : nbr[nd]) {
        if (dist[peer] == big) {
          dist[peer] = dist[nd] + 1;
          que.push(peer);
        }
      }
    }
    return dist[goal];
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

