/*
  Binary Trie

  Usage:
    BinTrie bt(60);  // number of bits with length <=60
    bt.insert(x);    // single insert
    bt.insert(x, 10);   // 10 copies of x
    bt.erase(x);       // single erase
    bt.erase(x, 5);    // erase 5 copies -- must have 5 or more copies beforehand
    bt.erase_safe(x, 20);   // erase as many copies as possible in the range of <= 20
    n = bt.find(x);  // returns the number of copies of x
    n = bt.num_le(x);  // returns the sum of the number of copies of y with y <= x.  x is NOT necessarily in [0, 1LL<<len)
    n = bt.num_lt(x);  // returns the sum of the number of copies of y with y < x.   x is NOT necessarily in [0, 1LL<<len)
    x = bt.kth(7);    // 8th smallest element.  (bt.kth(0) is the smallest element.)  Returns -1 if no such elelment exists.
    y = bt.lower_bound(x);  // lower bound (Returns a ll instead of an iterator).  Returns -1 if no such element exists.
    cout << bt; // for debugging
 */


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- bintrie.cc

struct BTNode {
  int ne; // number of elements stored
  int p0; // index for 0 successor (-1 if not exists)
  int p1; // index for 1 successor (-1 if not exists)
  BTNode() : ne(0), p0(-1), p1(-1) {}
  int& nxt(int b) { return b == 0 ? p0 : p1; }
};

struct BinTrie {
  int len;
  vector<BTNode> body;

  BinTrie(int len_) : len(len_), body(1) {}

  int _num_branch(int b, int idx) {
    int p = body[idx].nxt(b);
    return p < 0 ? 0 : body[p].ne;
  }

  void insert(ll x, int num = 1) {
    int idx = 0;
    for (int i = len - 1; i >= 0; i--) {
      int& pp = body[idx].nxt(x >> i & 1);
      if (pp < 0) {
        pp = body.size();
        body.resize(pp + 1);
        // Caution: now pp is invalidated
      }
      body[idx].ne += num;
      idx = body[idx].nxt(x >> i & 1);
    }
    body[idx].ne += num;
  }

  int find(ll x) {
    int idx = 0;
    for (int i = len - 1; i >= 0; i--) {
      int& pp = body[idx].nxt(x >> i & 1);
      if (pp < 0) return 0;
      idx = pp;
    }
    return body[idx].ne;
  }

  void erase(ll x, int num = 1) { insert(x, -num); }

  int erase_safe(ll x, int num = 1) {
    int m = find(x);
    if (m == 0) return 0;
    int k = min(m, num);
    insert(x, -k);
    return k;
  }

  int num_le(ll x) {
    if (x < 0) return 0;
    if (x >= (1LL << len)) return body[0].ne;
    int ret = 0;
    int idx = 0;
    for (int i = len - 1; i >= 0; i--) {
      int b = x >> i & 1;
      if (b == 1) ret += _num_branch(0, idx);
      if (_num_branch(b, idx) == 0) return ret;
      idx = body[idx].nxt(b);
    }
    ret += body[idx].ne;
    return ret;
  }

  int num_lt(ll x) { return num_le(x - 1); }

  ll kth(int k) {  // 0-indexed.  i.e. kth(0) is the minimum element.
    if (k >= body[0].ne) return -1LL;
    ll ret = 0;
    int idx = 0;
    for (int i = len - 1; i >= 0; i--) {
      int t = _num_branch(0, idx);
      if (k < t) idx = body[idx].p0;
      else {
        k -= t;
        ret |= (1LL << i);
        idx = body[idx].p1;
      }
    }
    return ret;
  }

  ll lower_bound(ll x) {
    if (body[0].ne == 0) return -1;
    int idx = 0;
    int cand_i = -1, cand_idx = -1;
    int i;
    for (i = len - 1; i >= 0; i--) {
      int b = x >> i & 1;
      if (b == 0 and _num_branch(1, idx) > 0) { cand_i = i; cand_idx = idx; }
      if (_num_branch(b, idx) == 0) break;
      idx = body[idx].nxt(b);
    }
    if (i < 0) return x;
    if (cand_i < 0) return -1;
    i = cand_i;
    idx = cand_idx;
    ll mask = ~((1LL << (i + 1)) - 1);
    ll ret = (x & mask) | (1LL << i) ;
    idx = body[idx].p1;
    i--;
    for (; i >= 0; i--) {
      int b = _num_branch(0, idx) > 0 ? 0 : 1;
      ret |= (ll(b) << i);
      idx = body[idx].nxt(b);
    }
    return ret;
  }

  ll upper_bound(ll x) { return lower_bound(x + 1); }
  
  friend ostream& operator <<(ostream& ostr, const BinTrie& bt) {
    vector<pair<ll, int>> vec;
    auto add = [&](auto rF, ll v, int idx, int lev) -> void {
      if (idx < 0) return;
      if (lev == bt.len) {
        if (bt.body[idx].ne != 0) vec.emplace_back(v, bt.body[idx].ne);
        return;
      }
      rF(rF, v, bt.body[idx].p0, lev + 1);
      rF(rF, v | (1LL << (bt.len - 1 - lev)), bt.body[idx].p1, lev + 1);
    };
    add(add, 0, 0, 0);
    ostr << "[";
    bool fst = true;
    for (auto [v, n] : vec) {
      if (fst) fst = false;
      else ostr << ", ";
      ostr << v << ":" << n;
    }
    ostr << "]";
    return ostr;
  }

};    


// @@ !! END ---- board.cc
