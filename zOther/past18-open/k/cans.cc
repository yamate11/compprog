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

// @@ !! LIM(trie rle cmpNaive debug)

// ---- inserted library file trie.cc

/**
 * @brief Trie木
 *
 * テンプレートパラメタ T には，ユーザデータを格納するデータ型を指定する．
 *   特に使わないときには，仮に，T = ll としておく．
 */

template <typename T = ll>
struct TrieNode {
  /** このノードに対応する文字列が Trie に格納されている数 */
  int _num;
  /** このノード以下に存在する要素の数 */
  int _size;
  /** ユーザデータ */
  T user;
  
  /** コンストラクタ */
  TrieNode(int n = 0, int s = 0, const T& u = T())
    : _num(n), _size(s), user(u) {};
};

template <typename T = ll>
struct Trie {
  /** 最初の文字 */
  char from;
  /** 文字の種類数 */
  int br_size;
  /** ノード．nodes[0] は，空文字列に対応する．*/
  vector<TrieNode<T>> nodes;
  /** 添字 
      若干奇妙ではあるが，第 i 番目のノードに対応する文字列を s とするとき，
      その親ノードの添字を index[i * (br_size + 1)] に格納し，
      j 番目の子供，つまり，s + (char)(from + j) に対応するノードの添字を index[i * (br_size + 1) + (1 + j)]
      に格納している．
      つまり，index は (1 + br_size) ずつのグループになっており，
      各グループには先頭に親の添字を，そのあとは from, (char)(from + 1), ... の添字を格納している．
  */
  vector<int> index;

  /** コンストラクタ */
  Trie(char from_, int br_size_) : from(from_), br_size(br_size_), nodes(1), index(br_size + 1, -1) {}

  int& _parent_index(int idx) { return index[idx * (br_size + 1)]; }
  int& _child_index(int idx, char ch) { return index[idx * (br_size + 1) + 1 + (ch - from)]; }

  /** 親ノードの添字 */
  int parent_index(int idx) { return _parent_index(idx); }

  /** 子ノードの添字．create = true の時には，ノードが存在しなければ作成する */
  int child_index(int idx, char ch, bool create = false) {
    int i = _child_index(idx, ch);
    if (i >= 0) return i;
    if (not create) return -1;
    int new_idx = nodes.size();
    nodes.resize(new_idx + 1);
    index.resize((new_idx + 1) * (br_size + 1), -1);
    _child_index(idx, ch) = new_idx;
    _parent_index(new_idx) = idx;
    return new_idx;
  }

  /** 文字列ノードの添字 (途中から) */
  int prefixed_string_index(int idx, const string& s, bool create = false) {
    int cur = idx;
    for (size_t i = 0; i < s.size(); i++) {
      cur = child_index(cur, s[i], create);
      if (cur < 0) return cur;
    }
    return cur;
  }

  /** 文字列ノードの添字 */
  int string_index(const string& s, bool create = false) { return prefixed_string_index(0, s, create); }

  /** 指定された添字を持つノードの文字列の存在個数 */
  int num(int idx) { return idx < 0 ? 0 : nodes[idx]._num; }

  /** 指定された添字を持つノード以下にある文字列の存在個数 */
  int size(int idx) { return idx < 0 ? 0 : nodes[idx]._size; }

  /** 文字列の存在個数を返す */
  int num_string(const string& s) { return num(string_index(s)); }

  /** 指定された prefix を持つ文字列の存在個数を返す */
  int num_prefix(const string& prefix) { return size(string_index(prefix)); }

  /** 文字列を1個追加する．対応するノードの添字を返す */
  int insert(const string& s) {
    int idx = string_index(s, true);
    nodes[idx]._num++;
    for (int i = idx; i >= 0; i = _parent_index(i)) nodes[i]._size++;
    return idx;
  }
  
  /** 文字列を1個削除する */
  void erase(const string& s) {
    int idx = string_index(s);
    if (idx < 0) throw runtime_error("Trie: tried to erase non-existing node.");
    if (nodes[idx]._num == 0) throw runtime_error("Trie: tried to remove a number from zero.");
    nodes[idx]._num--;
    for (int i = idx; i >= 0; i = _parent_index(i)) nodes[i]._size--;
  }

  /** 指定された添字のノードの文字列を返す．低効率デバッグ用 */
  string node_to_str(int idx) {
    string ret;
    while (idx > 0) {
      int p = _parent_index(idx);
      char ch = from;
      for (; child_index(p, ch) != idx; ch++);
      ret.push_back(ch);
      idx = p;
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }

  vector<string> _sub_string_set(int idx, const string& prefix) {
    vector<string> ret;
    for (int k = 0; k < num(idx); k++) ret.push_back(prefix);
    for (int i = 0; i < br_size; i++) {
      int j = _child_index(idx, from + i);
      if (j < 0) continue;
      auto vv = _sub_string_set(j, prefix + (char)(from + i));
      copy(vv.begin(), vv.end(), back_inserter(ret));
    }
    return ret;
  }

  /** 格納されている文字列のリスト (vector<string>) を返す．デバッグ用 */
  vector<string> string_set() {
    return _sub_string_set(0, "");
  }

};

template <typename T = ll>
Trie<T> create_trie(char from_, char to_) {
  Trie t(from_, to_ - from_ + 1);
  return t;
}

template <typename T = ll>
ostream& operator<<(ostream& ostr, Trie<T> trie) {
  ostr << trie.string_set();
  return ostr;
}

/* Poorman's Binary Trie */

string ull2binstr(unsigned long long x, int len = 64) {
  string ret(len, ' ');
  for (int i = 0; i < len; i++) ret[i] = (x >> (len - 1 - i) & 1) ? '1' : '0';
  return ret;
}

unsigned long long binstr2ull(string s) {
  unsigned long long ret = 0;
  for (char c : s) ret = 2 * ret + (c - '0');
  return ret;
}


// ---- end trie.cc

// ---- inserted library file rle.cc

template<class InputIt, class OutputIt>
OutputIt rle_iter(InputIt first, InputIt last, OutputIt d_first) {
  InputIt itA = first;
  OutputIt oit = d_first;
  while (itA != last) {
    InputIt itB = next(itA);
    for (; itB != last and *itA == *itB; itB++);
    *oit = make_pair(*itA, itB - itA);
    itA = itB;
    oit++;
  }
  return oit;
}

template<class V>
auto rle(V vec) {
  vector<pair<typename V::value_type, ll>> ret;
  rle_iter(vec.begin(), vec.end(), back_inserter(ret));
  return ret;
}

// ---- end rle.cc

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
  // @InpVec(N, A, type=u64) [0P5sZdnA]
  auto A = vector(N, u64());
  for (int i = 0; i < N; i++) { u64 v; cin >> v; A[i] = v; }
  // @End [0P5sZdnA]

  ll ans = 0;
  REP(i, 0, N) REP(j, i + 1, N) {
    u64 x = A[i] + A[j];
    ans += countr_zero(x);
  }
  cout << ans << endl;

  return 0;
}
int body(istream& cin, ostream& cout) {

  ll N; cin >> N;
  // @InpVec(N, A, type=u64) [0P5sZdnA]
  auto A = vector(N, u64());
  for (int i = 0; i < N; i++) { u64 v; cin >> v; A[i] = v; }
  // @End [0P5sZdnA]
  
  vector<vector<ll>> vec(33);
  REP(i, 0, N) {
    ll c = countr_zero(A[i]);
    vec[c].push_back(A[i]);
  }
  ll ans = 0;
  REP(i, 0, 33) REP(j, i + 1, 33) {
    ans += ssize(vec[i]) * ssize(vec[j]) * i;
  }
  REP(k, 0, 33) {
    Trie t = create_trie('0', '1');
    ll z = ssize(vec[k]);
    ll val = (k + 1) * z * (z - 1) / 2;
    for (u64 a : vec[k]) {
      a >>= (k + 1);
      string s{};
      REP(j, 0, 32 - k) {
        s += (char)('0' + a % 2);
        a /= 2;
      }
      DLOGK(s);
      t.insert(s);
    }
    DLOGK(val);
    auto func = [&](auto rF, ll idx_0, ll idx_1) -> void {
      if (idx_0 < 0 or idx_1 < 0) return;
      DLOGK(t.node_to_str(idx_0), t.node_to_str(idx_1), t.size(idx_0), t.size(idx_1));
      val += t.size(idx_0) * t.size(idx_1);
      rF(rF, t.child_index(idx_0, '0'), t.child_index(idx_1, '1'));
      rF(rF, t.child_index(idx_0, '1'), t.child_index(idx_1, '0'));
    };
    func(func, t.child_index(0, '0'), t.child_index(0, '1'));
    ans += val;
  }
  cout << ans << endl;

  return 0;
}

