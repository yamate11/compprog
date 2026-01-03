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

// @@ !! LIM(tree cmpNaive debug)

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

// ---- inserted library file cmpNaive.cc

const string end_mark("^__=end=__^");

int naive(istream& cin, ostream& cout);
int body(istream& cin, ostream& cout);

void cmpNaive() {
  while (true) {
    string s;
    getline(cin, s);
    bool run_body;
    if (s.at(0) == 'Q') {
      return;
    }else if (s.at(0) == 'B') {
      run_body = true;
    }else if (s.at(0) == 'N') {
      run_body = false;
    }else {
      cerr << "Unknown body/naive specifier.\n";
      exit(1);
    }
    string input_s;
    while (true) {
      getline(cin, s);
      if (s == end_mark) break;
      input_s += s;
      input_s += "\n";
    }
    stringstream ss_in(move(input_s));
    stringstream ss_out;
    ss_out << setprecision(20);
    if (run_body) {
      body(ss_in, ss_out);
    }else {
      naive(ss_in, ss_out);
    }
    cout << ss_out.str() << end_mark << endl;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if CMPNAIVE
  if (argc == 2) {
    if (strcmp(argv[1], "cmpNaive") == 0) {
      cmpNaive();
    }else if (strcmp(argv[1], "naive") == 0) {
      naive(cin, cout);
    }else if (strcmp(argv[1], "skip") == 0) {
      exit(0);
    }else {
      cerr << "Unknown argument.\n";
      exit(1);
    }
  }else {
#endif
    body(cin, cout);
#if CMPNAIVE
  }
#endif
  return 0;
}

/*
int naive(istream& cin, ostream& cout) {
  return 0;
}
int body(istream& cin, ostream& cout) {
  return 0;
}
*/

// ---- end cmpNaive.cc

// ---- inserted function f:<< from util.cc

// declarations

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p);

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t);

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t);

template <typename T1, typename T2, typename T3, typename T4, typename T5>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5>& t);

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t);

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

template <typename T, size_t N>
ostream& operator<< (ostream& os, const array<T, N>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig);

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig);

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st);

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t);
#endif

ostream& operator<< (ostream& os, int8_t x);

ostream& operator<< (ostream& os, const __int128& x);

// definitions

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ", " << get<4>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ", " << get<4>(t) << ", " << get<5>(t) << ")";
  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
  os << '[';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << ']';

  return os;
}

template <typename T, size_t N>
ostream& operator<< (ostream& os, const array<T, N>& v) {
  os << '[';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << ']';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig) {
  queue<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig) {
  deque<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop_front();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig) {
  priority_queue<T, T2, T3> pq(orig);
  bool first = true;
  os << '[';
  while (!pq.empty()) {
    T x = pq.top(); pq.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st) {
  stack<T> tmp(st);
  os << '[';
  bool first = true;
  while (!tmp.empty()) {
    T& t = tmp.top();
    if (first) first = false;
    else os << ", ";
    os << t;
    tmp.pop();
  }
  os << ']';
  return os;
}

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t) {
  if (t.has_value()) os << "v(" << t.value() << ")";
  else               os << "nullopt";
  return os;
}
#endif

ostream& operator<< (ostream& os, int8_t x) {
  os << (int32_t)x;
  return os;
}

// for Enum type; just displays ordinals.
template <typename E>
typename std::enable_if<std::is_enum<E>::value, std::ostream&>::type
operator<<(std::ostream& os, E e) {
    return os << static_cast<typename std::underlying_type<E>::type>(e);
}

// This is a very ad-hoc implementation...
// Known problem: "1 << 127" cannot be handled.
ostream& operator<<(ostream& os, const __int128& v) {
  unsigned __int128 a = v < 0 ? -v : v;
  ll i = 0;
  string s(64, ' ');
  if (v == 0) {
    s[i++] = '0';
  }else {
    while (a > 0) {
      s[i++] = '0' + (char)(a % 10);
      a /= 10;
    }
  }
  if (v < 0) {
    s[i++] = '-';
  }
  s.erase(s.begin() + i, s.end());
  reverse(s.begin(), s.end());
  os << s;
  return os;
}


// ---- end f:<<

// ---- inserted library file debug.cc
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(bool with_nl, Head&& head) {
  cerr << head;
  if (with_nl) cerr << endl;
}

template <class Head, class... Tail>
void dbgLog(bool with_nl, Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(with_nl, forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DLOGNNL(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

/*
#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL_LIB(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif
*/

#define DUP1(E1)       #E1 "=", E1
#define DUP2(E1,E2)    DUP1(E1), DUP1(E2)
#define DUP3(E1,...)   DUP1(E1), DUP2(__VA_ARGS__)
#define DUP4(E1,...)   DUP1(E1), DUP3(__VA_ARGS__)
#define DUP5(E1,...)   DUP1(E1), DUP4(__VA_ARGS__)
#define DUP6(E1,...)   DUP1(E1), DUP5(__VA_ARGS__)
#define DUP7(E1,...)   DUP1(E1), DUP6(__VA_ARGS__)
#define DUP8(E1,...)   DUP1(E1), DUP7(__VA_ARGS__)
#define DUP9(E1,...)   DUP1(E1), DUP8(__VA_ARGS__)
#define DUP10(E1,...)   DUP1(E1), DUP9(__VA_ARGS__)
#define DUP11(E1,...)   DUP1(E1), DUP10(__VA_ARGS__)
#define DUP12(E1,...)   DUP1(E1), DUP11(__VA_ARGS__)
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,NAME,...) NAME
#define DUP(...)          GET_MACRO(__VA_ARGS__, DUP12, DUP11, DUP10, DUP9, DUP8, DUP7, DUP6, DUP5, DUP4, DUP3, DUP2, DUP1)(__VA_ARGS__)
#define DLOGK(...)        DLOG(DUP(__VA_ARGS__))
#define DLOGKL(lab, ...)  DLOG(lab, DUP(__VA_ARGS__))

#if DEBUG_LIB
  #define DLOG_LIB   DLOG
  #define DLOGK_LIB  DLOGK
  #define DLOGKL_LIB DLOGKL
#endif

// ---- end debug.cc

// @@ !! LIM -- end mark --

int naive(istream& cin, ostream& cout) {
  ll N; cin >> N;

  Tree tr(N);
  REP(i, 0, N - 1) {
    ll u, v; cin >> u >> v;
    tr.add_edge(u, v);
  }
  
  auto mex = [&](const auto& v) -> ll {
    vector w(N + 1, true);
    for (ll x : v) w[x] = false;
    REP(i, 0, N + 1) if (w[i]) return i;
    assert(0);
  };

  ll ans = 0;
  REP(x, 0, N) REP(y, x, N) {
    auto v = tr.nnpath(x, y);
    ans += mex(v);
  }
  cout << ans << endl;

  return 0;
}
int body(istream& cin, ostream& cout) {
  ll N; cin >> N;

  Tree tr(N);
  REP(i, 0, N - 1) {
    ll u, v; cin >> u >> v;
    tr.add_edge(u, v);
  }
  ll ans = 0;
  ll cur = N * (N + 1) / 2;
  for (ll c0 : tr.children(0)) cur -= tr.stsize(c0) * (tr.stsize(c0) + 1) / 2;
  ans += cur;
  DLOGKL("ans1", ans);
  ll d0 = 0;
  vector onPath(N, false);
  onPath[0] = true;
  auto f = [&](ll nd0) -> pll {
    assert(not onPath[nd0]);
    ll nd = nd0;
    while (true) {
      onPath[nd] = true;
      ll prev = nd;
      nd = tr.parent(nd);
      if (onPath[nd]) return {nd, prev};
    }
  };
  auto [_dummy, y] = f(1);
  ll n0 = N - tr.stsize(y);
  ll d1 = 1;
  ll n1 = tr.stsize(1);
  ans += n0 * n1;
  DLOGKL("ans2", ans, n0, n1);
  for (ll lev = 2; lev < N; lev++) {
    DLOGK(lev, onPath);
    if (not onPath[lev]) {
      auto [z, _dum] = f(lev);
      if (z == d0) {
        n0 = tr.stsize(lev);
        d0 = lev;
      }else if (z == d1) {
        n1 = tr.stsize(lev);
        d1 = lev;
      }else break;
    }
    ans += n0 * n1;
    DLOGK(lev, ans, n0, n1);
  }
  cout << ans << endl;
  return 0;
}

