#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(FuncGraph cmpNaive forall)

// ---- inserted library file FuncGraph.cc

struct FuncGraph {
  int size;
  vector<int> fwd;
  vector<int> _cc;
  vector<int> _cc_size;
  vector<int> _cycle_size;
  vector<int> _on_cycle;
  vector<int> _dp;
  bool _built;

  FuncGraph(int size_) : size(size_), fwd(size), _cc(size, -1), _cc_size(), _cycle_size(),
                         _on_cycle(size), _dp(size, -1), _built(false) {}

  void add_edge(int i, int j) {
    fwd[i] = j;
  };

  int _set_depth(int i) {
    if (_dp[i] < 0) {
      if (_on_cycle[i] == i) _dp[i] = 0;
      else _dp[i] = _set_depth(fwd[i]) + 1;
    }
    return _dp[i];
  }

  void build() {
    if (_built) throw runtime_error("FuncGraph: built() should be called at most once.");
    for (int i = 0; i < size; i++) {
      if (_cc[i] < 0) {
        int tmpidx = _cc_size.size();
        vector<int> stack;
        int k;
        for (k = i; _cc[k] < 0; k = fwd[k]) {
          _cc[k] = tmpidx;
          stack.push_back(k);
        }
        if (_cc[k] == tmpidx) {
          _cc_size.push_back(stack.size());
          bool on = true;
          while (not stack.empty()) {
            int m = stack.back(); stack.pop_back();
            _on_cycle[m] = on ? m : k;
            if (m == k) {
              _cycle_size.push_back(_cc_size[tmpidx] - stack.size());
              on = false;
            }
          }
        }else {
          _cc_size[_cc[k]] += stack.size();
          while (not stack.empty()) {
            int m = stack.back(); stack.pop_back();
            _on_cycle[m] = _on_cycle[k];
            _cc[m] = _cc[k];
          }
        }
      }
    }
    for (int i = 0; i < size; i++) _set_depth(i);
    _built = true;
  }

  ll numcc() {
    if (not _built) build();
    return (ll)_cc_size.size();
  }

  ll ccid(int i) {
    if (not _built) build();
    return _cc[i];
  }

  ll cc_size(int i) {
    if (not _built) build();
    return _cc_size[ccid(i)];
  }

  ll cycle_size(int i) {
    if (not _built) build();
    return _cycle_size[ccid(i)];
  }

  ll node_on_cycle(int i) {
    if (not _built) build();
    return _on_cycle[i];
  }

  bool is_on_cycle(int i) {
    if (not _built) build();
    return _dp[i] == 0;
  }

  ll dist_to_cycle(int i) {
    if (not _built) build();
    return _dp[i];
  }

};

// ---- end FuncGraph.cc

// ---- inserted library file cmpNaive.cc

const string end_mark("^__=end=__^");

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
    ss_out << setprecision(20);
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
    }else if (strcmp(argv[1], "skip") == 0) {
      exit(0);
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

// ---- inserted library file forall.cc

#define EX_REP_LL(i, from, to) for (ll i = (from); i < (to); i++)
#define EX_REP_RB(x, coll) for (auto x : coll)
#define EXGEN(rep_part, cond, yes, no_behaviour) ([&]() { rep_part if (cond) return (yes); no_behaviour; }())
#define EXISTS_BASE(rep_part, cond) EXGEN(rep_part, cond, true, return false)
#define EXFIND_BASE(rep_part, cond, t) EXGEN(rep_part, cond, t, assert(0))
#define EXFIND_D_BASE(rep_part, cond, t, def) EXGEN(rep_part, cond, t, return def)

#define EXISTS(i, from, to, cond) EXISTS_BASE(EX_REP_LL(i, from, to), cond)
#define FORALL(i, from, to, cond) (not EXISTS(i, from, to, not (cond)))
#define EXFIND(i, from, to, cond) EXFIND_BASE(EX_REP_LL(i, from, to), cond, i)
#define EXFIND_D(i, from, to, cond, def) EXFIND_D_BASE(EX_REP_LL(i, from, to), cond, i, def)

#define EXISTS_C(x, coll, cond) EXISTS_BASE(EX_REP_RB(x, coll), cond)
#define FORALL_C(x, coll, cond) (not EXISTS_C(x, coll, not (cond)))
#define EXFIND_C(x, coll, cond) EXFIND_BASE(EX_REP_RB(x, coll), cond, x)
#define EXFIND_D_C(x, coll, cond, def) EXFIND_D_BASE(EX_REP_RB(x, coll), cond, x, def)

#define COUNT_BASE(rep_part, cond) ([&](){ ll ret = 0; rep_part if (cond) ret++; return ret; }())
#define COUNT(i, from, to, cond) COUNT_BASE(EX_REP_LL(i, from, to), cond)
#define COUNT_C(x, coll, cond) COUNT_BASE(EX_REP_RB(x, coll), cond)

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

// @@ !! LIM -- end mark --

#if DEBUG
  ll sz = 4;
#else
  ll sz = 26;
#endif

int naive(istream& cin, ostream& cout) {
  ll N; cin >> N;

  auto solve = [&]() -> ll {

    auto check = [&](string& s, string& t) -> bool {
      vector<ll> go(sz, -1LL);
      REP(i, 0, N) {
        ll d1 = s[i] - 'a';
        ll d2 = t[i] - 'a';
        if (go[d1] < 0) {
          go[d1] = d2;
        }else if (go[d1] != d2) {
          return false;
        }
      }
      return true;
    };

    auto appear = [&](string& s, char c) {
      vector<ll> ret;
      REP(i, 0, N) {
        if (s[i] == c) ret.push_back(i);
      }
      return ret;
    };

    string S, T; cin >> S >> T;
  
    if (S == T) return 0;
    if (not check(S, T)) return -1;
    unordered_map<string, ll> mp;
    mp[S] = 0;
    queue<string> que;
    que.push(S);
    while (not que.empty()) {
      string s1 = que.front(); que.pop();
      for (char c1 = 'a'; c1 < 'a' + sz; c1++) {
        vector app = appear(s1, c1);
        if (app.empty()) continue;
        for (char c2 = 'a'; c2 < 'a' + sz; c2++) {
          if (c2 == c1) continue;
          string s2 = s1;
          for (ll p : app) s2[p] = c2;
          if (s2 == T) return mp[s1] + 1;
          if (mp.contains(s2)) continue;
          if (not check(s2, T)) continue;
          mp[s2] = mp[s1] + 1;
          que.push(s2);
        }
      }
    }
    return -1;
  };
  cout << solve() << "\n";

  return 0;
}


int body(istream& cin, ostream& cout) {

  ll N; cin >> N;
  string S, T; cin >> S >> T;

  vector A(sz, -1LL);
  REP(i, 0, N) {
    ll x = S[i] - 'a';
    ll y = T[i] - 'a';
    if (A[x] == y) {
      // do nothing
    }else if (A[x] < 0) {
      A[x] = y;
    }else {
      cout << -1 << endl;
      return 0;
    }
  }
  
  FuncGraph fg(sz + 1);
  REP(i, 0, sz) {
    if (A[i] < 0) {
      fg.add_edge(i, sz);
    }
    else {
      fg.add_edge(i, A[i]);
    }
  }
  fg.add_edge(sz, sz);

  if (FORALL(i, 0, sz, fg.cycle_size(i) == fg.cc_size(i)) and EXISTS(i, 0, sz, fg.cycle_size(i) > 1)) {
    cout << -1 << endl;
    return 0;
  }

  vector checked(sz + 1, false);
  ll add = 0;
  REP(i, 0, sz) {
    ll ccid = fg.ccid(i);
    if (checked[ccid]) continue;
    checked[ccid] = true;
    if (fg.cycle_size(i) > 1 and fg.cycle_size(i) == fg.cc_size(i)) add++;
  }
  ll ans = 0;
  REP(i, 0, sz) if (A[i] >= 0 and A[i] != i) ans++;
  cout << ans + add << endl;
  

  return 0;
}

