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

// @@ !! LIM(trie)

// ---- inserted library file trie.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/trie.cc

template <int bt_size, char from, typename User = monostate,
  typename S = string, bool compact = 2 < bt_size, bool has_offset = true>
struct Trie {

  Trie* parent = nullptr;

  using c_pat_t = conditional_t<compact, unsigned long long, monostate>;
  [[no_unique_address]] c_pat_t c_pat{};

  using cpt_children_t = conditional_t<compact, vector<Trie*>, monostate>;
  [[no_unique_address]] cpt_children_t cpt_children{};

  using children_t = conditional_t<compact, monostate, array<Trie*, bt_size>>;
  [[no_unique_address]] children_t children{};

  using offset_t = conditional_t<has_offset, int, monostate>;
  static consteval offset_t make_default_offset() {
    if constexpr (is_same_v<offset_t, int>) return -1;
    else return {};
  }
  [[no_unique_address]] offset_t offset = make_default_offset();

  bool reside = false;

  int size_st = 0;

  [[no_unique_address]] User user{};

  Trie() = default;
  Trie(Trie* p, int offset_) : parent(p) {
    if constexpr (has_offset) offset = offset_;
  }

  Trie* get_child_val(int c, bool create = false) { return get_child_offset(c - from, create); }

  Trie* get_child_offset(int d, bool create = false) {
    if constexpr(compact) {
      ll idx = popcount(c_pat & ((1ULL << d) - 1));
      if (c_pat >> d & 1) return cpt_children[idx];
      if (not create) return nullptr;
      Trie* p = new Trie(this, d);
      cpt_children.insert(cpt_children.begin() + idx, p);
      c_pat |= 1ULL << d;
      return p;
    }else {
      Trie* p = children[d];
      if (p) return p;
      if (not create) return nullptr;
      p = children[d] = new Trie(this, d);
      return p;
    }
  }

  struct children_iterator {
    Trie* node;
    int idx;
    int offset;
    explicit children_iterator(Trie* node_, int idx_, int offset_) : node(node_), idx(idx_), offset(offset_) {
      _next_effective_child();
    }
    pair<Trie*, char> operator*() const {
      Trie* p;
      if constexpr (compact) p = node->cpt_children[idx];
      else                   p = node->children[idx];
      return make_pair(p, from + offset);
    }
    void _next_effective_child() {
      if constexpr (compact) {
        if constexpr (has_offset) {
          if (idx < ssize(node->cpt_children)) offset = node->cpt_children[idx]->offset;
          else offset = bt_size;
        }else {
          while (offset < bt_size and not (node->c_pat >> offset & 1)) offset++;
        }
      }else {
        while (idx < bt_size and not node->children[idx]) idx++;
        offset = idx;
      }
    }
    const children_iterator& operator++() {
      idx++;
      offset++;
      _next_effective_child();
      return *this;
    }
    bool operator !=(const children_iterator& o) const { return node != o.node or offset != o.offset; }
  };

  struct children_view {
    Trie* node;
    children_view(Trie* node_) : node(node_) {}
    children_iterator begin() const { return children_iterator(node, 0, 0); }
    children_iterator end() const { return children_iterator(node, bt_size, bt_size); }
  };

  auto children_w_val() { return children_view(this); }

  Trie* get_node(const auto& s, bool create = false) {
    Trie* tr = this;
    for (auto c : s) {
      auto cld = tr->get_child_val(c, create);
      if (not cld) return nullptr;
      tr = cld;
    }
    return tr;
  }
  Trie* get_node(const char* s, bool create = false) { return get_node(string(s), create); }

  Trie* search(const auto& s) {
    Trie* p = get_node(s);
    if (p and not p->reside) p = nullptr;
    return p;
  }
  Trie* search(const char* s) { return search(string(s)); }

  Trie* insert(const auto& s) {
    Trie* tr = get_node(s, true);
    if (not tr->reside) {
      tr->reside = true;
      for (Trie* p = tr; p; p = p->parent) p->size_st++;
    }
    return tr;
  }
  Trie* insert(const char* s) { return insert(string(s)); }

  void erase() {
    if (reside) for (Trie* tr = this; tr; tr = tr->parent) tr->size_st--;
    reside = false;
  }

  int get_offset() {
    if constexpr (has_offset) return offset;
    else {
      Trie* p = parent;
      if (not p) return -1;
      for (int d = 0; d < bt_size; d++) if (p->get_child_offset(d) == this) return d;
      assert(0);
    }
  }

  S repr() {
    S ret;
    for (Trie* tr = this; true; tr = tr->parent) {
      ll d = tr->get_offset();
      if (d < 0) break;
      ret.push_back(from + tr->get_offset());
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }

  void _show_sub(auto& vec) {
    if (reside) vec.push_back(repr());
    for (int i = 0; i < bt_size; i++) {
      Trie* p = get_child_offset(i);
      if (p) p->_show_sub(vec);
    }
  }

  vector<S> show() {
    vector<S> ret;
    _show_sub(ret);
    return ret;
  }


};


// ---- end trie.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, S, type=string) [AVT50Idi]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [AVT50Idi]

  auto root = new Trie<26, 'a'>();
  vector<decltype(root)> P(N);
  REP(i, 0, N) {
    auto p = root->search(S[i]);
    if (p) {
      cout << -1 << endl;
      return 0;
    }
    P[i] = root->insert(S[i]);
  }
  
  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }

  ll ans = 0;
  REP(i, 0, N) {
    if (P[i]->size_st != 1) {
      cout << -1 << endl;
      return 0;
    }
    auto p = P[i];
    ll d = ssize(S[i]);
    while (true) {
      p = p->parent;
      d--;
      if (p->size_st != 1) {
        ans += d + 1;
        break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}

