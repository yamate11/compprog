#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/**
 * @file trie.cc
 * @brief Trie木の実装

 Trie木を実装したもの．

 - ユーザデータは，T (テンプレートパラメタ) 型のデータとして格納できる．
   アクセスは trie.user(idx)
 - trie.index(s) は，インデックスを返すが，sがtrieの中に存在するときだけ．
 - trie.index(s, false) とすると，s が trie の中になくてもインデックスを返す
   (ノードは存在していないとダメ)

 典型的なコード:

\code
    Trie<ll> trie('a', 'z');
    int idx1 = trie.insert("abcde");    
    trie.user(idx1) = 0;
    int idx2 = trie.insert("ab");       
    trie.user(idx2) = 1;
    int x = trie.index("abcde");       // x == idx1
    int y = trie.index("abc");         // y == -1
    int z = trie.index("abc", false);  // z >= 0    
    ll w = trie.user(idx2);            // w == 1
\endcode

 */

/*
  Trie 

  Signature:

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
 */
template <typename T = ll>
struct Trie {

  /**
   *  @brief Trie のノード
   *
   */
  struct TrNode {
    /** 1文字増えた文字列のインデックスを格納するベクトル．サイズは Trie の br_size */
    vector<int> _next;
    /** 1文字減った文字列のインデックス．ルートでは -1 が設定されている */
    int _parent;
    /** このノードに対応する文字列が Trie に格納されているか */
    bool _exists;
    /** ユーザデータ */
    T _user;
    /** コンストラクタ．Trie からは，sz は br_size で，_parent_ は適切に設定して呼び出される */
    TrNode(int sz = 0, int _parent_ = -1) : _next(sz, -1), _parent(_parent_), _exists(false), _user() {}
  };

  /** 最初の文字 */
  char from;
  /** 文字の種類数 */
  int br_size;
  /** ノード */
  vector<TrNode> nodes;

  /** コンストラクタ */
  Trie(char from_, char to_)
    : from(from_), br_size(to_ - from_ + 1), nodes(1, TrNode(br_size)) {}

  int _index(const string& s, bool create) {
    int idx = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      int c = s[i] - from;
      if (nodes[idx]._next[c] < 0) {
        if (not create) return -1;
        nodes[idx]._next[c] = nodes.size();
        nodes.emplace_back(br_size, idx);
        idx = nodes.size() - 1;
      }else {
	idx = nodes[idx]._next[c];
      }
    }
    return idx;
  }

  /** 文字列を Trie に挿入する */
  int insert(const string& s) {
    int idx = _index(s, true);
    nodes[idx]._exists = true;
    return idx;
  }

  /** 指定したインデックスに対応する文字列を Trie から削除する */
  bool erase(int idx) {
    bool ret = nodes[idx]._exists;
    nodes[idx]._exists = false;
    return ret;
  }

  /** 文字列を Trie から削除する */
  bool erase(const string& s) {
    int idx = _index(s, false);
    if (idx < 0) return false;
    return erase(idx);
  }

  /** 
      文字列のインデックスを返す．
      @param s 文字列
      @param exists_only これが true の場合には，s が Trie に存在している場合にのみ，有効なインデックス (非負)
      が返り，存在していない場合には -1 が返る．false の場合には，s に対応するノードが存在すれば
      そのインデックスが返る．
  */
  int index(const string& s, bool exists_only = true) {
    int idx = _index(s, false);
    if (idx < 0) return -1;
    if (exists_only and not nodes[idx]._exists) return -1;
    return idx;
  }

  /** 1文字少ない文字列のインデックス */
  int parent(int idx) { return nodes[idx]._parent; }

  /** 1文字多い文字列のインデックス．c はベクトルの添字ではなく文字であることに注意 */
  int child(int idx, char c) { return nodes[idx]._next[c - from]; }

  /** インデックス idx に対応する文字列が存在しているか．引数 idx はインデックスであることに注意 */
  bool exists(int idx) { return nodes[idx]._exists; }

  /** ユーザデータ */
  T& user(int idx) { return nodes[idx]._user; }

  /** 文字列ベクトルを返す．デバッグ用．*/
  vector<string> to_vector_string() {
    vector<string> vec;
    auto sub = [&](auto rF, int idx, string& s) -> void {
      if (nodes[idx]._exists) vec.push_back(s);
      for (int i = 0; i < br_size; i++) {
        int j = nodes[idx]._next[i];
        if (j >= 0) {
          s.push_back(from + i);
          rF(rF, j, s);
          s.pop_back();
        }
      }
    };
    string s = "";
    sub(sub, 0, s);
    return vec;
  }

};

template <typename T>
ostream& operator<<(ostream& ostr, Trie<T> trie) {
  ostr << trie.to_vector_string();
  return ostr;
}


// @@ !! END ---- trie.cc
