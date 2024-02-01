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

int naive(istream& cin, ostream& cout) {

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1, read=C) [0fgA0xpb]
  struct nbr_t {
    int nd;
    ll C;
    // nbr_t() {}
    nbr_t(int nd_ = int(), ll C_ = ll()) : nd(nd_), C(C_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    nbr[u].emplace_back(v, C);
    nbr[v].emplace_back(u, C);
  }
  // @End [0fgA0xpb]
  ll K; cin >> K;
  // @InpMVec(K, ((X, dec=1), (Y, dec=1), Z)) [BemU6NgS]
  auto X = vector(K, ll());
  auto Y = vector(K, ll());
  auto Z = vector(K, ll());
  for (int i = 0; i < K; i++) {
    ll v1; cin >> v1; v1 -= 1; X[i] = v1;
    ll v2; cin >> v2; v2 -= 1; Y[i] = v2;
    ll v3; cin >> v3; Z[i] = v3;
  }
  // @End [BemU6NgS]

  ll big = 1e18;
  vector dist(N, vector(N, big));
  REP(i, 0, N) dist[i][i] = 0;
  REP(i, 0, N) for (auto [j, w] : nbr[i]) dist[i][j] = w;
  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) updMin(dist[i][j], dist[i][k] + dist[k][j]);
  REP(k, 0, K) {
    ll x = X[k], y = Y[k], z = Z[k];
    dist[x][y] = dist[y][x] = min(z, dist[x][y]);
    REP(m, 0, N) REP(i, 0, N) REP(j, 0, N) updMin(dist[i][j], dist[i][m] + dist[m][j]);
    ll ans = 0; REP(i, 0, N) REP(j, i + 1, N) ans += dist[i][j];
    cout << ans << "\n";
  }

  return 0;
}
int body(istream& cin, ostream& cout) {

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1, read=C) [0fgA0xpb]
  struct nbr_t {
    int nd;
    ll C;
    // nbr_t() {}
    nbr_t(int nd_ = int(), ll C_ = ll()) : nd(nd_), C(C_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    nbr[u].emplace_back(v, C);
    nbr[v].emplace_back(u, C);
  }
  // @End [0fgA0xpb]
  ll K; cin >> K;
  // @InpMVec(K, ((X, dec=1), (Y, dec=1), Z)) [BemU6NgS]
  auto X = vector(K, ll());
  auto Y = vector(K, ll());
  auto Z = vector(K, ll());
  for (int i = 0; i < K; i++) {
    ll v1; cin >> v1; v1 -= 1; X[i] = v1;
    ll v2; cin >> v2; v2 -= 1; Y[i] = v2;
    ll v3; cin >> v3; Z[i] = v3;
  }
  // @End [BemU6NgS]

  ll big = 1e18;
  vector dist(N, vector(N, big));
  REP(i, 0, N) dist[i][i] = 0;
  REP(i, 0, N) for (auto [j, w] : nbr[i]) dist[i][j] = w;
  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) updMin(dist[i][j], dist[i][k] + dist[k][j]);
  ll ans = 0; REP(i, 0, N) REP(j, i + 1, N) ans += dist[i][j];
  REP(k, 0, K) {
    ll x = X[k], y = Y[k], z = Z[k];
    ll diff = dist[x][y] - min(z, dist[x][y]);
    dist[x][y] = dist[y][x] = min(z, dist[x][y]);
    REP(i, 0, N) REP(j, i + 1, N) {
      if ((i == x and j == y) or (i == y and j == x)) continue;
      ll a = dist[i][x] + z + dist[y][j];
      ll b = dist[i][y] + z + dist[x][j];
      ll c = min(dist[i][j], min(a, b));
      diff += dist[i][j] - c;
      dist[i][j] = dist[j][i] = c;
    }
    ans -= diff;
    cout << ans << "\n";
  }

  return 0;
}

