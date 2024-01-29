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

// @@ !! LIM(input f:updMaxMin cmpNaive)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

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

// @@ !! LIM -- end mark --

using u64 = unsigned long long;

int naive(istream& cin, ostream& cout) {
  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, fwd, dir=True, dec=1, read=W) [51gdgSGX]
  struct fwd_t {
    int nd;
    ll W;
    // fwd_t() {}
    fwd_t(int nd_ = int(), ll W_ = ll()) : nd(nd_), W(W_) {}
  };
  auto fwd = vector(N, vector(0, fwd_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll W; cin >> W;
    fwd[u].emplace_back(v, W);
  }
  // @End [51gdgSGX]

  ll big = 1e18;
  vector tbl(1LL << N, vector(N, 2 * big));
  vector<pll> stack;
  REP(i, 0, N) {
    tbl[1LL << i][i] = 0;
    stack.emplace_back(1LL << i, i);
  }
  while (not stack.empty()) {
    auto [x, i] = stack.back(); stack.pop_back();
    for (auto [j, w] : fwd[i]) {
      ll y = x | (1LL << j);
      ll newv = tbl[x][i] + w;
      if (newv < big and newv < tbl[y][j]) {
        tbl[y][j] = newv;
        stack.emplace_back(y, j);
      }
    }
  }
  ll ans = big;
  REP(i, 0, N) ans = min(ans, tbl[(1LL << N) - 1][i]);
  if (ans == big) {
    cout << "No\n";
  }else {
    cout << ans << endl;
  }
  

  return 0;
}


int body(istream& cin, ostream& cout) {
  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, fwd, dir=True, dec=1, read=W) [51gdgSGX]
  struct fwd_t {
    int nd;
    ll W;
    // fwd_t() {}
    fwd_t(int nd_ = int(), ll W_ = ll()) : nd(nd_), W(W_) {}
  };
  auto fwd = vector(N, vector(0, fwd_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll W; cin >> W;
    fwd[u].emplace_back(v, W);
  }
  // @End [51gdgSGX]

  ll big = 1e18;
  vector dist(N, vector(N, 2 * big));
  REP(i, 0, N) dist[i][i] = 0;
  REP(i, 0, N) for (auto [p, w] : fwd[i]) dist[i][p] = w;
  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) updMin(dist[i][j], dist[i][k] + dist[k][j]);
  vector tbl(1LL << N, vector(N, 2 * big));
  REP(i, 0, N) tbl[1LL << i][i] = 0;
  REP(x, 1, 1LL << N) {
    REP(t, 0, N) if (x >> t & 1) {
      REP(s, 0, N) if (not (x >> s & 1)) updMin(tbl[x | (1LL << s)][s], tbl[x][t] + dist[t][s]);
    }
  }
  ll ans = big;
  REP(t, 0, N) updMin(ans, tbl[(1LL << N) - 1][t]);
  if (ans >= big) {
    cout << "No\n";
  }else {
    cout << ans << endl;
  }


  return 0;
}

