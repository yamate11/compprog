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

// @@ !! LIM(f:intDiv cmpNaive binsearch)

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

// ---- inserted library file binsearch.cc

template <typename T>
requires integral<T>
T binsearch(auto check, T yes, T no) {
  while (abs(no - yes) > 1) {
    T mid = yes + (no - yes) / 2;  // avoiding unnecessary overflow
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

template <typename T>
requires floating_point<T>
T binsearch(auto check, T yes, T no, T err) {
  int rep = llround(ceil(log(abs(yes - no) / err) / log(2.0))) + 1;
  for (int r = 0; r < rep; r++) {
    T mid = (yes + no) / 2.0;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc

// @@ !! LIM -- end mark --

int naive(istream& cin, ostream& cout) {
  ll N, M; cin >> N >> M;
  // @InpMVec(M, (L, D, K, C, (A, dec=1), (B, dec=1))) [52oEJuBO]
  auto L = vector(M, ll());
  auto D = vector(M, ll());
  auto K = vector(M, ll());
  auto C = vector(M, ll());
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; L[i] = v1;
    ll v2; cin >> v2; D[i] = v2;
    ll v3; cin >> v3; K[i] = v3;
    ll v4; cin >> v4; C[i] = v4;
    ll v5; cin >> v5; v5 -= 1; A[i] = v5;
    ll v6; cin >> v6; v6 -= 1; B[i] = v6;
  }
  // @End [52oEJuBO]

  ll big = 2e18;
  REP(start, 0, N - 1) {
    auto check = [&](ll t0) -> bool {
      auto search = [&](auto rF, ll nd, ll visited, ll t) -> bool {
        if (nd == N - 1) return true;
        if (visited >> nd & 1) return false;
        REP(i, 0, M) {
          if (A[i] == nd) {
            ll j0 = divCeil(t0 - L[i], D[i]);
            if (j0 <= K[i] - 1) {
              if (rF(rF, B[i], visited | (1LL << nd), L[i] + D[i] * j0)) return true;
            }
          }
        }
        return false;
      };
      return search(search, start, 0, t0);
    };
    if (check(0)) {
      ll x = binsearch(check, 0LL, big);
      cout << x << "\n";
    }else {
      cout << "Unreachable\n";
    }
  }
  return 0;
}
int body(istream& cin, ostream& cout) {
  ll N, M; cin >> N >> M;
  // @InpMVec(M, (L, D, K, C, (A, dec=1), (B, dec=1))) [52oEJuBO]
  auto L = vector(M, ll());
  auto D = vector(M, ll());
  auto K = vector(M, ll());
  auto C = vector(M, ll());
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; L[i] = v1;
    ll v2; cin >> v2; D[i] = v2;
    ll v3; cin >> v3; K[i] = v3;
    ll v4; cin >> v4; C[i] = v4;
    ll v5; cin >> v5; v5 -= 1; A[i] = v5;
    ll v6; cin >> v6; v6 -= 1; B[i] = v6;
  }
  // @End [52oEJuBO]

  vector info(N, vector<ll>());
  REP(i, 0, M) info[B[i]].push_back(i);

  priority_queue<pll> pque;
  ll big = 4e18;
  vector time(N, -big);
  time[N - 1] = big;
  pque.emplace(big, N - 1);
  while (not pque.empty()) {
    auto [tt, nd] = pque.top(); pque.pop();
    if (time[nd] == tt) {
      for (ll idx : info[nd]) {
        ll peer = A[idx];
        ll j0 = divFloor(tt - L[idx], D[idx]);
        if (j0 >= K[idx] - 1) j0 = K[idx] - 1;
        if (j0 >= 0) {
          ll new_tt = L[idx] + j0 * D[idx];
          if (new_tt > time[peer]) {
            time[peer] = new_tt;
            pque.emplace(new_tt, peer);
          }
        }
      }
    }
  }

  REP(i, 0, N - 1) {
    if (time[i] < 0) cout << "Unreachable\n";
    else cout << time[i] << "\n";
  }

  return 0;
}

