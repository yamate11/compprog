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

// @@ !! LIM()

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
    /** このノード以下に存在する要素の数 */
    int _numElems;
    /** 深さ */
    int _depth;
    /** このノードが表す文字の，文字集合中の順番 */
    int _cidx;
    /** ユーザデータ */
    T _user;
    /** コンストラクタ．Trie からは，sz は br_size で，_parent_ は適切に設定して呼び出される */
    TrNode(int sz = 0, int _parent_ = -1, int _depth_ = 0, int _cidx_ = -1)
      : _next(sz, -1), _parent(_parent_), _exists(false), _numElems(0), _depth(_depth_), _cidx(_cidx_), _user() {}
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
        nodes.emplace_back(br_size, idx, nodes[idx]._depth + 1, c);
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
    for (ll i = idx; i >= 0; i = nodes[i]._parent) nodes[i]._numElems++;
    return idx;
  }

  /** 指定したインデックスに対応する文字列を Trie から削除する */
  bool erase(int idx) {
    bool ret = nodes[idx]._exists;
    if (ret) {
      nodes[idx]._exists = false;
      for (ll i = idx; i >= 0; i = nodes[i]._parent) nodes[i]._numElems--;
    }
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

  /** 1文字少ない文字列のインデックス 
      idx にルート (0) を指定すると -1 が返される
   */
  int parent(int idx) {
    if (idx < 0) return -1;
    return nodes[idx]._parent;
  }

  /** 1文字多い文字列のインデックス．c はベクトルの添字ではなく文字であることに注意 
      子ノードが存在しないときには -1 を返す．
   */
  int child(int idx, char c) {
    if (idx < 0) return -1;
    return nodes[idx]._next[c - from];
  }

  /** インデックス idx に対応する文字列が存在しているか．引数 idx はインデックスであることに注意 */
  bool exists(int idx) {
    if (idx < 0) return false;
    return nodes[idx]._exists;
  }

  /** この trie の中にある，インデックス idx に対応する文字列を部分文字列とする，文字列の数 */
  int numElems(int idx) {
    if (idx < 0) return 0;
    return nodes[idx]._numElems;
  }

  /** ユーザデータ */
  T& user(int idx) { return nodes[idx]._user; }

  /** インデックス idx が表す文字列を返す． */
  string index2str(int idx) {
    string s(nodes[idx]._depth, ' ');
    for (int i = idx; i > 0; i = nodes[i]._parent) s[nodes[i]._depth - 1] = from + nodes[i]._cidx;
    return s;
  }

  /** 
      インデックス idx 以下に存在する文字列のリスト (vector<string>) を返す．
      引数 withPrefix が true なら，先頭からの文字列のリスト，そうでなければこの idx から先の suffix のみのリスト
  */
  vector<string> nodeset(int idx, bool withPrefix = true) {
    return sub_nodeset(idx, withPrefix ? index2str(idx) : "");
  }

  vector<string> sub_nodeset(int idx1, string prefix) {
    vector<string> ret;
    if (idx1 < 0) return ret;
    if (nodes[idx1]._numElems == 0) return ret;
    for (int i = 0; i < br_size; i++) {
      auto vv = sub_nodeset(nodes[idx1]._next[i], prefix + (char)(from + i));
      copy(vv.begin(), vv.end(), back_inserter(ret));
    }
    if (nodes[idx1]._exists) ret.push_back(prefix);
    return ret;
  };
  
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


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll K = 30;
  struct UD {
    ll vmin;   // value minimum
  };
  Trie<UD> trie('0', '1');

  auto to_bin = [&](ll n) -> string {
    string ret(K, ' ');
    REP(i, 0, K) {
      if (n >> i & 1) ret[K - 1 - i] = '1';
      else            ret[K - 1 - i] = '0';
    };
    return ret;
  };
  auto to_ll = [&](string s) -> ll {
    ll ret = 0;
    REP(i, 0, K) ret = ret * 2 + (s[i] - '0');
    return ret;
  };

  auto update = [&](ll idx0) -> void {
    for (int idx = trie.parent(idx0); idx >= 0; idx = trie.parent(idx)) {
      ll c1 = trie.child(idx, '0');
      ll c2 = trie.child(idx, '1');
      ll n1 = trie.numElems(c1);
      ll n2 = trie.numElems(c2);
      if (n1 < n2) { swap(n1, n2); swap(c1, c2); }
      if (n2 == 0) trie.user(idx).vmin = trie.user(c1).vmin;
      else if (n2 == 1) {
        if (n1 == 1) {
          auto ns1 = trie.nodeset(c1);
          auto ns2 = trie.nodeset(c2);
          assert(SIZE(ns1) == 1 and SIZE(ns2) == 1);
          trie.user(idx).vmin = to_ll(ns1[0]) ^ to_ll(ns2[0]);
        }else {
          trie.user(idx).vmin = trie.user(c1).vmin;
        }
      }else {
        trie.user(idx).vmin = min(trie.user(c1).vmin, trie.user(c2).vmin);
      }
    }
  };

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x; cin >> x;
      string sx = to_bin(x);
      ll idx = trie.insert(sx);
      update(idx);
    }else if (tp == 2) {
      ll x; cin >> x;
      string sx = to_bin(x);
      ll idx = trie.index(sx);
      trie.erase(idx);
      update(idx);
    }else if (tp == 3) {
      cout << trie.user(0).vmin << "\n";
    }else assert(0);
  }

  return 0;
}

