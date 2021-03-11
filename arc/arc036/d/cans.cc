#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(UnionFind cmpNaive)
// --> UnionFind cmpNaive
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

// ---- end cmpNaive.cc
// @@ !! LIM  -- end mark --

int naive(istream& cin, ostream& cout) {
  ll N, Q; cin >> N >> Q;

  vector even_link(N+1, vector(N+1, int8_t(0)));
  vector odd_link(N+1, vector(N+1, int8_t(0)));
  bool changed = false;
  for (ll i = 1; i <= N; i++) even_link[i][i] = 1;

  auto update = [&]() -> void {
    while (changed) {
      changed = false;
      for (ll i = 1; i <= N; i++) {
	for (ll j = 1; j <= N; j++) {
	  for (ll k = 1; k <= N; k++) {
	    bool eji = even_link[j][i];
	    bool eik = even_link[i][k];
	    bool oji = odd_link[j][i];
	    bool oik = odd_link[i][k];
	    if (((eji && eik) || (oji && oik)) && !even_link[j][k]) {
	      changed = true;
	      even_link[j][k] = even_link[k][j] = 1;
	    }
	    if (((eji && oik) || (oji && eik)) && !odd_link[j][k]) {
	      changed = true;
	      odd_link[j][k] = odd_link[k][j] = 1;
	    }
	  }
	}
      }
    }
  };

  for (ll _q = 0; _q < Q; _q++) {
    ll w, x, y, z; cin >> w >> x >> y >> z;
    if (w == 2) {
      update();
      cout << (even_link[x][y] ? "YES\n" : "NO\n");
    }else {
      if (z % 2 == 0) {
	if (!even_link[x][y]) {
	  changed = true;
	  even_link[x][y] = even_link[y][x] = 1;
	}
      }else {
	if (!odd_link[x][y]) {
	  changed = true;
	  odd_link[x][y] = odd_link[y][x] = 1;
	}
      }
    }
  }

  return 0;
}


int body(istream& cin, ostream& cout) {

  ll N, Q; cin >> N >> Q;
  UnionFind uf(N);
  vector<ll> fr(N, -1LL);

  auto link = [&](ll p, ll q) -> void {
    if (p >= 0) fr[p] = q;
    if (q >= 0) fr[q] = p;
  };
  auto ex_merge = [&](ll p, ll q) -> ll {
    if (p >= 0 && q >= 0) return uf.merge(p, q);
    if (p >= 0) return p;
    if (q >= 0) return q;
    return -1;
  };

  for (ll _q = 0; _q < Q; _q++) {
    ll w, x, y, z; cin >> w >> x >> y >> z; x--; y--;
    ll p = uf.leader(x);
    ll q = uf.leader(y);
    if (w == 2) {
      cout << (p == q ? "YES\n" : "NO\n");
      continue;
    }
    if (p == q) {
      if (z % 2 == 1) {
	ll r = fr[p];
	if (r >= 0) p = uf.merge(p, r);
	fr[p] = p;
      }
    }else {
      if (fr[p] == p || fr[q] == q) {
	ll t = -1;
	if (fr[p] != p) t = fr[p];
	if (fr[q] != q) t = fr[q];
	ll r = uf.merge(p, q);
	r = ex_merge(r, t);
	fr[r] = r;
      }else if (fr[p] == q) {
	if (z % 2 == 0) {
	  ll r = uf.merge(p, q);
	  fr[r] = r;
	}
      }else {
	ll pp = fr[p];
	ll qq = fr[q];
	if (z % 2 == 0) {
	  link(ex_merge(p, q), ex_merge(pp, qq));
	}else {
	  link(ex_merge(p, qq), ex_merge(pp, q));
	}
      }
    }
  }

  return 0;
}

