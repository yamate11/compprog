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

// @@ !! LIM(wavelet tree)

// ---- inserted library file wavelet.cc

struct BitVector {
  ll N;
  ll vsize;
  vector<int> vs;
  vector<u64> vb;
  bool built;
  BitVector() = default;
  BitVector(ll N_) : N(N_), vsize((N + 63) / 64), vs(vsize + 1), vb(vsize), built(false) {}
  void set(bool val, int k) {
    if (built) throw runtime_error("already built.");
    if (val) vb[k >> 6] |=   1ULL << (k & 63);
    else     vb[k >> 6] &= ~(1ULL << (k & 63));
  }
  bool at(ll k) { return static_cast<bool>(vb[k >> 6] >> (k & 63) & 1); }
  void build() {
    if (not built) {
      for (ll i = 0; i < vsize; i++) vs[i + 1] = vs[i] + popcount(vb[i]);
      built = true;
    }
  }
  ll rank(bool val, ll k) {
    if (not built) build();
    ll cnt1 = (k >= N) ? vs.back() : vs[k >> 6] + popcount(vb[k >> 6] & ((1ULL << (k & 63)) - 1));
    if (val) return cnt1;
    else     return k - cnt1;
  }

  // for debugging
  vector<bool> vec_view() {
    vector<bool> vec(N);
    for (ll i = 0; i < N; i++) vec[i] = at(i);
    return vec;
  }

};

template<typename INT=ll>
struct WaveletMatrix {
  ll N;
  ll ht;
  vector<BitVector> vbv;
  vector<int> mid;

  pair<bool, INT> _h_rest(ll h, INT t) { return {t >> h & 1, t & ((static_cast<INT>(1) << h) - 1)}; }

  WaveletMatrix() = default;
  WaveletMatrix(const auto& vec, ll amax) { _init(vec, amax); }
  void _init(const auto& vec, ll amax) {
    if (amax < 0) amax = vec.empty() ? 1 : *max_element(vec.begin(), vec.end());
    N = ssize(vec);
    ht = bit_width((u64)amax);
    vbv = vector(ht, BitVector(N));
    mid = vector<int>(ht);
    vector tmpA{vec, vector<INT>(N)};
    vector tmpB(2, vector<INT>(N));
    vector<ll> a{N, 0};
    vector<ll> b{0, 0};
    for (ll h = ht - 1; h >= 0; h--) {
      for (int e = 0; e < 2; e++) {
        for (ll i = 0; i < a[e]; i++) {
          auto [x, y] = _h_rest(h, tmpA[e][i]);
          vbv[h].set(x, e == 0 ? i : a[0] + i);
          tmpB[x][b[x]++] = y;
        }
      }
      mid[h] = b[0];
      swap(tmpA, tmpB);
      a = b;
      b[0] = b[1] = 0;
    }
  }
  
  pair<ll, ll> _next_range(bool x, ll l, ll r, ll h) {
    return {x * mid[h] + vbv[h].rank(x, l), x * mid[h] + vbv[h].rank(x, r)};
  }

  // vec[p]
  INT access(ll p) {
    INT ret = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      bool x = vbv[h].at(p);
      if (x == 1) ret |= INT(1) << h;
      if (x == 0) p =          vbv[h].rank(0, p);
      else        p = mid[h] + vbv[h].rank(1, p);
    }
    return ret;
  }

  // #{ i < r : vec[i] == t }
  ll rank(INT t, ll r) {
    if (bit_width((u64)t) > ht) return 0;
    ll l = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      ll x = t >> h & 1;
      tie (l, r) = _next_range(x, l, r, h);
    }
    return r - l;
  }

  // k-th smallest value in vec[l, r)   (0-indexed)
  INT kth_smallest(ll k, ll l, ll r) {
    if (k < 0 or k >= r - l) throw runtime_error("k out of range");
    INT ret = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      ll num0 = vbv[h].rank(0, r) - vbv[h].rank(0, l);
      bool x = k >= num0;
      if (x) {
        k -= num0;
        ret |= INT(1) << h;
      }
      tie(l, r) = _next_range(x, l, r, h);
    }
    return ret;
  }

  // k-th largest value in vec[l, r)   (0-indexed)
  INT kth_largest(ll k, ll l, ll r) { return kth_smallest(r - l - 1 - k, l, r); }

  // #{ i \in [l, r) : vec[i] < hi }
  ll range_freq(INT hi, ll l, ll r) {
    if (bit_width((u64)hi) > ht) return r - l;
    ll ret = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      ll x = hi >> h & 1;
      if (x == 1) ret += vbv[h].rank(0, r) - vbv[h].rank(0, l);
      tie(l, r) = _next_range(x, l, r, h);
    }
    return ret;
  }

  // #{i \in [l, r) : lo <= vec[i] < hi }
  ll range_freq(INT lo, INT hi, ll l, ll r) { return range_freq(hi, l, r) - range_freq(lo, l, r); }


};



// ---- end wavelet.cc

// ---- inserted library file tree.cc

struct function_error : runtime_error {
  function_error(const string& msg) : runtime_error(msg) {}
};

struct Tree {

  struct pe_t {
    ll peer;
    ll edge;
    pe_t(ll peer_ = -1, ll edge_ = -1) : peer(peer_), edge(edge_) {}
    static const pe_t end_object;
  };

  struct nbr_t {
    ll parent_idx;                 // pe[parent_idx] is the parent
    vector<pe_t> pe;
    nbr_t() : parent_idx(-1), pe() {}
  };

  template<bool get_peer>
  struct nbr_iterator {
    const nbr_t& body;
    ll pe_idx;
    explicit nbr_iterator(const nbr_t& body_, ll pe_idx_) : body(body_), pe_idx(pe_idx_) {
      if (pe_idx == body.parent_idx) pe_idx++;
    }
    auto operator*() const -> typename conditional<get_peer, ll, const pe_t&>::type {
      if constexpr (get_peer) return body.pe[pe_idx].peer;
      else                    return body.pe[pe_idx];
    }
    const nbr_iterator& operator++() {
      pe_idx++;
      if (pe_idx == body.parent_idx) pe_idx++;
      return *this;
    }
    bool operator !=(const nbr_iterator& o) const { return pe_idx != o.pe_idx; }
  };

  template<bool get_peer>
  struct children_view {
    const nbr_t& body;
    children_view(const nbr_t& body_) : body(body_) {}
    nbr_iterator<get_peer> begin() const { return nbr_iterator<get_peer>(body, 0); }
    nbr_iterator<get_peer> end() { return nbr_iterator<get_peer>(body, std::ssize(body.pe)); }
  };

  ll numNodes;
  ll root;
  vector<nbr_t> _nbr;
  vector<pair<ll, ll>> _edges;   // (x, y) in _edges => x < y
  vector<ll> _parent;             // _parent[root] == -1
  vector<ll> _stsize;
  vector<ll> _depth;
  unordered_map<ll, ll> _edge_idx;
  vector<ll> _euler_in;
  vector<ll> _euler_out;
  vector<pair<ll, bool>> _euler_edge;
  vector<vector<vector<ll>>> _lca_tbl;

  constexpr static bool use_depth = true;
  constexpr static bool use_stsize = true;
  constexpr static bool use_euler = true;

  Tree(ll numNodes_, ll root_ = 0) : numNodes(numNodes_), root(root_), _nbr(numNodes_) {
    if (numNodes == 1) _set_parent();
  }

  ll add_edge(ll x, ll y) {
    ll i = ssize(_edges);
    if (i >= numNodes - 1) throw range_error("add_edge");
    _nbr[x].pe.emplace_back(y, i);
    _nbr[y].pe.emplace_back(x, i);
    _edges.emplace_back(min(x, y), max(x, y));
    if (i + 1 == numNodes - 1) _set_parent();
    return i;
  }

  void _set_parent() {   // called from constructor, add_edge() and change_root()

    _nbr[root].parent_idx = ssize(_nbr[root].pe);

    if constexpr (use_depth) _depth.resize(numNodes);
    if constexpr (use_stsize) _stsize.resize(numNodes);
    if constexpr (use_euler) {
      _euler_in.resize(numNodes);
      _euler_out.resize(numNodes);
      _euler_edge.resize(2 * numNodes);
    }
    ll euler_idx = 0;

    auto dfs = [&](auto rF, ll nd, ll pt, ll edge) -> void {
      if constexpr (use_depth) _depth[nd] = pt == -1 ? 0 : _depth[pt] + 1;
      if constexpr (use_stsize) _stsize[nd] = 1;
      if constexpr (use_euler) {
        _euler_edge[euler_idx] = {edge, nd < pt};
        _euler_in[nd] = euler_idx;
        euler_idx++;
      }
      for (ll i = 0; i < ssize(_nbr[nd].pe); i++) {
        auto [c_id, c_eg] = _nbr[nd].pe[i];
        if (c_id == pt) _nbr[nd].parent_idx = i;
        else {
          rF(rF, c_id, nd, c_eg);
          if constexpr (use_stsize) _stsize[nd] += _stsize[c_id];
        }
      }
      if constexpr (use_euler) {
        _euler_edge[euler_idx] = {edge, pt < nd};
        _euler_out[nd] = euler_idx;
        euler_idx++;
      }
    };

    dfs(dfs, root, -1, numNodes - 1);
  }

  pe_t parent_pe(ll nd) { return _nbr[nd].pe[_nbr[nd].parent_idx]; }
  ll parent(ll nd) { return nd == root ? -1 : parent_pe(nd).peer; }
  ll num_children(ll nd) { return _nbr[nd].pe.size() - (_nbr[nd].parent_idx == (ll)_nbr[nd].pe.size() ? 0 : 1); }
  pe_t child_pe(ll nd, ll idx) { return _nbr[nd].pe[idx < _nbr[nd].parent_idx ? idx : idx + 1]; }
  ll child(ll nd, ll idx) { return child_pe(nd, idx).peer; }
  ll child_edge(ll nd, ll idx) { return child_pe(nd, idx).edge; }
  auto children_pe(ll nd) { return children_view<false>(_nbr[nd]); }
  auto children(ll nd) { return children_view<true>(_nbr[nd]); }

  ll stsize(ll nd) {
    if constexpr (use_stsize) return _stsize[nd];
    else throw function_error("use_stsize should be set to call stsize.");
  }

  ll depth(ll nd) {
    if constexpr (use_depth) return _depth[nd];
    else throw function_error("use_depth should be set to call depth.");
  }

  ll _enc_node_pair(ll x, ll y) { return (x + 1) * (numNodes + 1) + (y + 1); }

  ll edge_idx(ll x, ll y) {
    if (_edge_idx.empty()) {
      for (ll i = 0; i < ssize(_edges); i++) {
        auto [xx, yy] = _edges[i];
        _edge_idx[_enc_node_pair(xx, yy)] = i;
        _edge_idx[_enc_node_pair(yy, xx)] = i;
      }
    }
    auto it = _edge_idx.find(_enc_node_pair(x, y));
    return it == _edge_idx.end() ? -1 : it->second;
  }

  pair<ll, ll> nodes_of_edge(ll e) { return _edges[e]; }

  void _set_euler() {
    _euler_in.resize(numNodes);
    _euler_out.resize(numNodes);
    vector<pair<ll, ll>> stack{{root, -1}};
    ll idx = 0;
    while (not stack.empty()) {
      auto& [nd, cidx] = stack.back();
      if (cidx == -1) _euler_in[nd] = idx++;
      cidx++;
      if (cidx < num_children(nd)) stack.emplace_back(child(nd, cidx), -1);
      else {
        _euler_out[nd] = idx++;
        stack.pop_back();
      }
    }
  }

  ll euler_in(ll nd) {
    if constexpr (use_euler) return _euler_in[nd];
    else throw function_error("use_euler should be set to call euler_in.");
  }

  ll euler_out(ll nd) {
    if constexpr (use_euler) return _euler_out[nd];
    else throw function_error("use_euler should be set to call euler_out.");
  }

  tuple<ll, ll, ll> euler_edge(ll idx) {
    if constexpr (use_euler) {
      if (idx == 0) return {numNodes - 1, -1, root};
      else if (idx == 2 * numNodes - 1) return {numNodes - 1, root, -1};
      else {
        auto [e, b] = _euler_edge[idx];
        auto [x, y] = nodes_of_edge(e);
        if (b) swap(x, y);
        return {e, x, y};
      }
    }
    else throw function_error("use_euler should be set to call euler_out.");
  }

  // Lowest Common Ancestor
  ll lca(ll x, ll y) {
    ll kmax = 1 + bit_width((unsigned)numNodes);
    ll lastmove = 2 * numNodes - 2;
    if (_lca_tbl.empty()) {
      auto choose = [&](const auto& vec, ll a, ll b) -> ll {
        if (0 <= b and b <= lastmove and vec[b] >= 0) return depth(vec[a]) < depth(vec[b]) ? vec[a] : vec[b];
        else return -1;
      };
      _lca_tbl.resize(kmax + 1, vector(2, vector(lastmove + 1, -1LL)));
      for (ll s = 0; s < 2; s++) for (ll i = 0; i <= lastmove; i++) _lca_tbl[0][s][i] = get<2>(euler_edge(i));
      for (ll k = 1; k <= kmax; k++) {
        ll prev_len = 1 << (k - 1);
        for (ll s = 0; s < 2; s++) {
          for (ll i = 0; i <= lastmove; i++) _lca_tbl[k][0][i] = choose(_lca_tbl[k - 1][0], i, i + prev_len);
          for (ll i = 0; i <= lastmove; i++) _lca_tbl[k][1][i] = choose(_lca_tbl[k - 1][1], i, i - prev_len);
        }
      }
    }
    ll a = euler_in(x), b = euler_in(y);
    if (a > b) swap(a, b);
    ll k = countr_zero(bit_floor((unsigned)(b - a + 1)));
    ll i = _lca_tbl[k][0][a];
    ll j = _lca_tbl[k][1][b];
    return depth(i) < depth(j) ? i : j;
  }

  // the path between two nodes (list of nodes, including x and y)
  vector<ll> nnpath(ll x, ll y) {
    vector<ll> ret;
    ll c = lca(x, y);
    for ( ; x != c; x = parent(x)) ret.push_back(x);
    ret.push_back(c);
    ll len = (ll)ret.size();
    for ( ; y != c; y = parent(y)) ret.push_back(y);
    reverse(ret.begin() + len, ret.end());
    return ret;
  }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"    
  tuple<ll, ll, ll, ll, ll> diameter() {
    if (numNodes == 1) return {0, 0, 0, 0, 0};
    if (numNodes == 2) return {1, 0, 1, 0, 1};
    depth(root);   // to ensure that _depth is correctly built
    ll nd0 = max_element(_depth.begin(), _depth.end()) - _depth.begin();
    ll nd1 = -1, ct0 = -1, ct1 = -1;
    ll diam = 0;
    auto dfs2 = [&](auto rF, ll nd, ll dp, ll pt) -> bool {
      // DFS from nd0, which is different from the root.
      bool ret = false;
      ll numChildren = 0;
      for (auto [cld, _e] : _nbr[nd].pe) {
        if (cld == pt) continue;
        numChildren++;
        bool bbb = rF(rF, cld, dp + 1, nd);
        ret = ret || bbb;
      }
      if (numChildren > 0) {
        if (ret) {
          if (diam % 2 == 0) {
            if (dp == diam / 2) ct0 = ct1 = nd;
          }else {
            if (dp == diam / 2) ct0 = nd;
            else if (dp == diam / 2 + 1) ct1 = nd;
          }
        }
      }else {
        if (dp > diam) {
          diam = dp;
          nd1 = nd;
          ret = true;
        }
      }
      return ret;
    };
    dfs2(dfs2, nd0, 0, -1);
    return {diam, nd0, nd1, ct0, ct1};
  }
#pragma GCC diagnostic pop

  pair<ll, ll> centroids() {
    auto dfs = [&](auto rF, ll nd) -> pair<ll, ll> {
      for (ll c : children(nd)) {
        ll a = 2 * stsize(c);
        if (a > numNodes) return rF(rF, c);
        if (a == numNodes) return make_pair(nd, c);
      }
      return make_pair(nd, -1);
    };
    return dfs(dfs, root);
  }

  void change_root(ll newRoot) {
    _stsize.clear();
    _depth.clear();
    _edge_idx.clear();
    _euler_in.clear();
    _euler_out.clear();
    _lca_tbl.clear();

    root = newRoot;
    _set_parent();
  }

};

const Tree::pe_t end_object{-1, -1};

template <typename M>
auto reroot(Tree& tree, const M& unit, auto add, auto mod1, auto mod2) {
  using A = decltype(mod2(M(), 0));
  vector<A> result(tree.numNodes);
  vector<vector<M>> sum_left(tree.numNodes);
  vector<vector<M>> sum_right(tree.numNodes);
  
  auto dfs1 = [&](const auto& recF, ll nd) -> A {
    ll k = tree.num_children(nd);
    vector<M> ws(k);
    for (ll i = 0; i < k; i++) {
      ll c = tree.child(nd, i);
      ws[i] = mod1(recF(recF, c), nd, c);
    }
    sum_left[nd].resize(k + 1, unit);
    sum_right[nd].resize(k + 1, unit);
    for (ll i = 0; i < k; i++) sum_left[nd][i + 1] = add(sum_left[nd][i], ws[i]);
    for (ll i = k - 1; i >= 0; i--) sum_right[nd][i] = add(sum_right[nd][i + 1], ws[i]);
    return mod2(sum_right[nd][0], nd);
  };
  dfs1(dfs1, tree.root);

  auto dfs2 = [&](const auto& recF, ll nd, const M& t) -> void {
    result[nd] = mod2(add(sum_right[nd][0], t), nd);
    ll k = tree.num_children(nd);
    for (ll i = 0; i < k; i++) {
      ll c = tree.child(nd, i);
      M excl_c = add(sum_left[nd][i], sum_right[nd][i + 1]);
      M m_for_c = add(excl_c, t);
      A v_for_c = mod2(m_for_c, nd);
      M pass_c = mod1(v_for_c, c, nd);
      recF(recF, c, pass_c);
    }
  };
  dfs2(dfs2, tree.root, unit);
  
  return result;
}

template <typename M>
vector<M> reroot(Tree& tree, const M& unit, auto add, auto mod1) {
  return reroot<M>(tree, unit, add, mod1, [](const M& m, ll i) -> M { return m; });
}

// ---- end tree.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, X) [5YBN0zuF]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [5YBN0zuF]

  Tree tr(N);
  REP(i, 0, N - 1) {
    ll a, b; cin >> a >> b; a--; b--;
    tr.add_edge(a, b);
  }
  
  vector<ll> vec(2*N, 0LL);
  REP(i, 0, 2*N) {
    auto [e, x, y] = tr.euler_edge(i);
    if (y >= 0 and x == tr.parent(y)) vec[i] = X[y] + 1;
  }
  WaveletMatrix wm(vec, -1);

  REP(_q, 0, Q) {
    ll v, k; cin >> v >> k; v--; k--;
    ll i0 = tr.euler_in(v);
    ll i1 = tr.euler_out(v);
    cout << wm.kth_largest(k, i0, i1) - 1 << "\n";
  }

  return 0;
}

