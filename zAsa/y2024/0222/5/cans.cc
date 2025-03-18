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

  auto func = [&](ll l0, ll r0) -> vector<ll> {
    vector<ll> ret{0};
    REP(i, l0, r0) {
      auto prev = move(ret);
      ret = vector<ll>();
      ll x = A[i];
      ll p = 0, q = 0;
      while (p < N or q < N) {
        if (p < N and prev[p] < prev[q] + x) ret.push_back(prev[p++]);
        else if (prev[q] + x <= T) ret.push_back(prev[q++] + x);
      }
    }
    sort(ALL(ret));
    return ret;
  };

  ll Ma = N / 2;
  auto C = func(0, Ma);
  auto D = func(Ma, N);
  ll q = ssize(D) - 1;
  ll ans = 0;
  for (ll y : C) {
    while (q >= 0 and y + D[q] > T) q--;
    if (q < 0) break;
    updMax(ans, y + D[q]);
  }


  cout << ans << endl;

  return 0;
}

