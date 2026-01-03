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
  auto solve = [&]() -> ll {
    ll N, A, B, X, Y, Z; cin >> N >> A >> B >> X >> Y >> Z;

    ll big = 1e18;
    ll ans = big;
    for (ll a = 0; true; a++) {
      if (a * A > N) break;
      for (ll b = 0; true; b++) {
        if (a * A + b * B > N) break;
        updMin(ans, a * Y + b * Z + (N - a * A - b * B) * X);
      }
    }
    return ans;
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}
int body(istream& cin, ostream& cout) {

  auto solve = [&]() -> ll {
    ll big = 1e18;
    ll N, A, B, X, Y, Z; cin >> N >> A >> B >> X >> Y >> Z;
    ll lim = llround(sqrt(N));
    if (X * A <= Y and X * B <= Z) return X * N;
    if (X * A <= Y) {
      ll p = N / B;
      ll q = N % B;
      return p * Z + q * X;
    }
    if (X * B <= Z) {
      ll p = N / A;
      ll q = N % A;
      return p * Y + q * X;
    }
    auto f = [&](ll num1, ll cost1, ll num2, ll cost2, ll size) -> ll {
      ll ret = big;
      REP(i, 0, size) {
        ll rem = N - i * num1;
        updMin(ret, i * cost1 + (rem / num2) * cost2 + (rem % num2) * X);
      }
      return ret;
    };

    if (A >= lim) return f(A, Y, B, Z, N / A + 1);
    if (B >= lim) return f(B, Z, A, Y, N / B + 1);
    if (Y * B <= Z * A) return f(B, Z, A, Y, A);
    else                return f(A, Y, B, Z, B);
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

