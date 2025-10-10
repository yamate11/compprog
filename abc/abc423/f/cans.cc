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

// @@ !! LIM(fastTransform cmpNaive)

// ---- inserted library file fastTransform.cc

template <typename T>
int trans_resize(vector<T>& x, vector<T>& y) {
  int n = max(x.size(), y.size());
  int p = 31 - __builtin_clz(n);
  int t = 1 << p;
  if (n > t) t *= 2;
  x.resize(t);
  y.resize(t);
  return t;
}

template<typename T>
int trans_resize(vector<T>& x) { return trans_resize(x, x); }

template<typename T, int p1, int p2, int p3, int p4, int div>
void _trans_form(vector<T>& f) {
  int n = f.size();
  for (int i = 1; i < n; i *= 2) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        T x = f[j];
        T y = f[j | i];
        f[j    ] = (p1 * x + p2 * y) / div;
        f[j | i] = (p3 * x + p4 * y) / div;
      }
    }
  }
}

template <typename T>
void hadamard(vector<T>& f) { _trans_form<T, 1, 1, 1, -1, 1>(f); }

template <typename T>
void inv_hadamard(vector<T>& f) { _trans_form<T, 1, 1, 1, -1, 2>(f); }

template<typename T>
void zeta_upper(vector<T>& f) { _trans_form<T, 1, 1, 0, 1, 1>(f); }

template<typename T>
void moebius_upper(vector<T>& f) { _trans_form<T, 1, -1, 0, 1, 1>(f); }

template<typename T>
void zeta_lower(vector<T>& f) { _trans_form<T, 1, 0, 1, 1, 1>(f); }

template<typename T>
void moebius_lower(vector<T>& f) { _trans_form<T, 1, 0, -1, 1, 1>(f); }

template<typename T>
void _conv_dest_form(vector<T>& x, vector<T>& y,
                     void fwd(vector<T>&), void bwd(vector<T>&)) {
  int t = trans_resize(x, y);
  fwd(x);
  fwd(y);
  for (int i = 0; i < t; i++) x[i] *= y[i];
  bwd(x);
}

template<typename T>
void xor_conv_dest(vector<T>& x, vector<T>& y) {
  _conv_dest_form(x, y, hadamard, inv_hadamard);
}

template<typename T>
void and_conv_dest(vector<T>& x, vector<T>& y) {
  _conv_dest_form(x, y, zeta_upper, moebius_upper);
}

template<typename T>
void or_conv_dest(vector<T>& x, vector<T>& y) {
  _conv_dest_form(x, y, zeta_lower, moebius_lower);
}

template <typename T>
vector<T> xor_conv(vector<T> x, vector<T> y) {
  xor_conv_dest(x, y);
  return x;
}

template <typename T>
vector<T> and_conv(vector<T> x, vector<T> y) {
  and_conv_dest(x, y);
  return x;
}

template <typename T>
vector<T> or_conv(vector<T> x, vector<T> y) {
  or_conv_dest(x, y);
  return x;
}

// ---- end fastTransform.cc

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
  ll N, M, Y; cin >> N >> M >> Y;
  // @InpVec(N, A) [lsI1YkpR]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [lsI1YkpR]

  vector<ll> cnt(Y + 1);
  REP(i, 0, N) {
    REP(j, 1, Y + 1) {
      ll x = A[i] * j;
      if (x > Y) break;
      cnt[x]++;
    }
  }
  ll ans = 0;
  REP(i, 1, Y + 1) if (cnt[i] == M) ans++;
  cout << ans << endl;

  return 0;
}
int body(istream& cin, ostream& cout) {

  ll N1, M, Y; cin >> N1 >> M >> Y;
  // @InpVec(N1, A1) [lsI1YkpR]
  auto A1 = vector(N1, ll());
  for (int i = 0; i < N1; i++) { ll v; cin >> v; A1[i] = v; }
  // @End [lsI1YkpR]

  map<ll, ll> mp;
  REP(i, 0, N1) mp[A1[i]]++;
  vector<ll> A(N1);
  {
    ll j = 0;
    for (auto [a, n] : mp) {
      A[j] = a;
      j++;
    }
  }
  ll N = ssize(mp);
  A.resize(N);

  vector<ll> v_lcm(1LL << N);
  vector<ll> B(1LL << N);
  REP(x, 0, 1LL << N) {
    if (x == 0) continue;
    ll s = bit_width((u64)x) - 1;
    if (popcount((u64)x) == 1) {
      v_lcm[x] = A[s];
      B[x] = Y / A[s];
    }else {
      ll masked = ((1LL << s) - 1) & x;
      if (v_lcm[masked] > Y) v_lcm[x] = Y + 1;
      else {
        ll g = gcd(A[s], v_lcm[masked]);
        if (v_lcm[masked] / g <= Y / A[s]) {
          v_lcm[x] = v_lcm[masked] / g * A[s];
        }else {
          v_lcm[x] = Y + 1;
        }
      }
      B[x] = Y / v_lcm[x];
    }
  }
  moebius_upper(B);
  ll ans = 0;
  REP(x, 0, 1LL << N) {
    ll t = 0;
    REP(i, 0, N) if (x >> i & 1) t += mp[A[i]];
    if (t == M) ans += B[x];
  }
  cout << ans << endl;
  return 0;
}

