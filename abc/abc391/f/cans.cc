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
  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [wCEHZYAT]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [wCEHZYAT]
  // @InpVec(N, B) [zUs7aHQl]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [zUs7aHQl]
  // @InpVec(N, C) [m0cR4BOV]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [m0cR4BOV]
  vector<ll> vals;
  REP(i, 0, N) REP(j, 0, N) REP(k, 0, N) {
    ll p = A[i], q = B[j], r = C[k];
    ll v = p * q + q * r + r * p;
    vals.push_back(v);
  }
  sort(ALL(vals), greater<ll>());
  cout << vals[K - 1] << endl;

  return 0;
}


template<typename T1, typename T2, typename T3, typename T4>
struct myTuple4 {
  T1 t1;
  T2 t2;
  T3 t3;
  T4 t4;
  myTuple4() : t1(), t2(), t3(), t4() {}
  myTuple4(const T1& t1_, const T2& t2_, const T3& t3_, const T4& t4_) : t1(t1_), t2(t2_), t3(t3_), t4(t4_) {}
  operator []
};



int body(istream& cin, ostream& cout) {
  ll N, K; cin >> N >> K;
  vector P(3, vector<ll>(N));
  REP(i, 0, 3) REP(j, 0, N) cin >> P[i][j];
  REP(i, 0, 3) sort(ALL(P[i]), greater<ll>());
  auto val = [&](ll a, ll b, ll c) -> ll {
    ll p = P[0][a], q = P[1][b], r = P[2][c];
    return q * r + r * p + p * q;
  };
  auto enc = [&](ll a, ll b, ll c) -> ll { return a + N * (b + N * c); };
  unordered_set<ll> ss;
  ss.insert(0);
  using sta = tuple<ll, ll, ll, ll>;
  priority_queue<sta> pque;
  pque.emplace(val(0, 0, 0), 0, 0, 0);
  while (true) {
    auto [v, a, b, c] = pque.top(); pque.pop();
    if (--K == 0) {
      cout << v << endl;
      return 0;
    }
    auto g = [&](ll a0, ll b0, ll c0) -> void {
      ll e = enc(a0, b0, c0);
      if (ss.contains(e)) return;
      ss.insert(e);
      pque.emplace(val(a0, b0, c0), a0, b0, c0);
    };
    if (a + 1 < N) g(a + 1, b, c);
    if (b + 1 < N) g(a, b + 1, c);
    if (c + 1 < N) g(a, b, c + 1);
  }
  return 0;
}

