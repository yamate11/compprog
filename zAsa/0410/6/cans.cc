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
  auto check = [&](ll a, ll b, ll c, ll d) -> bool {
    vector<ll> vec(a + c + d + 1, false);
    ll x = a;
    while (true) {
      if (vec[x]) return true;
      vec[x] = true;
      if (x < b) return false;
      x -= b;
      if (x <= c) x += d;
    }
  };

  ll T; cin >> T;
  REP(t, 0, T) {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    if (check(a, b, c, d)) {
      cout << "Yes\n";
    }else {
      cout << "No\n";
    }
  }

  return 0;
}

int body(istream& cin, ostream& cout) {

  auto check = [&](ll a, ll b, ll c, ll d) -> bool {
    if (a < b) return false;
    if (d < b) return false;
    ll g = gcd(b, d);
    ll m = (a - c) % g;
    if (m == 0) m = g;
    return c + m >= b;
  };

  ll T; cin >> T;
  REP(t, 0, T) {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    if (check(a, b, c, d)) {
      cout << "Yes\n";
    }else {
      cout << "No\n";
    }
  }

  return 0;
}

