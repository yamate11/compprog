#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:<< trie)

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

// ---- inserted library file trie.cc
#line 17 "/home/y-tanabe/proj/compprog/clib/trie.cc"

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

// @@ !! LIM -- end mark --
#line 7 "trie_skel.cc"

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    auto trie = create_trie('a', 'd');
    assert (trie.from == 'a');
    assert (trie.br_size == 4);

    int p1 = trie.insert("abcd");
    trie.insert("ac");
    trie.insert("add");
    trie.insert("add");
    assert(trie.num_string("abcd") == 1);
    assert(trie.num_string("add") == 2);
    trie.erase("add");
    assert(trie.num_string("add") == 1);
    trie.erase("add");
    assert(trie.num_string("add") == 0);
    int p2 = trie.string_index("");
    assert (p2 == 0);

    int p3 = trie.string_index("abcdd");
    assert(p3 < 0);
    int p4 = trie.string_index("abcdd", true);
    assert(trie.child_index(p1, 'd') == p4);
    assert(trie.parent_index(p4) == p1);
    assert(trie.prefixed_string_index(p1, "d") == p4);
    int p10 = trie.insert("cdc");
    trie.insert("cdca");
    trie.insert("cdcaa");
    trie.insert("cdcd");
    assert(trie.num(p10) == 1);
    assert(trie.size(p10) == 4);
    int p11 = trie.string_index("ddddaaadd");
    assert(trie.num(p11) == 0);
    assert(trie.size(p11) == 0);
  }
  {
    auto trie = create_trie('A', 'E');
    trie.insert("ABC");
    int p1 = trie.insert("ABD");
    int p2 = trie.insert("ABEAB");
    trie.insert("ABC");
    assert(trie.node_to_str(p1) == "ABD");
    assert(trie.node_to_str(p2) == "ABEAB");
    assert(trie.num_prefix("A") == 4);
    assert(trie.num_prefix("AB") == 4);
    assert(trie.num_prefix("ABE") == 1);
    auto vec1 = trie.string_set();
    auto vec2 = vector<string>{"ABC", "ABC", "ABD", "ABEAB"};
    assert(vec1 == vec2);
    stringstream ss1, ss2;
    ss1 << trie;
    ss2 << trie.string_set();
    assert(ss1.str() == ss2.str());
  }
  {
    assert(ull2binstr(10, 4) == "1010");
    assert(binstr2ull("10010") == 18);
  }

  cout << "ok\n";
  return 0;
}
