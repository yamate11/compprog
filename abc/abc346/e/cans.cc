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

// @@ !! LIM(cmpNaive)

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
  ll H, W, M; cin >> H >> W >> M;
  // @InpMVec(M, (T, (A, dec=1), X)) [MS3Bc3uD]
  auto T = vector(M, ll());
  auto A = vector(M, ll());
  auto X = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; T[i] = v1;
    ll v2; cin >> v2; v2 -= 1; A[i] = v2;
    ll v3; cin >> v3; X[i] = v3;
  }
  // @End [MS3Bc3uD]

  vector brd(H, vector(W, 0LL));
  REP(i, 0, M) {
    if (T[i] == 1) {
      REP(j, 0, W) brd[A[i]][j] = X[i];
    }else {
      REP(j, 0, H) brd[j][A[i]] = X[i];
    }
  }
  ll xmax = 2e5;
  vector ans(xmax + 1, 0LL);
  REP(i, 0, H) REP(j, 0, W) ans[brd[i][j]]++;
  ll num = 0;
  REP(i, 0, xmax + 1) if (ans[i] > 0) num++;
  cout << num << "\n";
  REP(i, 0, xmax + 1) if (ans[i] > 0) cout << i << " " << ans[i] << "\n";
  


  return 0;
}

int body(istream& cin, ostream& cout) {

  ll H, W, M; cin >> H >> W >> M;
  // @InpMVec(M, (T, (A, dec=1), X)) [MS3Bc3uD]
  auto T = vector(M, ll());
  auto A = vector(M, ll());
  auto X = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; T[i] = v1;
    ll v2; cin >> v2; v2 -= 1; A[i] = v2;
    ll v3; cin >> v3; X[i] = v3;
  }
  // @End [MS3Bc3uD]

  ll xmax = 2e5;
  
  vector seenR(H, false);
  vector seenC(W, false);
  ll numSeenR = 0;
  ll numSeenC = 0;
  vector ans(xmax + 1, 0LL);
  REPrev(i, M - 1, 0) {
    if (T[i] == 1) {
      if (seenR[A[i]]) continue;
      seenR[A[i]] = true;
      numSeenR++;
      ans[X[i]] += W - numSeenC;
    }else {
      if (seenC[A[i]]) continue;
      seenC[A[i]] = true;
      numSeenC++;
      ans[X[i]] += H - numSeenR;
    }
  }
  ans[0] = H * W;
  REP(i, 1, xmax + 1) ans[0] -= ans[i];
  ll num = 0;
  REP(i, 0, xmax + 1) if (ans[i] > 0) num++;
  cout << num << endl;
  REP(i, 0, xmax + 1) if (ans[i] > 0) cout << i << " " << ans[i] << "\n";
  
  return 0;
}
