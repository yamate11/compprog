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
  vector vec(100, vector<char>());
  ll H = 0, W = 0;
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      char c; cin >> c;
      vec[H].insert(vec[H].begin() + W, c);
      W++;
    }else if (tp == 2) {
      W = 0;
    }else if (tp == 3) {
      H++;
      W = 0;
    }else assert(0);
  }
  cout << H + 1 << " " << W + 1 << endl;
  REP(r, 0, H + 1) {
    cout << "# ";
    for (char c : vec[r]) cout << c;
    cout << "\n";
  }

  return 0;
}
int body(istream& cin, ostream& cout) {

  ll Q; cin >> Q;
  vector<vector<string>> vec;
  vec.push_back(vector<string>());
  vec[0].push_back(string());
  ll i = 0, j = 0;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      char c; cin >> c;
      vec[i][j].push_back(c);
    }else if (tp == 2) {
      vec[i].push_back(string());
      j++;
    }else if (tp == 3) {
      vec.push_back(vector<string>());
      i++;
      vec[i].push_back(string());
      j = 0;
    }
  }
  cout << ssize(vec) << " " << ssize(vec[i].back()) + 1 << endl;
  for (auto& line : vec) {
    cout << "# ";
    REPrev(k, ssize(line) - 1, 0) cout << line[k];
    cout << "\n";
  }

  return 0;
}

