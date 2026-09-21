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

// @@ !! LIM(cmpNaive forall)

// ---- inserted library file cmpNaive.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/cmpNaive.cc

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

// ---- inserted library file forall.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/forall.cc

#define EX_REP_LL(i, from, to) for (ll i = (from); i < (to); i++)
#define EX_REP_RB(x, coll) for (auto x : coll)
#define EXGEN(rep_part, cond, yes, no_behaviour) ([&]() { rep_part if (cond) return (yes); no_behaviour; }())
#define EXISTS_BASE(rep_part, cond) EXGEN(rep_part, cond, true, return false)
#define EXFIND_BASE(rep_part, cond, t) EXGEN(rep_part, cond, t, assert(0))
#define EXFIND_D_BASE(rep_part, cond, t, def) EXGEN(rep_part, cond, t, return def)

#define EXISTS(i, from, to, cond) EXISTS_BASE(EX_REP_LL(i, from, to), cond)
#define FORALL(i, from, to, cond) (not EXISTS(i, from, to, not (cond)))
#define EXFIND(i, from, to, cond) EXFIND_BASE(EX_REP_LL(i, from, to), cond, i)
#define EXFIND_D(i, from, to, cond, def) EXFIND_D_BASE(EX_REP_LL(i, from, to), cond, i, def)

#define EXISTS_C(x, coll, cond) EXISTS_BASE(EX_REP_RB(x, coll), cond)
#define FORALL_C(x, coll, cond) (not EXISTS_C(x, coll, not (cond)))
#define EXFIND_C(x, coll, cond) EXFIND_BASE(EX_REP_RB(x, coll), cond, x)
#define EXFIND_D_C(x, coll, cond, def) EXFIND_D_BASE(EX_REP_RB(x, coll), cond, x, def)

#define COUNT_BASE(rep_part, cond) ([&](){ ll ret = 0; rep_part if (cond) ret++; return ret; }())
#define COUNT(i, from, to, cond) COUNT_BASE(EX_REP_LL(i, from, to), cond)
#define COUNT_C(x, coll, cond) COUNT_BASE(EX_REP_RB(x, coll), cond)

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

// @@ !! LIM -- end mark --

int naive(istream& cin, ostream& cout) {
  
  auto solve = [&]() -> void {
    ll N, K; cin >> N >> K;
    string bodyans1; cin >> bodyans1;
    if (bodyans1 == "No") {
      cout << "OK\n";
      return;
    }
    string bodyans2; cin >> bodyans2;
    assert(ssize(bodyans2) == N * N - 1);
    vector visited(N, vector(N, false));
    visited[0][0] = true;
    ll i = 0, j = 0;
    ll cnt = 0;
    for (char c : bodyans2) {
      if (c == 'R') {
        cnt++;
        j++;
      }else if (c == 'L') {
        j--;
      }else if (c == 'D') {
        i++;
      }else if (c == 'U') {
        i--;
      }else assert(0);
      assert(0 <= i and i < N and 0 <= j and j < N);
      visited[i][j] = true;
    }
    if (cnt != K or EXISTS(a, 0, N, EXISTS(b, 0, N, not visited[a][b])) or i != N - 1 or j != N - 1) {
      cout << "NG\n";
      return;
    }
    cout << "OK\n";

  };

  ll T; cin >> T;
  REP(t, 0, T) solve();
  return 0;

}
int body(istream& cin, ostream& cout) {

  auto mn = [&](ll m, ll  ) { return m - 1; };
  auto mx = [&](ll m, ll n) { return (m - 1) * (n + 1) / 2; };

  auto f = [&](auto rF, ll m, ll n, ll k) -> string {
    if (mn(m, n) == k) {
      string ret;
      REP(i, 0, m) {
        if (i % 2 == 0) ret += string(n - 1, 'D');
        else            ret += string(n - 1, 'U');
        if (i < m - 1) ret += 'R';
      }
      assert(ssize(ret) == m * n - 1);
      return ret;
    }else if (mx(m, n) == k) {
      string ret;
      REP(i, 0, n) {
        if (i % 2 == 0) ret += string(m - 1, 'R');
        else            ret += string(m - 1, 'L');
        if (i < n - 1) ret += 'D';
      }
      assert(ssize(ret) == m * n - 1);
      return ret;
    }
    if (mn(m, n - 2) <= k - (m - 1) and k - (m - 1) <= mx(m, n - 2)) {
      string ret = string(m - 1, 'R');
      ret += 'D';
      ret += string(m - 1, 'L');
      ret += 'D';
      ret += rF(rF, m, n - 2, k - (m - 1));
      assert(ssize(ret) == m * n - 1);
      return ret;
    }else {
      assert(mn(m - 2, n) <= k - 2 and k - 2 <= mx(m - 2, n));
      string ret = string(n - 1, 'D');
      ret += 'R';
      ret += string(n - 1, 'U');
      ret += 'R';
      ret += rF(rF, m - 2, n, k - 2);
      assert(ssize(ret) == m * n - 1);
      return ret;
    }
  };

  auto solve = [&]() -> void {
    ll N, K; cin >> N >> K;
    if (N % 2 == 0 or K % 2 != 0
        or not (N - 1 <= K and K <= (N + 1) * (N - 1) / 2)) {
      cout << "No\n";
      return;
    }
    cout << "Yes\n";
    cout << f(f, N, N, K) << "\n";
  };

  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

