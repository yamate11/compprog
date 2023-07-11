#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/**
 * @file trie.cc
 * @brief Trie木の実装

 Trie木を実装したもの．

 - ポインタによる実装
 - set モデルと multiset モデルがある．
 - ノードは一旦作ったら消さない．
 - ユーザデータは，T (テンプレートパラメタ) 型のデータとして格納できる．
   アクセスは node.user

 典型的なコード:

\code
    struct us_t {
      ll fld1;
      ll fld2;
    };
    Trie<us_t> trie{'a', 'z'};   // multiset モデル
       // Trie<us_t> trie('a', 'z', false)  なら，set モデル
    TrieNode<us_t>* root = trie.root();
    TrieNode<us_t>* nd1 = trie.insert("abcde");
    nd1.user.fld1 = 10;
    auto nd2 = trie.insert("abcd");
    nd2.user.fld2 = 30;
    auto nd3 = nd1.parent;               // nd3 == nd2
    auto nd4 = nd2.child['e' - 'a'];     // nd4 == nd1
    auto nd5 = trie.getNode("abcd");     // nd5 == nd2
    auto nd6 = trie.getNode("xxx");      // nd6 == nullptr
    auto nd7 = trie.getNode("xxx", true);   // The node is created and returned
    cout << root.depth << " " << nd1.depth;  // 0 5
    cout << nd2.exists; // true
    cout << trie.getVal("abcde"); // 1
    cout << nd3.exists; // false
    cout << trie.getVal("abcd");  // 0
\endcode

 */

/*
  Trie 

  Signature:

  古い．直さなくては....
    template <typename T>
    struct Trie {
      char from;
      int br_size;
      vector<TrNode> nodes;

      Trie(char from_, char to_);

      int insert(const string& s);
      bool erase(int idx);
      bool erase(const string& s);
      int index(const string& s, bool exists_only = true);
      int parent(int idx);
      int child(int idx, char c);
      bool exists(int idx);
      T& user(int idx);
      vector<string> to_vector_string();   // for debugging
    };
    ostream& operator<<(ostream& ostr, Trie<T> trie);

*/


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- trie.cc

/**
 * @brief Trie木
 *
 * テンプレートパラメタ T には，ユーザデータを格納するデータ型を指定する．
 *   特に使わないときには，仮に，T = ll としておく．
 */
template <typename T = ll>
struct Trie {

  /**
   *  @brief Trie のノード
   *
   */
  struct TrNode {
    /** 1文字増えたノードを格納するベクトル．サイズは Trie の br_size */
    vector<TrNode*> children;
    /** 1文字減ったノード．ルートでは nullptr が設定されている */
    TrNode* parent;
    /** このノードに対応する文字列が Trie に格納されている数 */
    ll num;
    /** このノード以下に存在する要素の数 */
    ll numSubTree;
    /** このノードの深さ */
    int depth;
    /** このノードが表す文字の，文字集合中の順番．parent->children[cidx] == this が成り立つ */
    int cidx;
    /** ユーザデータ */
    T user;
    /** コンストラクタ．Trie からは，sz は br_size で，_parent_ は適切に設定して呼び出される */
    TrNode(int sz = 0, TrNode* parent_ = nullptr, int depth_ = 0, int cidx_ = -1)
      : children(sz, nullptr), parent(parent_), num(0), numSubTree(0), depth(depth_), cidx(cidx_), user() {}
  };

  /** 最初の文字 */
  char from;
  /** 文字の種類数 */
  int br_size;
  /** ノード */
  TrNode* root;

  /** コンストラクタ */
  Trie(char from_, char to_)
    : from(from_), br_size(to_ - from_ + 1), root(new TrNode(br_size)) {}

  /** 文字列に対応するノードへのポインタを返す
      @param s 文字列
      @param create これが true の場合には，s に対応するノードが存在しない場合には，(そこまでの)ノードが
      作成される．false の場合には，s に対応するノードが存在しない場合には，nullptr が返る．
   */
  TrNode* getNode(const string& s, bool create = false) {
    TrNode* p = root;
    for (int i = 0; i < (int)s.size(); i++) {
      int c = s[i] - from;
      TrNode* q = p->children[c];
      if (q)               p = q;
      else if (not create) return nullptr;
      else                 p = p->children[c] = new TrNode(br_size, p, p->depth + 1, c);
    }
    return p;
  }

  /** 指定ノードの存在個数を増減する． 指定ノードを返す */
  TrNode* changeVal(TrNode* p, ll diff) {
    TrNode* ret = p;
    p->num += diff;
    for (; p; p = p->parent) p->numSubTree += diff;
    return ret;
  }

  /** 文字列の存在個数を増減する．その文字列を表すノードを返す */
  TrNode* changeVal(const string& s, ll diff) {
    TrNode* p = getNode(s, true);
    return changeVal(p, diff);
  }

  /** Trie に文字列を指定個数追加する その文字列を表すノードを返す． */
  TrNode* insert(const string& s, ll num = 1) { return changeVal(s, num); }

  /** Trie から文字列を (最大) 指定個数削除する．その個数だけ削除できなかったときには nullptr が返る */
  TrNode* erase(const string& s, ll num = 1) {
    TrNode* p = getNode(s);
    if (not p) return nullptr;
    if (p->num >= num) return changeVal(p, -num);
    else {
      changeVal(p, -p->num);
      return nullptr;
    }
  }

  /** 文字列がTrie中に存在している数を返す */
  ll num(const string& s) {
    TrNode* p = getNode(s);
    if (not p) return 0;
    return p->num;
  }

  /** Trie 中に存在する，prefix が指定されたものである文字列の数を返す */
  ll numSubTree(const string& s) {
    TrNode* p = getNode(s);
    if (not p) return 0;
    return p->numSubTree;
  }

  /** ノードが表す文字列を返す． */
  string node2str(TrNode* p) {
    string s(p->depth, ' ');
    for (; p->parent ; p = p->parent) s[p->depth - 1] = from + p->cidx;
    return s;
  }

  /** 
      指定されたノード以下に存在する文字列一覧 (vector<string>) を返す．
      @param p ノード
      @param withPrefix true なら，先頭からの文字列の一覧，そうでなければこのノードから先の suffix のみの一覧
  */
  vector<string> stringSet(TrNode* p, bool withPrefix = true) {
    return sub_stringSet(p, withPrefix ? node2str(p) : "");
  }

  vector<string> sub_stringSet(TrNode* p, const string& prefix) {
    vector<string> ret;
    if (not p) return ret;
    for (ll i = 0; i < p->num; i++) ret.push_back(prefix);
    if (p->numSubTree == 0) return ret;
    for (int i = 0; i < br_size; i++) {
      auto vv = sub_stringSet(p->children[i], prefix + (char)(from + i));
      copy(vv.begin(), vv.end(), back_inserter(ret));
    }
    return ret;
  };
  
};

template <typename T>
ostream& operator<<(ostream& ostr, Trie<T> trie) {
  ostr << trie.stringSet(trie.root);
  return ostr;
}


// @@ !! END ---- trie.cc
