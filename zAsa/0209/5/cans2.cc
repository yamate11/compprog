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
  ll A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
  
  double eps = 1e-8;

  double rmax = 0.0;
  ll sol = 100;
  ll sug = 0;
  REP(a, 0, 31) {
    if (100 * a * A > F) break;
    REP(b, 0, 31) {
      if (100 * a * A + 100 * b * B > F) break;
      if (a + b == 0) continue;
      REP(c, 0, 3001) {
        if (100 * a * A + 100 * b * B + c * C > F) break;
        REP(d, 0, 3001) {
          if (100 * a * A + 100 * b * B + c * C + d * D > F) break;
          if (c * C + d * D <= (a * A + b * B) * E) {
            double r = double(c * C + d * D) / (a * A + b * B);
            if (r > rmax + eps) {
              rmax = r;
              sug = c * C + d * D;
              sol = 100 * (a * A + b * B) + (c * C + d * D);
            }else if (r > rmax - eps) {
              if (sug > c * C + d * D) {
                sug = c * C + d * D;
                sol = 100 * (a * A + b * B) + (c * C + d * D);
              }
            }
          }
        }
      }
    }
  }
  cout << sol << " " << sug << endl;

  return 0;
}
int body(istream& cin, ostream& cout) {
  ll A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
  ll limW = 31, limS = 1501;
  vector water(limW, false);
  vector sugar(limS, false);
  REP(a, 0, limW) {
    if (a * A >= limW) break;
    REP(b, 0, limW) {
      if (a * A + b * B >= limW) break;
      water[a * A + b * B] = true;
    }
  }
  REP(c, 0, limS) {
    if (c * C >= limS) break;
    REP(d, 0, limS) {
      if (c * C + d * D >= limS) break;
      sugar[c * C + d * D] = true;
    }
  }
  double rmax = 0.0;
  ll sol = 100, sug = 0;
  REP(w, 1, limW) if (water[w]) {
    REP(s, 0, limS) if (sugar[s]) {
      if (s <= E * w and 100 * w + s <= F) {
        double r = double(100 * s) / (100 * w + s);
        if (r > rmax) {
          rmax = r;
          sug = s;
          sol = 100 * w + s;
        }
      }
    }
  }
  cout << sol << " " << sug << endl;

  return 0;
}

