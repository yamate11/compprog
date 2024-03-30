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
  auto solve = [&]() -> void {
    ll N, X; cin >> N >> X;
    // @InpVec(N, A) [ib6YbXDx]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [ib6YbXDx]

    ll ans = -1;
    REP(y, 0, 1LL << (N - 1)) {
      ll acc = 0;
      ll cur = 0;
      REP(i, 0, N) {
        cur ^= A[i];
        if (i == N - 1 or y >> i & 1) {
          acc |= cur;
          cur = 0;
        }
      }
      if (acc <= X) ans = max(ans, (ll)(1 + popcount((u64)y)));
    }
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}
int body(istream& cin, ostream& cout) {

  auto solve = [&]() -> void {
    ll N, X; cin >> N >> X;
    // @InpVec(N, A) [ib6YbXDx]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [ib6YbXDx]


    auto func = [&](auto rF, ll k, const auto& vec) -> ll {
      if (k == -1) {
        return ssize(vec);
      }
      vector<ll> newvec;
      ll mode = 0;
      ll acc = 0;
      REP(i, 0, ssize(vec)) {
        ll z = vec[i];
        if (mode == 0) {
          if (z >> k & 1) {
            mode = 1;
            acc = z;
          }else {
            newvec.push_back(z);
          }
        }else {
          acc ^= z;
          if (z >> k & 1) {
            newvec.push_back(acc);
            mode = 0;
          }else {
            ;
          }
        }
      }
      if (X >> k & 1) {
        ll res2 = rF(rF, k - 1, vec);
        if (mode == 1) return res2;
        else return max(res2, (ll)ssize(newvec));
      }else {
        if (mode == 1) return -1;
        ll res2 = rF(rF, k - 1, newvec);
        return res2;
      }
    };


    ll ans = func(func, 29, A);
    cout << ans << endl;

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

