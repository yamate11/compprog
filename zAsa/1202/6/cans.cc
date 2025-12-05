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

// @@ !! LIM(tree doubling)

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

  template<bool get_peer, bool excl_parent>
  struct nbr_iterator {
    const nbr_t& body;
    ll pe_idx;
    explicit nbr_iterator(const nbr_t& body_, ll pe_idx_) : body(body_), pe_idx(pe_idx_) {
      if constexpr (excl_parent) {
        if (pe_idx == body.parent_idx) pe_idx++;
      }
    }
    auto operator*() const -> typename conditional<get_peer, ll, const pe_t&>::type {
      if constexpr (get_peer) return body.pe[pe_idx].peer;
      else                    return body.pe[pe_idx];
    }
    const nbr_iterator& operator++() {
      pe_idx++;
      if constexpr (excl_parent) {
        if (pe_idx == body.parent_idx) pe_idx++;
      }
      return *this;
    }
    bool operator !=(const nbr_iterator& o) const { return pe_idx != o.pe_idx; }
  };

  template<bool get_peer, bool excl_parent = true>
  struct children_view {
    const nbr_t& body;
    children_view(const nbr_t& body_) : body(body_) {}
    nbr_iterator<get_peer, excl_parent> begin() const { return nbr_iterator<get_peer, excl_parent>(body, 0); }
    nbr_iterator<get_peer, excl_parent> end() { return nbr_iterator<get_peer, excl_parent>(body, std::ssize(body.pe));  }
  };

  ll numNodes;
  ll root;
  vector<nbr_t> _nbr;
  vector<pair<ll, ll>> _edges;   // (x, y) in _edges => x < y
  vector<ll> _stsize;
  vector<ll> _depth;
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
        _euler_edge[euler_idx] = {edge, 0};
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
        _euler_edge[euler_idx] = {edge, 1};
        _euler_out[nd] = euler_idx;
        euler_idx++;
      }
    };

    dfs(dfs, root, -1, numNodes - 1);
  }

  pe_t parent_pe(ll nd) { return nd == root ? pe_t(-1, -1) : _nbr[nd].pe[_nbr[nd].parent_idx]; }
  ll parent(ll nd) { return nd == root ? -1 : parent_pe(nd).peer; }
  ll num_children(ll nd) { return _nbr[nd].pe.size() - (_nbr[nd].parent_idx == (ll)_nbr[nd].pe.size() ? 0 : 1); }
  pe_t child_pe(ll nd, ll idx) { return _nbr[nd].pe[idx < _nbr[nd].parent_idx ? idx : idx + 1]; }
  ll child(ll nd, ll idx) { return child_pe(nd, idx).peer; }
  ll child_edge(ll nd, ll idx) { return child_pe(nd, idx).edge; }
  auto children_pe(ll nd) { return children_view<false>(_nbr[nd]); }
  auto children(ll nd) { return children_view<true>(_nbr[nd]); }
  auto neighbor_pe(ll nd) { return children_view<false, false>(_nbr[nd]); }
  auto neighbor(ll nd) { return children_view<true, false>(_nbr[nd]); }

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
    auto [py, ey] = parent_pe(y);
    if (x == py) return ey;
    auto [px, ex] = parent_pe(x);
    if (y == px) return ex;
    return -1LL;
  }

  pair<ll, ll> nodes_of_edge(ll e, ll mode = 0) {
    if (mode == -1) {
      return _edges[e];
    }else {
      const auto& [x, y] = _edges[e];
      if ((x == parent(y)) == (mode == 0)) return {x, y};
      else return {y, x};
    }
  }

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
        auto [x, y] = nodes_of_edge(e, b);
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

// ---- inserted library file doubling.cc

template<typename T = void, typename Add = void>
struct Doubling {
  static constexpr bool HAS_T = not is_void_v<T>;
  using Node = conditional_t<HAS_T, pair<int, T>, int>;

  int n{};
  vector<vector<Node>> tbl;
  [[no_unique_address]] conditional_t<HAS_T, T, monostate> unit{};
  [[no_unique_address]] conditional_t<HAS_T, Add, monostate> add{};

  int& nd_int(Node& nd) { if constexpr (HAS_T) return nd.first; else return nd; }

  void prepare_tbl(u64 lim, const auto& nxt) {
    int K = 64 - countl_zero(lim);
    tbl.resize(K, vector<Node>(n));
    for (int i = 0; i < n; i++) nd_int(tbl[0][i]) = nxt[i];
  }

  void fill_tbl(u64 lim) {
    for (int k = 0; k + 1 < ssize(tbl); k++) {
      for (int i = 0; i < n; i++) {
        nd_int(tbl[k + 1][i]) = nd_int(tbl[k][nd_int(tbl[k][i])]);
        if constexpr (HAS_T) tbl[k + 1][i].second = add(tbl[k][i].second, tbl[k][tbl[k][i].first].second);
      }
    }
  }

  Doubling() {}

  Doubling(ll lim, int n_, const auto& nxt) requires (not HAS_T) : n(n_) {
    prepare_tbl(lim, nxt);
    fill_tbl(lim);
  }

  template<typename U = T, typename A = Add> requires (HAS_T)
  Doubling(ll lim, int n_, const auto& nxt, const auto& mapping, U unit_, A add_)
    : n(n_), unit(unit_), add(add_) {
    prepare_tbl(lim, nxt);
    for (int i = 0; i < n; i++) tbl[0][i].second = mapping[i];
    fill_tbl(lim);
  }

  Node val(ll x, int i) {
    Node ret;
    nd_int(ret) = i;
    if constexpr (HAS_T) ret.second = unit;
    for (int k = 0; x > 0; x >>= 1, k++) {
      if (x & 1) {
        Node cur = tbl[k][nd_int(ret)];
        nd_int(ret) = nd_int(cur);
        if constexpr (HAS_T) ret.second = add(ret.second, cur.second);
      }
    }
    return ret;
  }

};

template<typename T, typename Add>
auto make_doubling_with_monoid_unit_add(ll lim, int n, const auto& nxt, const auto& mapping, T unit, Add add) {
  return Doubling<T, decltype(add)>(lim, n, nxt, mapping, unit, add);
}
template<typename T>
auto make_doubling_with_monoid(ll lim, int n, const auto& nxt, const auto& mapping) {
  return make_doubling_with_monoid_unit_add(lim, n, nxt, mapping, T(), plus<T>());
}



/*
struct DoublingFRel { // from functional relation
  int n;
  vector<vector<int>> tbl;

  void _init(ll lim, auto frel) {
    int K = 64 - countl_zero((u64)lim);
    tbl.resize(K, vector<int>(n));
    for (int i = 0; i < n; i++) tbl[0][i] = frel(i);
    for (int k = 0; k + 1 < K; k++) for (int i = 0; i < n; i++) tbl[k + 1][i] = tbl[k][tbl[k][i]];
  }

  DoublingFRel(ll lim, int n_, auto frel) : n(n_) { _init(lim, frel); }
  static DoublingFRel from_container(ll lim, int n, auto vec) {
    return DoublingFRel(lim, n, [&](int i) { return vec[i]; });
  }

  int val(ll x, int i) { // Calculates frel^{(x)}(i).  Should be x <= lim.
    for (int k = 0; x > 0; x >>= 1, k++) if (x & 1) i = tbl[k][i];
    return i;
  }
};
  
template <typename T, typename add_t>
struct DoublingCum {
  const DoublingFRel& d;
  T unit;
  add_t add;
  vector<vector<T>> tbl;

  void _init(auto mapping) {
    int K = d.tbl.size();
    tbl.resize(K, vector<T>(d.n));
    for (int i = 0; i < d.n; i++) tbl[0][i] = mapping(i);
    for (int k = 0; k + 1 < K; k++) for (int i = 0; i < d.n; i++) tbl[k + 1][i] = add(tbl[k][i], tbl[k][d.tbl[k][i]]);
  }

  DoublingCum(const DoublingFRel& d_, auto mapping, T unit_, add_t add_)
    : d(d_), unit(unit_), add(add_) { _init(mapping); }

  T val(ll x, int i) { // the monoid sum of x objs from i.  i.e. from i to i + x - 1.
    T ret = unit;
    for (int k = 0; x > 0; x >>= 1, k++) if (x & 1) {
        ret = add(ret, tbl[k][i]);
        i = d.tbl[k][i];
      }
    return ret;
  }
};

DoublingFRel doubling_from_func(ll lim, int n, auto func) { return DoublingFRel(lim, n, func); }
DoublingFRel doubling_from_container(ll lim, int n, auto vec) {
  return DoublingFRel(lim, n, [&vec](int i) { return vec[i]; });
}
template<typename T, typename add_t = std::plus<T>>
auto doubling_cum_from_func(const DoublingFRel& d, auto mapping, T unit = T(), add_t add = plus<T>()) {
  return DoublingCum<T, decltype(add)>(d, mapping, unit, add);
}
template<typename T, typename add_t = std::plus<T>>
auto doubling_cum_from_container(const DoublingFRel& d, auto vec_mapping, T unit = T(), add_t add = plus<T>()) {
  return DoublingCum<T, decltype(add)>(d, [&vec_mapping](int i) { return vec_mapping[i]; }, unit, add);
}
*/

// ---- end doubling.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  Tree tr(N);
  REP(i, 0, N - 1) {
    ll a, b; cin >> a >> b; a--; b--;
    tr.add_edge(a, b);
  }
  auto [diam, nd0, nd1, ct0, ct1] = tr.diameter();
  tr.change_root(ct0);
  auto mkpath = [&](ll nd) {
    vector<ll> ret{nd};
    while (nd != ct0) {
      nd = tr.parent(nd);
      ret.push_back(nd);
    }
    ranges::reverse(ret);
    return ret;
  };
  auto p0 = mkpath(nd0);
  auto p1 = mkpath(nd1);
  
  vector<ll> myparent(N);
  REP(i, 0, N) myparent[i] = tr.parent(i);
  myparent[ct0] = ct0;
  Doubling dobj(N, N, myparent);

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll u, k; cin >> u >> k; u--;
    auto f = [&](const auto& vec, ll d) -> ll {
      if (d >= ssize(vec)) return -1;
      else return vec[d];
    };
    auto getans = [&]() -> ll {
      if (N == 2) {
        if (k == 1) return 1 - u;
        else return -1;
      }
      ll dep = tr.depth(u);
      if (k <= dep) return dobj.val(k, u);
      ll z = dobj.val(dep - 1, u);
      if (z == p1[1]) return f(p0, k - dep);
      else            return f(p1, k - dep);
    };
    ll ans = getans();
    cout << (ans >= 0 ? ans + 1 : -1) << "\n";
  }

  return 0;
}

