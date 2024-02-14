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

// @@ !! LIM(cmpNaive f:intDiv)

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

// @@ !! LIM -- end mark --

int naive(istream& cin, ostream& cout) {
  ll N, X; cin >> N >> X;
  // @InpVec(N, A) [fy5KrnLY]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [fy5KrnLY]

  ll tot = accumulate(ALL(A), 0LL);
  ll full = (1LL << N) - 1;
  queue<pll> que;
  que.emplace(0, 0);
  ll ans = tot;
  while (not que.empty()) {
    auto [t, x] = que.front(); que.pop();
    if (t >= ans) continue;
    if (x == full) ans = min(ans, t);
    else {
      REP(i, 0, N) if (not (x >> i & 1)) {
        ll y = x | (1LL << i);
        ll new_t = t + A[i];
        if (new_t < ans) que.emplace(new_t, y);
      }
      ll y = ((x << 1) & full) | ((x >> (N - 1)) & 1);
      ll new_t = t + X;
      if (new_t < ans) que.emplace(new_t, y);
    }
  }
  cout << ans << endl;

  return 0;
}

int body(istream& cin, ostream& cout) {
  ll N, X; cin >> N >> X;
  // @InpVec(N, A) [fy5KrnLY]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [fy5KrnLY]

  ll i0 = min_element(ALL(A)) - A.begin();
  vector B(N, 0LL);

  vector<ll> st;
  st.push_back(i0);
  REP(_i, 1, N + 1) {
    ll i = imod(i0 - _i, N);
    ll prev = 0;
    while (not st.empty()) {
      ll pos = st.back();
      ll cur = A[pos] - A[i];
      if (A[i] > A[pos]) {
        B[imod(pos - i, N)] += 0 - prev;
        break;
      }
      B[imod(pos - i, N)] += cur - prev;
      prev = cur;
      st.pop_back();
    }
    st.push_back(i);
  }
  
  ll s = accumulate(ALL(A), 0LL);
  ll ans = s;
  ll d = 0;
  REP(i, 1, N) {
    d += B[i];
    s -= d;
    ans = min(ans, s + i * X);
  }
  cout << ans << endl;

  return 0;
}

