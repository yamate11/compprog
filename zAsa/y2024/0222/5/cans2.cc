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

  ll N, T; cin >> N >> T;
  // @InpVec(N, A) [NfiHnI2i]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [NfiHnI2i]

  ll ans = 0;
  REP(x, 0, 1LL << N) {
    ll s = 0;
    REP(i, 0, N) if (x >> i & 1)  s += A[i];
    if (s <= T) ans = max(ans, s);
  }
  cout << ans << endl;

  return 0;
}

int body(istream& cin, ostream& cout) {

  ll N, T; cin >> N >> T;
  // @InpVec(N, A) [NfiHnI2i]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [NfiHnI2i]

  if (N == 1) {
    if (A[0] <= T) { cout << A[0] << endl; }
    else { cout << 0 << endl; }
    return 0;
  }
  set<ll> ss{0};
  ll Ma = N / 2;
  ll Mb = N - Ma;
  vector<ll> tblA(1<< Ma, 0LL);
  vector<ll> tblB(1<< Mb, 0LL);
  REP(x, 1, 1 << Ma) {
    ll w = bit_width((u64)x);
    ll s = tblA[x] = A[w - 1] + tblA[x ^ (1LL << (w - 1))];
    if (s <= T) ss.insert(s);
  }
  ll ans = 0;
  if (not ss.empty()) ans = *(prev(ss.end()));
  REP(x, 1, 1 << Mb) {
    ll w = bit_width((u64)x);
    ll s = tblB[x] = A[Ma + (w - 1)] + tblB[x ^ (1LL << (w - 1))];
    auto it = ss.lower_bound(T - s);
    if (it != ss.end() and *it == T - s) {
      ans = T;
      break;
    }
    if (it != ss.begin()) {
      it--;
      ans = max(ans, *it + s);
    }
  }
  cout << ans << endl;

  return 0;
}

