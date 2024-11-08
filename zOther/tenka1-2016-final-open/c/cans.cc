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

// @@ !! LIM(trie f:updMaxMin debug)

// ---- inserted library file trie.cc

/**
 * @brief Trie木
 *
 * テンプレートパラメタ T には，ユーザデータを格納するデータ型を指定する．
 *   特に使わないときには，仮に，T = ll としておく．
 */

template <typename T = ll>
struct Trie {
  struct Info {
    /** 最初の文字 */
    char from;
    /** 文字の種類数 */
    int br_size;
    /** ノード */
    Trie* root;

    /** コンストラクタ */
    Info(char from_, int br_size_) : from(from_), br_size(br_size_), root(nullptr) {}

  };

  /** Trie 全体の情報 */
  Info* info;
  /** 1文字増えたノードを格納するベクトル．サイズは Trie の br_size */
  vector<Trie*> children;
  /** 1文字減ったノード．ルートでは nullptr が設定されている */
  Trie* parent;
  /** このノードに対応する文字列が Trie に格納されている数 */
  ll num;
  /** このノード以下に存在する要素の数 */
  ll size;
  /** このノードの深さ */
  int depth;
  /** このノードが表す文字の，文字集合中の順番．parent->children[cidx] == this が成り立つ */
  int cidx;
  /** ユーザデータ */
  T user;

  /** コンストラクタ */
  Trie(Info* info_, Trie* parent_ = nullptr, int depth_ = 0, int cidx_ = -1)
    : info(info_), children(info->br_size, nullptr), parent(parent_),
      num(0), size(0), depth(depth_), cidx(cidx_), user() {}

  static Trie* create_root(char from_, char to_) {
    auto info = new Info(from_, to_ - from_ + 1);
    auto root = new Trie(info, nullptr, 0, -1);
    info->root = root;
    return root;
  }

  /** 文字に対応するノードへのポインタを返す．
      @param ch 文字．info->from <= ch < info->from + info->br_size である必要がある．
      @param create これが true の場合に対応するノードがなければ作成される．falseの場合には，
      ch に対応するノードが存在しない場合には，nullptr が返る．
  */
  Trie* getNode(char ch, bool create = false) {
    int c = ch - info->from;
    Trie* q = children[c];
    if (q) return q;
    else if (not create) return nullptr;
    else return children[c] = new Trie(info, this, depth + 1, c);
  }

  /** 文字列に対応するノードへのポインタを返す．
      文字列は，このノードを起点に (このノードが空文字列を表すと仮定して) 解釈される．
      @param s 文字列
      @param create これが true の場合には，s に対応するノードが存在しない場合には，(そこまでの)ノードが
      作成される．false の場合には，s に対応するノードが存在しない場合には，nullptr が返る．
   */
  Trie* getNode(const string& s, bool create = false) {
    auto p = this;
    for (int i = 0; i < (int)s.size(); i++) {
      p = p->getNode(s[i], create);
      if (not p) return nullptr;
    }
    return p;
  }

  /** 存在個数を増減する．負にはならない．指定通りに増減できたときに true を返す． */
  bool addVal(ll diff) {
    bool ret = true;
    if (num + diff < 0) {
      ret = false;
      diff = -num;
    }
    num += diff;
    for (auto p = this; p; p = p->parent) p->size += diff;
    return ret;
  }

  /** 文字列の存在個数を増減する．負には鳴らない．その文字列を表すノードを返す */
  Trie* addVal(const string& s, ll diff) {
    Trie* p = getNode(s, true);
    p->addVal(diff);
    return p;
  }

  /** Trie に文字列を指定個数追加する その文字列を表すノードを返す． */
  Trie* insert(const string& s, ll add_num = 1) { return addVal(s, add_num); }

  /** Trie から文字列を (最大) 指定個数削除する．指定通り削除できたときに true を返す． */
  bool erase(const string& s, ll del_num = 1) {
    Trie* p = getNode(s);
    if (not p) return false;
    return p->addVal(-del_num);
  }

  /** 文字列がTrie中に存在している数を返す */
  ll getNum(const string& s) {
    Trie* p = getNode(s);
    if (not p) return 0;
    return p->num;
  }

  /** 文字列が Trie 中に1つ以上存在しているかどうかを返す */
  bool exists(const string& s) {
    return getNum(s) > 0;
  }

  /** Trie 中に存在する，prefix が指定されたものである文字列の数を返す */
  ll numPrefix(const string& s) {
    Trie* p = getNode(s);
    if (not p) return 0;
    return p->size;
  }

  /** ノードが表す文字列を返す． */
  string node2str() {
    string s(depth, ' ');
    for (auto p = this; p->parent ; p = p->parent) s[p->depth - 1] = info->from + p->cidx;
    return s;
  }

  /** 
      このノード以下に存在する文字列一覧 (vector<string>) を返す．
      基本的にはデバッグ用．
  */
  vector<string> stringSet() {
    return sub_stringSet("");
  }

  vector<string> sub_stringSet(const string& prefix) {
    vector<string> ret;
    for (ll i = 0; i < num; i++) ret.push_back(prefix);
    if (size == 0) return ret;
    for (int i = 0; i < info->br_size; i++) {
      auto q = children[i];
      if (not q) continue;
      auto vv = q->sub_stringSet(prefix + (char)(info->from + i));
      copy(vv.begin(), vv.end(), back_inserter(ret));
    }
    return ret;
  };
};

template <typename T>
ostream& operator<<(ostream& ostr, Trie<T> trie) {
  ostr << trie.stringSet();
  return ostr;
}

// ---- end trie.cc

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// ---- inserted function f:<< from util.cc
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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll N = SIZE(S);
  ll M; cin >> M;
  // @InpVec(M, P, type=string) [jxMxalRw]
  auto P = vector(M, string());
  for (int i = 0; i < M; i++) { string v; cin >> v; P[i] = v; }
  // @End [jxMxalRw]
  // @InpVec(M, W) [Gj4zn2U8]
  auto W = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; W[i] = v; }
  // @End [Gj4zn2U8]

  auto root = Trie<>::create_root('a', 'z');
  REP(i, 0, M) {
    auto p = root->insert(P[i]);
    p->user = W[i];
  }

  vector<ll> tbl(N + 1, 0LL);
  ll cur = 0;
  REP(i, 0, N + 1) {
    cur = max(cur, tbl[i]);
    DLOGK(i, cur);
    if (i == N) break;
    auto p = root;
    ll j = i;
    while (p and p->size > 0) {
      if (p->num > 0) {
        DLOGK(i, j, p->node2str());
        bool b = updMax(tbl[j], cur + p->user);
#if DEBUG
        if (b) {
          DLOGK(j, tbl[j]);
        }
#endif
      }
      if (j == N) break;
      p = p->getNode(S[j]);
      j++;
    }
  }
  cout << cur << endl;

  return 0;
}

