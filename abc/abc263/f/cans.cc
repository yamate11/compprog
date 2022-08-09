#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(cmpNaive f:updMaxMin)

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

// @@ !! LIM -- end mark --

int naive(istream& cin, ostream& cout) {
  ll N; cin >> N;
  ll M = 1LL << N;
  vector C(N, vector<ll>(M, 0LL));
  REP(i, M) REP(j, N) cin >> C[j][i];

  ll ans = 0;
  REP(x, 1LL << (M - 1)) {
    vector<ll> wincnt(M);
    vector<ll> cur(M);
    REP(i, M) cur[i] = i;
    ll gid = 0;
    REP(k, N) {
      auto prev = move(cur);
      cur = vector<ll>();
      REP(j, SIZE(prev) / 2) {
        ll w;
        if (x >> gid & 1) {
          w = prev[2*j];
        }else {
          w = prev[2*j + 1];
        }
        cur.push_back(w);
        wincnt[w]++;
        gid++;
      }
    }
    ll t = 0;
    REP(i, M) if (wincnt[i] > 0) t += C[wincnt[i] - 1][i];
    ans = max(ans, t);
  }
  cout << ans << endl;

  return 0;
}

int body(istream& cin, ostream& cout) {

  ll N; cin >> N;
  ll M = 1LL << N;
  vector C(N + 1, vector<ll>(M, 0LL));
  // D[k][i] is the maximum mark obtained in the `mount' of i when i wins k times.
  vector D(N + 1, vector<ll>(M, 0LL)); 
  // E[k][b] is only defined when b is a multiples of 1<<k.
  // It is the maximum value of (D[k][b], D[k][b + 1], ..., D[k][b + (1<<k) - 1])
  vector E(N + 1, vector<ll>(M, 0LL));
  REP(i, M) REP(j, N) cin >> C[j + 1][i];

  REP2(k, 1, N + 1) {
    ll w = 1LL << k, h = w / 2;
    for (ll b = 0; b < M; b += w) {
      E[k][b] = 0;
      REP(p, 2) REP(i, h) {
        ll i0 = b + p * h + i;
        D[k][i0] = C[k][i0] - C[k - 1][i0] + D[k - 1][i0] + E[k - 1][b + (1 - p) * h];
        updMax(E[k][b], D[k][i0]);
      }
    }
  }
  cout << E[N][0] << endl;

  return 0;
}

