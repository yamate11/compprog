#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(cmpNaive)
// --> cmpNaive
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
// @@ !! LIM  -- end mark --

int naive(istream& cin, ostream& cout) {
  ll n, k, M, D; cin >> n >> k >> M >> D;
  ll ans = -1;
  for (ll m = 1; m <= M; m++) {
    ll y = n / m;
    ll z = y / k;
    if (n - z * m * k >= m) z++;
    if (z > D) continue;
    ans = max(ans, z * m);
  }
  cout << ans << endl;

  return 0;
}
int body(istream& cin, ostream& cout) {

  ll n, k, M, D; cin >> n >> k >> M >> D;
  ll ans = -1;
  for (ll y = 1; y <= D; y++) {
    ll x = n / ((y - 1) * k + 1);
    if (x == 0) break;
    x = min(x, M);
    ans = max(ans, x * y);
  }
  cout << ans << endl;

  return 0;
}

