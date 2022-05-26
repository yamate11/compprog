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
  auto solve = [&]() -> ll {
    ll n, a, b, x, y, z; cin >> n >> a >> b >> x >> y >> z;
    ll ans = LLONG_MAX;
    REP(i, n / a + 1) {
      REP(j, (n - a * i) / b + 1) {
        ll k = n - (a * i + b * j);
        ll cost = i * y + j * z + k * x;
        ans = min(ans, cost);
      }
    }
    return ans;
  };

  ll T; cin >> T;
  REP(t, T) cout << solve() << "\n";
  return 0;
}
int body(istream& cin, ostream& cout) {

  auto solve = [&]() -> ll {
    ll n, a, b, x, y, z; cin >> n >> a >> b >> x >> y >> z;
    if (y * b > z * a) { swap(a, b); swap(y, z); }
    if (x * a <= y) return x * n;
    if (x * b <= z) return (n / a) * y + (n % a) * x;
    ll ans = LLONG_MAX;
    ll g = gcd(a, b);
    REP2R(i, n / a, 0) {
      ll rem = n - a * i;
      ll cost = i * y + (rem / b) * z + (rem % b) * x;
      ans = min(ans, cost);
      if (rem % b < g) return ans;
    }
    return ans;
  };

  ll T; cin >> T;
  REP(t, T) cout << solve() << "\n";
  return 0;
}

