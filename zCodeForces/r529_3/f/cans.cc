#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(cmpNaive perm UnionFind)
// --> cmpNaive perm UnionFind
// ---- inserted library file cmpNaive.cc

const string end_mark("^__=end=__^");
const string end_file_mark("^__=end_file=__^");

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
// ---- inserted library file perm.cc

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

// ---- end perm.cc
// ---- inserted library file UnionFind.cc

class UnionFind {
protected:
  int size;
  vector<int> _leader;
  vector<int> _rank;
  vector<int> _gsize;
  unordered_map<int, vector<int>> _groups;
  
public:
  UnionFind(int s);
  int leader(int i);
  int merge(int i, int j);
  int groupSize(int i);
  const unordered_map<int, vector<int>>& groups();
  const vector<int>& group(int i);
};

UnionFind::UnionFind(int s) {
  size = s;
  _leader = vector<int>(size);
  for (int i = 0; i < size; i++) { _leader.at(i) = i; }
  _rank = vector<int>(size, 1);
  _gsize = vector<int>(size, 1);
}

int UnionFind::leader(int i) {
  int cur = i;
  int nxt = _leader.at(cur);
  vector<int> seen;
  while (cur != nxt) {
    seen.push_back(cur);
    cur = nxt;
    nxt = _leader.at(cur);
  }
  for (auto j : seen) _leader.at(j) = cur;
  return cur;
}

int UnionFind::merge(int i0, int j0) {
  if (!_groups.empty()) {
    cerr << "merge() cannot be called after group() or groups()." << endl;
    exit(1);
  }
  int li = leader(i0);
  int lj = leader(j0);
  if (li == lj) return li;
  int ri = _rank.at(li);
  int rj = _rank.at(lj);
  int rep = li;
  int other = lj;
  if      (ri <  rj) swap(rep, other);
  else if (ri == rj) _rank.at(rep)++;
  _leader.at(other) = rep;
  _gsize.at(rep) += _gsize.at(other);
  return rep;
}

int UnionFind::groupSize(int i) {
  return _gsize.at(leader(i));
}

const unordered_map<int, vector<int>>& UnionFind::groups() {
  if (_groups.empty()) {
    for (int i = 0; i < size; i++) _groups[leader(i)].push_back(i);
  }
  return _groups;  
}

const vector<int>& UnionFind::group(int i) { return groups().at(leader(i)); }



// ---- end UnionFind.cc
// @@ !! LIM  -- end mark --

int naive(istream& cin, ostream& cout) {
  ll n, m; cin >> n >> m;
  vector<ll> cost(n+1);
  for (ll i = 1; i <= n; i++) {
    ll c; cin >> c;
    cost[i] = c;
  }
  vector<map<ll, ll>> offer(n+1);
  for (ll i = 0; i < m; i++) {
    ll x, y, w; cin >> x >> y >> w;
    offer[x][y] = w;
    offer[y][x] = w;
  }

  using sta = pair<ll, ll>;
  vector<sta> c2;
  for (ll i = 1; i <= n; i++) {
    for (ll j = i + 1; j <= n; j++) c2.emplace_back(i, j);
  }
  ll K = c2.size();
  IntComb ic(K, n - 1);
  const vector<int>& v = ic.get();
  ll ans = LLONG_MAX;
  do {
    UnionFind uf(n+1);
    ll sum = 0;
    for (ll i : v) {
      auto [p, q] = c2[i];
      uf.merge(p, q);
      ll s1 = LLONG_MAX;
      if (offer[p].find(q) != offer[p].end()) s1 = offer[p][q];
      ll s2 = cost[p] + cost[q];
      ll s = min(s1, s2);
      sum += s;
    }
    if (uf.groupSize(1) != n) continue;
    ans = min(ans, sum);
  }while (ic.next());
  cout << ans << endl;

  return 0;
}
int body(istream& cin, ostream& cout) {

  ll n, m; cin >> n >> m;
  using sta = pair<ll, ll>;
  vector<sta> cost;
  for (ll i = 1; i <= n; i++) {
    ll c; cin >> c;
    cost.emplace_back(c, i);
  }
  sort(cost.begin(), cost.end());
  // using stb = pair<ll, ll>;
  vector<map<ll, ll>> offer(n+1);
  for (ll i = 0; i < m; i++) {
    ll x, y, w; cin >> x >> y >> w;
    if (offer[x][y] > 0 && offer[x][y] <=w) continue;
    offer[x][y] = w;
    offer[y][x] = w;
  }
  using stc = pair<ll, ll>;
  priority_queue<stc, vector<stc>, greater<stc>> pque;
  vector<bool> added(n+1);
  ll tot = 0;

  auto doadd = [&](ll p) -> void {
    added[p] = true;
    for (auto [q, w] : offer[p]) {
      if (!added[q]) pque.emplace(w, q);
    }
  };
  ll idx = 0;
  auto getnxt = [&]() -> pair<ll, ll> {
    while (true) {
      if (idx >= n) return {-1, -1};
      auto [c, p] = cost[idx];
      if (!added[p]) return {c, p};
      idx++;
    }
  };
  auto pendingcost = [&]() -> pair<ll, ll> {
    while (true) {
      if (pque.empty()) return {ll(1e18), -1};
      auto [c, p] = pque.top();
      if (!added[p]) return {c, p};
      pque.pop();
    }
  };

  auto [c0, p0] = getnxt();
  doadd(p0);

  while (true) {
    auto [c1, p1] = getnxt();
    c1 += c0;
    if (p1 < 0) break;
    auto [c2, p2] = pendingcost();
    if (c1 <= c2) {
      idx++;
      tot += c1;
      doadd(p1);
    }else {
      pque.pop();
      tot += c2;
      doadd(p2);
    }
  }
  cout << tot << endl;
  

  return 0;
}

