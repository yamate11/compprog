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

constexpr int TRIE_SET_MULTI = 0;
constexpr int TRIE_SET_SINGLE = 1;
constexpr int TRIE_SET_NONE = 2;

template <int bt_size, char from, int set_mode = TRIE_SET_MULTI, typename User = monostate,
          typename S = string, bool compact = (8 <= bt_size and bt_size <= 63), bool has_offset = true>
struct Trie {

  template <typename RetType>
  static consteval RetType make_default_intval(int x) {
    if constexpr (is_same_v<RetType, int>) return x;
    else return {};
  }

  Trie* parent = nullptr;

  using c_pat_t = conditional_t<compact, unsigned long long, monostate>;
  [[no_unique_address]] c_pat_t c_pat{};

  using cpt_children_t = conditional_t<compact, vector<Trie*>, monostate>;
  [[no_unique_address]] cpt_children_t cpt_children{};

  using children_t = conditional_t<compact, monostate, array<Trie*, bt_size>>;
  [[no_unique_address]] children_t children{};

  using offset_t = conditional_t<has_offset, int, monostate>;
  [[no_unique_address]] offset_t offset = make_default_intval<offset_t>(-1);

  using reside_t = conditional_t<set_mode == TRIE_SET_NONE, monostate, int>;
  [[no_unique_address]] reside_t reside = make_default_intval<reside_t>(0);

  using size_st_t = conditional_t<set_mode == TRIE_SET_NONE, monostate, int>;
  [[no_unique_address]] size_st_t size_st = make_default_intval<size_st_t>(0);

  [[no_unique_address]] User user{};

  /*
    Note on the default value of compact: When `compact' = true, the size of Trie increases 4 bytes per bt_size,
    as the type of `children' is array<Trie*, bt_size>.  When `compact' = false, the size of Trie itself
    does not depend on the value of bt_size, but the memory consumption increases when a string is added,
    as the type of `cpt_children` is vector<Trie*>.  The size of Trie with (compact=true, bt_size=4) is
    the same as that with (compact=False).  (Warning: if you use -D_GLIBCXX_DEBUG, the results may be
    different.)  Thus, when bt_size <= 4, `comapct' should definitely be false.
  */

  Trie() = default;
  Trie(Trie* p, int offset_) : parent(p) {
    if constexpr (has_offset) offset = offset_;
  }

  Trie* get_child_offset(int d) const {
    if constexpr(compact) {
      static_assert(bt_size <= 63);
      ll idx = popcount(c_pat & ((1ULL << d) - 1));
      return (c_pat >> d & 1) ? cpt_children[idx] : nullptr;
    }else {
      Trie* p = children[d];
      return p ? p : nullptr;
    }
  }
  Trie* get_child_val(int c) const { return get_child_offset(c - from); }

  Trie* get_or_create_child_offset(int d) {
    if (Trie* p0 = get_child_offset(d); p0) return p0;
    Trie* p = new Trie(this, d);
    if constexpr(compact) {
      ll idx = popcount(c_pat & ((1ULL << d) - 1));
      cpt_children.insert(cpt_children.begin() + idx, p);
      c_pat |= 1ULL << d;
    }else {
      children[d] = p;
    }
    return p;
  }
  Trie* get_or_create_child_val(int c) { return get_or_create_child_offset(c - from); }

  /*
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
  */

  Trie* get_or_create_node(const auto& s) {
    Trie* tr = this;
    for (auto c : s) tr = tr->get_or_create_child_val(c);
    return tr;
  }
  Trie* get_or_create_node(const char* s) { return get_or_create_node(string_view(s)); }

  Trie* get_node(const auto& s) const {
    Trie* tr = const_cast<Trie*>(this);
    for (auto c : s) {
      tr = tr->get_child_val(c);
      if (not tr) return nullptr;
    }
    return tr;
  }
  Trie* get_node(const char* s) const { return get_node(string_view(s)); }

  Trie* search(const auto& s) const {
    Trie* p = get_node(s);
    if (p and p->reside == 0) p = nullptr;
    return p;
  }
  Trie* search(const char* s) const { return search(string_view(s)); }

  Trie* insert(const auto& s) {
    Trie* tr = get_or_create_node(s);
    if constexpr (set_mode == TRIE_SET_SINGLE) {
      if (tr->reside == 0) {
        tr->reside = 1;
        for (Trie* p = tr; p; p = p->parent) p->size_st++;
      }
    }else if constexpr (set_mode == TRIE_SET_MULTI) {
      tr->reside++;
      for (Trie* p = tr; p; p = p->parent) p->size_st++;
    }
    return tr;
  }
  Trie* insert(const char* s) { return insert(string_view(s)); }

  void erase() {
    if constexpr (set_mode == TRIE_SET_SINGLE or set_mode == TRIE_SET_MULTI) {
      if (reside > 0) {
        for (Trie* tr = this; tr; tr = tr->parent) tr->size_st--;
        reside--;
      }
    }
  }
  void erase(const auto& s) {
    Trie* p = search(s);
    if (p) p->erase();
  }
  void erase(const char* s) { erase(string_view(s)); }

  int get_offset() const {
    if constexpr (has_offset) return offset;
    else {
      Trie* p = parent;
      if (not p) return -1;
      for (int d = 0; d < bt_size; d++) if (p->get_child_offset(d) == this) return d;
      assert(0);
    }
  }

  S repr() const {
    S ret;
    for (const Trie* tr = this; true; tr = tr->parent) {
      ll d = tr->get_offset();
      if (d < 0) break;
      ret.push_back(from + tr->get_offset());
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }

  void _elem_list_sub(auto& vec) const {
    for (int i = 0; i < reside; i++) vec.push_back(repr());
    for (int i = 0; i < bt_size; i++) if (Trie* p = get_child_offset(i); p) p->_elem_list_sub(vec);
  }

  vector<S> elem_list() const {
    vector<S> ret;
    _elem_list_sub(ret);
    return ret;
  }

  using show_elem_tp = conditional_t<is_same_v<User, monostate>, tuple<S, int, int>, tuple<S, int, int, int, User>>;
  using show_tp = vector<show_elem_tp>;

  void _show_sub_add(string& s) const {
    s += "(" + repr() + ", " + to_string(reside) + ", " + to_string(size_st);
    if constexpr (not (is_same_v<User, monostate>)) s += ", " + g_show(user);
    s += "),\n  ";
  }

  void _show_sub(string& s, bool elemonly) const {
    auto add = [&]() -> void {
      s += "(" + repr();
      if constexpr (set_mode == TRIE_SET_SINGLE or set_mode == TRIE_SET_MULTI) {
        s += ", " + to_string(reside) + ", " + to_string(size_st);
      }
      if constexpr (not (is_same_v<User, monostate>)) s += ", " + g_show(user);
      s += "),\n  ";
    };

    if constexpr (set_mode == TRIE_SET_SINGLE or set_mode == TRIE_SET_MULTI) {
      if (reside > 0 or not elemonly) add();
    }else add();
    for (int i = 0; i < bt_size; i++) if (Trie* p = get_child_offset(i); p) p->_show_sub(s, elemonly);
  }

  string show(bool elemonly = true) const {
    string ret = "[ ";
    _show_sub(ret, elemonly);
    ret.pop_back(); ret.pop_back(); ret.pop_back(); ret.pop_back();
    ret += "]";
    return ret;
  }


};


// ---- end trie.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, K; cin >> N >> M >> K;
  string T; cin >> T;
  vector S(N, string(K, ' '));
  REP(i, 0, N) {
    string s; cin >> s;
    REP(j, 0, K) {
      if (s[j] == T[j]) S[i][j] = '1';
      else              S[i][j] = '0';
    }
  }
  using MyTrie = Trie<2, '0', TRIE_SET_MULTI>;
  MyTrie* root = new MyTrie;
  REP(i, 0, N) root->insert(S[i]);

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll i, j; cin >> i >> j; i--; j--;
    root->erase(S[i]);
    if (S[i][j] == '0') S[i][j] = '1';
    else                S[i][j] = '0';
    auto p = root->insert(S[i]);
    ll cnt = 0;
    ll numOK = 0;
    REPrev(k, K - 1, 0) {
      ll m = p->size_st;
      p = p->parent;
      if (S[i][k] == '1') {
        numOK++;
        cnt += p->size_st - m;
      }
    }
    if (numOK > 0 and cnt >= N - M) cout << "Yes\n";
    else cout << "No\n";
  }


  return 0;
}

