#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/**
 * @file trie.cc
 * @brief Trie木の実装

 Trie木を実装したもの．

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


// @@ !! END ---- trie.cc
