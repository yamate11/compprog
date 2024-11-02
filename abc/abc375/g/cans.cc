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

// @@ !! LIM(f:updMaxMin cmpNaive)

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
*/

// ---- end cmpNaive.cc

// @@ !! LIM -- end mark --

int naive(istream& cin, ostream& cout) {
  ll big = 1e18;

  ll N, M; cin >> N >> M;
  // @InpMVec(M, ((A, dec=1), (B, dec=1), C)) [IVCyzSnL]
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
    ll v3; cin >> v3; C[i] = v3;
  }
  // @End [IVCyzSnL]

  vector dist0(N, vector(N, big));
  REP(i, 0, N) dist0[i][i] = 0;
  REP(i, 0, M) dist0[A[i]][B[i]] = dist0[B[i]][A[i]] = C[i];
  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) updMin(dist0[i][j], dist0[i][k] + dist0[k][j]);

  REP(m, 0, M) {
    vector dist1(N, vector(N, big));
    REP(i, 0, N) dist1[i][i] = 0;
    REP(i, 0, M) if (i != m) dist1[A[i]][B[i]] = dist1[B[i]][A[i]] = C[i];
    REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) updMin(dist1[i][j], dist1[i][k] + dist1[k][j]);
    if (dist0[0][N - 1] == dist1[0][N - 1]) cout << "No\n";
    else                                    cout << "Yes\n";
  }

  return 0;
}

int body(istream& cin, ostream& cout) {

  ll big = 1e18;

  ll N, M; cin >> N >> M;
  // @InpMVec(M, ((A, dec=1), (B, dec=1), C)) [IVCyzSnL]
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
    ll v3; cin >> v3; C[i] = v3;
  }
  // @End [IVCyzSnL]

  vector nbr(N, vector<pll>());
  REP(m, 0, M) {
    nbr[A[m]].emplace_back(B[m], C[m]);
    nbr[B[m]].emplace_back(A[m], C[m]);
  }
    
  auto dij = [&](ll start) {
    vector dist(N, big);
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    dist[start] = 0;
    pque.emplace(0, start);
    while (not pque.empty()) {
      auto [d, x] = pque.top(); pque.pop();
      if (dist[x] == d) {
        for (auto [y, len] : nbr[x]) {
          ll newd = d + len;
          if (newd < dist[y]) {
            dist[y] = newd;
            pque.emplace(newd, y);
          }
        }
      }
    }
    return dist;
  };

  auto distL = dij(0);
  auto distR = dij(N - 1);

  assert(distL[N - 1] == distR[0]);
  ll alld = distR[0];

  vector onR(N, false);
  REP(i, 0, N) onR[i] = (distL[i] + distR[i] == alld);
  
  vector fwd(N, vector<ll>());
  vector bwd(N, vector<ll>());
  REP(i, 0, N) {
    if (not onR[i]) continue;
    for (auto [j, len] : nbr[i]) {
      if (onR[j] and distL[i] + len + distR[j] == alld) {
        fwd[i].push_back(j);
        bwd[j].push_back(i);
      }
    }
  }
  vector rank(N, -1LL);
  rank[N - 1] = 0;
  vector<ll> stack{N - 1};
  vector ticked(N, 0LL);
  while (not stack.empty()) {
    ll x = stack.back(); stack.pop_back();
    for (ll y : bwd[x]) {
      updMax(rank[y], rank[x] + 1);
      ticked[y]++;
      if (ticked[y] == ssize(fwd[y])) stack.push_back(y);
    }
  }
  vector r_uniq(N, false);
  auto mycomp = [&](ll x, ll y) -> bool {
    if (rank[x] != rank[y]) return rank[x] < rank[y];
    return x < y;
  };
  set<ll, decltype(mycomp)> ss(mycomp);
  ss.insert(N - 1);
  while (not ss.empty()) {
    ll x = *ss.begin();
    ss.erase(ss.begin());
    if (ss.empty()) r_uniq[x] = true;
    for (ll y : bwd[x]) ss.insert(y);
  }
  REP(m, 0, M) {
    ll a = A[m], b = B[m];
    if (onR[a] and onR[b] and r_uniq[a] and r_uniq[b] and abs(rank[a] - rank[b]) == 1) {
      cout << "Yes\n";
    }else {
      cout << "No\n";
    }
  }


  return 0;
}

