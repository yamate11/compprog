#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Permutations -- possibly usable for cmpNaive

  Classes:
    IntPerm ... permutations of vector of integers
    IterPerm<T> ... permutations of T, such as vector<S>
       TODO: should have the same type as IterComb<T>
    DupIntPerm ... permutations of vector of integers, allowing duplicates.
    IntComb ... combinations of vector of integers
    IterComb<T> ... combinations of vector<T>
  Methods (common to IntPerm and IterPerm<T>):
    const T& get() ... reference to the current permutation
    bool next() ... moves to the next permutation.  Returns true if there is.
                    Otherwise, returns false and set the initial permutatation.

  Usage:

  IntPerm ip(4);      // equivalent to ip(4, 4)
  IntPerm ip(4, 2);   // take two integers from [0, 4)
  DupIntPerm dip(4,2);  
  IntComb ic(4, 2);   // 
  const vector<int>& v = ip.get();
                      // This v can be used repeatedly in loops.
  do {
    cout << v << endl;      // prints [0,1],[0,2],[0,3],[1,0],[1,2],[1,3],
  }while (ip.next());       //        [2,0],[2,1],[2,3],[3,0],[3,1],[3,2]
  do {
    cout << v << endl;      // prints [0,0],[0,1],[0,2],[0,3],[1,0],[1,1],
  }while (dip.next());      //        [1,2],[1,3],[2,0], ... ,[3,2],[3,3]
  do {
    cout << v << endl;      // prints [0,1],[0,2],[0,3],[1,2],[1,3],[2,3]
  }while (ic.next());

  vector<int> vec({3, 10, 5});
  IterPerm<vector<int>> itp(vec, 2)
  const vector<int>& v = ip.get();
  do { // prints [3,10], [3,5], [10,3], [10,5], [5,3], [5,10]
    cout << v << endl;  
  }while (ip.next());
  IterComb<int> itc(vec, 2);
  const vector<int>& w = itc.get();
  do { // prints [3,10], [3,5], [10,5]
    cout << v << endl;
  }while (itc.next());

  // When ip.next() returns false, it's internal has gone back to the
  // init state, so you can continue the next round.

*/

// @@ !! LIM(debug)
// --> f:<< debug
// ---- inserted function << from util.cc
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

template <typename T>
ostream& operator<< (ostream& os, const set<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const multiset<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const map<T1, T2>& mp) {
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

// ---- end <<
// ---- inserted library file debug.cc
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(Head&& head) {
  cerr << head << endl;
}

template <class Head, class... Tail>
void dbgLog(Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(__VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

// ---- end debug.cc
// @@ !! LIM  -- end mark --


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- perm.cc

template<typename T>
class IterPerm {
  int cand_size;
  int seq_size;
  T perm;
  vector<T> cands;
  vector<int> idx;
  
  void construct(const T& orig, int ss) {
    cand_size = orig.size();
    seq_size = ss;
    perm = T(orig.begin(), orig.begin() + seq_size);
    cands = vector<T>(seq_size);
    if (seq_size > 0) cands.at(0) = orig;
    idx = vector<int>(seq_size);
    init();
  }

  void init() {
    for (int i = 0; i < seq_size; i++) {
      perm.at(i) = cands.at(0).at(i);
      if (i > 0) {
	cands.at(i) = T(cands.at(0).begin() + i, cands.at(0).end());
      }
      idx.at(i) = 0;
    }
  }

  // IntPerm is implemented using IterPerm<vector<int>>, and
  // it needs a constructor without parameter.
  friend class IntPerm;
  IterPerm() {}

public:
  
  IterPerm(const T& orig, int ss) { construct(orig, ss); }
  IterPerm(const T& orig) { construct(orig, orig.size()); }
  
  const T& get() { return perm; }

  bool next() {
    int i = seq_size - 1;
    while (i >= 0 && ++idx.at(i) >= cand_size - i) i--;
    if (i < 0) {
      init();
      return false;
    }
    perm.at(i) = cands.at(i).at(idx.at(i));
    for (int k = i + 1; k < seq_size; k++) {
      for (int m = 0; m < cand_size - k; m++) {
	int shift = m < idx.at(k - 1) ? 0 : 1;
	cands.at(k).at(m) = cands.at(k - 1).at(m + shift);
      }
      idx.at(k) = 0;
      perm.at(k) = cands.at(k).at(0);
    }
    return true;
  }
};

class IntPerm {

  IterPerm<vector<int>> itp;

  void construct(int ns, int ss) {
    vector<int> vec(ns);
    iota(vec.begin(), vec.end(), 0);
    itp = IterPerm(vec, ss);
  }

public:

  IntPerm(int ns, int ss) { construct(ns, ss); }
  IntPerm(int ns) { construct(ns, ns); }
  const vector<int>& get() { return itp.get(); }
  bool next() { return itp.next(); }

};

template<typename T>
class IterComb {

  vector<T> orig;
  int c_size;
  vector<T> comb;
  vector<int> idx;

  void init() {
    for (int i = 0; i < c_size; i++) {
      idx.at(i) = i;
      comb.at(i) = orig.at(i);
    }
  }


public:

  IterComb() {}

  IterComb(vector<T> orig_, int c_size_)
    : orig(orig_), c_size(c_size_), comb(c_size), idx(c_size) { init(); }

  const vector<T>& get() { return comb; }

  bool next() {
    int n = orig.size();
    int i = c_size - 1;
    while (i >= 0 && ++idx.at(i) > n - (c_size - i)) i--;
    if (i < 0) {
      init();
      return false;
    }

    int k = idx.at(i);
    for ( ; i < c_size; i++, k++) {
      idx.at(i) = k;
      comb.at(i) = orig.at(k);
    }
    return true;

  }

};

class IntComb {
  
  IterComb<int> itc;

public:

  IntComb(int n, int r) {
    vector<int> seq(n);
    iota(seq.begin(), seq.end(), 0);
    itc = IterComb<int>(seq, r);
  }
  const vector<int>& get() { return itc.get(); }
  bool next() { return itc.next(); }
};

class DupIntPerm {
  int n;
  int r;
  vector<int> vec;

public:
  DupIntPerm(int n_, int r_) : n(n_), r(r_), vec(r) {}

  const vector<int>& get() { return vec; }

  bool next() {
    for (int i = r - 1; i >= 0; i--) {
      if (++vec[i] < n) return true;
      vec[i] = 0;
    }
    return false;
  }
};

// @@ !! END ---- perm.cc


int cmp_vec(const auto& v1, const auto& v2) {
  ll m = min(v1.size(), v2.size());
  for (int i = 0; i < m; i++) {
    if (v1.at(i) < v2.at(i)) return -1;
    if (v1.at(i) > v2.at(i)) return 1;
  }
  if (v1.size() < v2.size()) return -1;
  if (v1.size() > v2.size()) return 1;
  return 0;
}

void sanity_perm(auto& perm, int exp_cnt) {
    int cnt = 1;
    auto prev = perm.get();
    while (true) {
      if (!perm.next()) break;
      cnt++;
      auto cur = perm.get();
      assert(cmp_vec(prev, cur) == -1);
      prev = move(cur);
    }
    assert(cnt == exp_cnt);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    IntPerm ip(6, 4);
    sanity_perm(ip, 6*5*4*3);
  }
  {
    IntPerm ip(5);
    sanity_perm(ip, 5*4*3*2*1);
  }
  {
    vector<int> v(4);
    iota(v.begin(), v.end(), 1);
    IterPerm<vector<int>> itp(v, 2);
    sanity_perm(itp, 4*3);
  }
  {
    string s("xcde");
    IterPerm<string> itp(s);
    int cnt = 1;
    while (true) {
      if (!itp.next()) break;
      cnt++;
    }
    assert(cnt == 4*3*2*1);
  }
  {
    IntComb ic(5, 2);
    sanity_perm(ic, (5*4)/(2*1));
  }
  {
    DupIntPerm dip(3, 5);
    const auto& vec = dip.get();
    assert(vec.size() == 5);
    int i = 0;
    do {
      int x = i;
      for (int j = 0; j < 5; j++) {
        assert(x % 3 == vec[4 - j]);
        x /= 3;
      }
      i++;
    }while (dip.next());
  }
  {
    vector<int> vec({5, 10, 3, 6});
    IterComb itc(vec, 2);
    vector<vector<int>> exp({{5,10},{5,3},{5,6},{10,3},{10,6},{3,6}});
    int i = 0;
    const auto& v = itc.get();
    do {
      assert(v == exp.at(i++));
    }while (itc.next());
    assert(i == 6);
  }


  cerr << "Test Done.\n";

}
