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
  ll N, K, M, R; cin >> N >> K >> M >> R;
  // @InpVec(N - 1, S) [745UaRoS]
  auto S = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) { ll v; cin >> v; S[i] = v; }
  // @End [745UaRoS]

  const ll big = 1e18;
  ll ans = big;
  REP(i, 0, M + 1) {
    auto vec = S;
    vec.push_back(i);
    sort(ALL(vec), greater<ll>());
    ll sum = 0;
    REP(j, 0, K) sum += vec[j];
    if (sum >= R * K) ans = min(ans, i);
  }
  if (ans == big) ans = -1;
  cout << ans << endl;
  

  return 0;
}

int body(istream& cin, ostream& cout) {
  ll N, K, M, R; cin >> N >> K >> M >> R;
  // @InpVec(N - 1, S) [745UaRoS]
  auto S = vector(N, ll());
  for (int i = 0; i < N - 1; i++) { ll v; cin >> v; S[i] = v; }
  // @End [745UaRoS]
  sort(ALL(S), greater<ll>());
  ll goal = R * K;
  ll ans;
  ll sum = 0; REP(i, 0, K - 1) sum += S[i];
  if (sum + M < goal) ans = -1;
  else if (sum + S[K - 1] >= goal) ans = 0;
  else ans = goal - sum;
  cout << ans << endl;

  return 0;
}

