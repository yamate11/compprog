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

// @@ !! LIM(trie)

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

/* Poorman's Binary Trie */

string ull2binstr(unsigned long long x, int len = 64) {
  string ret(len, ' ');
  REP(i, 0, len) ret[i] = (x >> (len - 1 - i) & 1) ? '1' : '0';
  return ret;
}

unsigned long long binstr2ull(string s) {
  unsigned long long ret = 0;
  for (char c : s) ret = 2 * ret + (c - '0');
  return ret;
}


// ---- end trie.cc

// @@ !! LIM -- end mark --

using ull = unsigned long long;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll len = 30;
  auto root = Trie<ull>::create_root('0', '1');

  auto f = [&](ull x, ll diff) -> void {
    string s = ull2binstr(x, len);
    auto p = root->getNode(s, true);
    p->addVal(diff);
    if (p->num == 1) p->user = x;
    else if (p->num >= 2) p->user = 0;
    p = p->parent;
    for (; p; p = p->parent) {
      ll n = p->size;
      auto p0 = p->getNode('0');
      auto p1 = p->getNode('1');
      ll n0 = p0 ? p0->size : 0;
      ll n1 = p1 ? p1->size : 0;
      if (n == 0) p->user = 0; // any
      else if (n0 == 0) p->user = p1->user;
      else if (n1 == 0) p->user = p0->user;
      else if (n == 2) p->user = p0->user ^ p1->user;
      else p->user = min(p0->user, p1->user);
    }
  };

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ull x; cin >> x;
      f(x, 1);
    }else if (tp == 2) {
      ull x; cin >> x;
      f(x, -1);
    }else if (tp == 3) {
      cout << root->user << "\n";
    }
  }

  return 0;
}

