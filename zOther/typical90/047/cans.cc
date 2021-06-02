#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(strSearch f:intDiv cmpNaive)

// ---- inserted library file strSearch.cc
vector<int> zAlg(string s) {
  int n = s.size();
  vector<int> z(n);
  z.at(0) = n;
  int i = 1;
  int j = 0;
  while (i < n) {
    for ( ; i+j < n && s.at(j) == s.at(i+j); j++) {}
    z.at(i++) = j;
    if (j > 0) {
      for (int k = 1; i < n && z.at(k) < j-1; k++, j--, i++) z.at(i) = z.at(k);
      j--;
    }
  }
  return z;
}

// matches("abab", "xababab") --> [1,3]
vector<int> matches(string p, string s, char sepChar = '\xff') {
  auto v = zAlg(p + string(1, sepChar) + s);
  int n = p.size();
  vector<int> res;
  for (size_t i = 0; i < s.size() - (n-1); i++) {
    if (v.at(n+1 + i) == n) res.push_back(i);
  }
  return res;
}
// ---- end strSearch.cc

// ---- inserted function f:intDiv from util.cc
// imod, divFloor, divCeil

// imod(x, y) : remainder of x for y
// for y > 0:
//   imod(x, y)  = r where x = dy + r, 0 <= r < y
//   imod(x, -y) = r where x = dy + r, 0 >= r > y
// Thus, imod( 10,  7) =  3
//       imod(-10,  7) =  4
//       imod( 10, -7) = -4
//       imod(-10, -7) = -3
ll imod(ll x, ll y) {
  ll v = x % y;
  if ((x >= 0) == (y >= 0)) return v;
  else                      return v == 0 ? 0 : v + y;
}

// Integer Division; regardless pos/neg
ll divFloor(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return x / y;
    else       return (x - y - 1) / y;
  }else {
    if (y > 0) return (x - y + 1) / y;
    else       return x / y;
  }
}

ll divCeil(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return (x + y - 1) / y;
    else       return x / y;
  }else {
    if (y > 0) return x / y;
    else       return (x + y + 1) / y;
  }
}
//   Just a note.  For d \in Z and t \in R,
//       d < t <=> d < ceil(t),     d <= t <=> d <= floor(t),
//       d > t <=> d > floor(t),    d >= t <=> d >= ceil(t).

// ---- end f:intDiv

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

ll enc (char c) {
  if (c == 'R') return 0;
  if (c == 'G') return 1;
  if (c == 'B') return 2;
  assert(0);
}

pair<string, string> mkdiff(string s) {
  string r0;
  string r1;
  for (ll i = 0; i+1 < (ll)s.size(); i++) {
    ll e0 = imod(enc(s[i+1]) - enc(s[i]), 3);
    ll e1 = imod(-e0, 3);
    r0 += '0' + e0;
    r1 += '0' + e1;
  }
  return {r0, r1};
}

int naive(istream& cin, ostream& cout) {
  ll N; cin >> N;
  string S, T; cin >> S >> T;

  auto tbl = vector(N, vector(N, '.'));
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      if (S[i] == T[j]) {
        tbl[i][j] = S[i];
      }else {
        vector<bool> chk(128);
        chk[S[i]] = true;
        chk[T[j]] = true;
        if (!chk['R']) tbl[i][j] = 'R';
        else if (!chk['G']) tbl[i][j] = 'G';
        else if (!chk['B']) tbl[i][j] = 'B';
        else assert(0);
      }
    }
  }
  ll cnt = 0;
  for (ll k = -(N - 1); k <= (N - 1); k++) {
    char c = '.';
    bool succ = true;
    for (ll i = 0; i < N; i++) {
      if (0 <= i + k && i + k < N) {
        if (c == '.') {
          c = tbl[i][i + k];
        }else {
          if (c != tbl[i][i + k]) {
            succ = false;
            break;
          }
        }
      }
    }
    if (succ) cnt++;
  }
  cout << cnt << endl;


  return 0;
}
int body(istream& cin, ostream& cout) {

  ll N; cin >> N;
  string S, T; cin >> S >> T;
  if (N == 1) {
    cout << "1\n";
    return 0;
  }

  auto [s0, s1] = mkdiff(S);
  auto [t0, t1] = mkdiff(T);
  auto vt = zAlg(s1 + '$' + t0);
  auto vs = zAlg(t1 + '$' + s0);
  ll cnt = 2;
  for (ll i = 0; i < N - 1; i++) {
    if (vt[N + i] >= N - 1 - i) cnt++;
    if (i == 0) continue;
    if (vs[N + i] >= N - 1 - i) cnt++;
  }
  cout << cnt << endl;
  return 0;
}

