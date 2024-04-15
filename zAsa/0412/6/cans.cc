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
  ll N, M; cin >> N >> M;
  // @InpMVec(M, ((X, dec=1), Y)) [6NgkQtS0]
  auto X = vector(M, ll());
  auto Y = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [6NgkQtS0]

  ll a0 = 0, e0 = 0;
  REP(i, 0, M) {
    e0 |= 1LL << X[i];
    if (Y[i] == 1) a0 |= 1LL << X[i];
  }
  vector tbl(1LL << N, vector(1LL << N, -1LL));
  auto f = [&](auto rF, ll a, ll e) -> bool {
    ll& r = tbl[a][e];
    if (r < 0) {
      auto g = [&]() -> bool {
        REP(i, 0, N) {
          if (not (e >> i & 1)) {
            REP(b, 0, 2) {
              bool cond1 = i > 0 and (e >> (i - 1) & 1) and (a >> (i - 1) & 1) == b;
              bool cond2 = i < N - 1 and (e >> (i + 1) & 1) and (a >> (i + 1) & 1) == b;
              if (not (cond1 or cond2)) {
                if (rF(rF, a | (b << i), e | (1LL << i))) return false;
              }
            }
          }
        }
        return true;
      };
      r = g();
    }
    return (bool)r;
  };
  cout << (f(f, a0, e0) ? "Aoki" : "Takahashi") << endl;
  

  return 0;
}
int body(istream& cin, ostream& cout) {

  ll N, M; cin >> N >> M;
  // @InpMVec(M, ((X, dec=1), Y)) [6NgkQtS0]
  auto X = vector(M, ll());
  auto Y = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [6NgkQtS0]
  bool takwin;
  if (M == 0) {
    takwin = N % 2 == 1;
  }else {
    ll cnt = 0;
    ll eL = 0, eR = 0;
    REP(i, 0, M - 1) if (Y[i] == Y[i + 1]) cnt++;
    if (X[0] == 1) cnt++;
    else if (X[0] >= 2) eL = X[0];
    if (X[M - 1] == N - 2) cnt++;
    else if (X[M - 1] <= N - 3) eR = N - 1 - X[M - 1];
    if (eL == 0 and eR == 0) takwin = cnt % 2 == 1;
    else if (eL > 0 and eR > 0) {
      if (cnt % 2 == 0) {
        if (eL == eR) takwin = cnt % 2 == 1;
        else takwin = true;
      }else {
        if (eL > eR) swap(eL, eR);
        if (eR == eL + 1 and eL % 2 == 0) takwin = false;
        else takwin = true;
      }
    }else takwin = true;
  }
  cout << (takwin ? "Takahashi" : "Aoki") << endl;

  return 0;
}

