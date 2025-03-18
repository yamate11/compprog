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
  ll N, Q; cin >> N >> Q;
  vector<string> S(N);
  vector<ll> P(N);
  REP(i, 0, N) {
    cin >> S[i];
    cin >> P[i];
  }
  REP(_q, 0, Q) {
    ll q; cin >> q;
    REP(i, 0, N) {
      if (S[i] == "NEGATE") q = -q;
      else if (S[i] == "CHMIN") q = min(q, P[i]);
      else if (S[i] == "CHMAX") q = max(q, P[i]);
    }
    cout << q << "\n";
  }
  
  return 0;
}
int body(istream& cin, ostream& cout) {

  ll N, Q; cin >> N >> Q;
  ll big = 1e18;
  ll lo = -big, hi = big;
  ll parity = 0;
  REP(i, 0, N) {
    string s; cin >> s;
    ll p; cin >> p;
    if (s == "NEGATE") {
      parity = 1 - parity;
    }else if (s == "CHMIN") {
      if (parity) {
        p = -p;
        if (p <= hi) lo = max(lo, p);
        else lo = hi = p;
      }else {
        if (lo <= p) hi = min(hi, p);
        else lo = hi = p;
      }
    }else if (s == "CHMAX") {
      if (parity) {
        p = -p;
        if (lo <= p) hi = min(hi, p);
        else lo = hi = p;
      }else {
        if (p <= hi) lo = max(lo, p);
        else lo = hi = p;
      }
    }else assert(0);
  }
  REP(_q, 0, Q) {
    ll q; cin >> q;
    if (q <= lo) q = lo;
    else if (hi <= q) q = hi;
    if (parity) q = -q;
    cout << q << "\n";
  }
  return 0;
}

