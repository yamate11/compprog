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

// @@ !! LIM(digit cmpNaive)

// ---- inserted library file digit.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/digit.cc

struct digit_error : runtime_error {
  digit_error(const string& msg) : runtime_error(msg) {}
};

struct digit_util {
  const ll base;
  const vector<ll> _pow;

  static vector<ll> _make_pow(ll b) {
    vector<ll> ret;
    ll t = 1;
    while (true) {
      ret.push_back(t);
      if (__builtin_smulll_overflow(t, b, &t)) break;
    }
    return ret;
  };

  void range_error(string meth, ll param) const {
    throw digit_error(format("digit.{}: parameter {} out of range", meth, param));
  }

#if DEBUG
  ll zero_warning(string meth, bool quiet) const {
    if (not quiet) {
      cerr << format("You called {} with parameter 0.  It returns 0.  If this is OK, considter quiet=true.", meth)
           << endl;
    }
    return 0;
  }
#else
  ll zero_warning(string, bool) const { return 0; }
#endif

  digit_util(ll base_ = 10) : base(base_), _pow(_make_pow(base_)) {}
    
  ll pow_size() const { return _pow.size(); }
  ll pow(ll i) const {
    if (i < 0 or ssize(_pow) <= i) range_error("pow", i);
    return _pow[i];
  }

  ll width(ll x, bool quiet = false) const {
    if (x < 0) range_error("width", x);
    if (base == 2) return bit_width((unsigned long long)x);
    if (x == 0) return zero_warning("width", quiet);
    ll ret = 0;
    for (; x != 0; x /= base) ret++;
    return ret;
  }

  ll nd_min(ll i, bool quiet = false) const {
    if (i < 0) range_error("nd_min", i);
    if (i == 0) return zero_warning("nd_min", quiet);
    return pow(i - 1);
  }
  ll nd_max(ll i, bool quiet = false) const {
    if (i < 0) range_error("nd_max", i);
    if (i == 0) return zero_warning("nd_max", quiet);
    return nd_min(i + 1) - 1;
  }

  ll floor(ll x, bool quiet = false) const {
    if (x < 0) range_error("floor", x);
    if (x == 0) return zero_warning("floor", quiet);
    return pow(width(x) - 1);
  }
  ll ceil(ll x, bool quiet = false) const {
    if (x < 0) range_error("ceil", x);
    if (x == 0) return zero_warning("ceil", quiet);
    ll p = pow(width(x) - 1);
    return x == p ? p : pow(width(x));
  }

  ll log(ll x) const {
    if (x <= 0) range_error("log", x);
    return width(x) - 1;
  }

  ll d_at(ll x, ll i) const {
    if (x < 0) range_error("d_at", x);
    if (x == 0) return 0;
    if (i < 0) i += width(x);
    return (x / pow(i)) % base;
  }

  ll d_sub(ll x, ll pos, ll len) const {
    if (x < 0) range_error("d_sub", x);
    if (x == 0) return 0;
    ll w = width(x);
    if (pos < 0) pos += w;
    if (len < 0) { len = -len; pos = pos - len + 1; }
    if (pos < 0) { len += pos; pos = 0; }
    if (pos + len > w) len = w - pos;
    return (x % pow(pos + len)) / pow(pos);
  }

  template<bool big_endian>
  vector<ll> _gen_to_vector(ll x) const {
    if (x < 0) range_error("to_vector", x);
    if (x == 0) return vector<ll>{0};
    ll w = width(x);
    vector<ll> ret(w);
    for (int i = 0; i < w; i++) {
      if constexpr (big_endian) ret[w - 1 - i] = x % base;
      else                      ret[i]         = x % base;
      x /= base;
    }
    return ret;
  }
  vector<ll> to_vector(ll x) const { return _gen_to_vector<false>(x); }
  vector<ll> to_vector_big_endian(ll x) const { return _gen_to_vector<true>(x); }

  template<bool big_endian>
  ll _gen_from_vector(const auto& vec) const {
    ll ret = 0;
    for (ll i = 0; i < ssize(vec); i++) {
      ll j;
      if constexpr (big_endian) j = ssize(vec) - 1 - i; else j = i;
      ret += vec[j] * pow(i);
    }
    return ret;
  }
  ll from_vector(const auto& vec) const { return _gen_from_vector<false>(vec); }
  ll from_vector_big_endian(const auto& vec) const { return _gen_from_vector<true>(vec); }

  string to_string(ll x, bool upcase = false) const {
    if (x < 0) range_error("to_string", x);
    if (x == 0) return string("0");
    char ten = upcase ? 'A' : 'a';
    ll w = width(x);
    string ret(w, ' ');
    for (ll i = w - 1; x != 0; x /= base, i--) {
      ll y = x % base;
      ret[i] = y < 10 ? '0' + y : ten + (y - 10);
    }
    return ret;
  }

  string to_string_padding(ll x, ll width, char c = '0', bool upcase = false) const {
    string s = to_string(x, upcase);
    if (ssize(s) >= width) return s;
    return string(width - ssize(s), c) + s;
  }

  static ll _get_digit_char(char c) {
    if ('0' <= c and c <= '9')      return c - '0';
    else if ('a' <= c and c <= 'z') return c - 'a' + 10;
    else if ('A' <= c and c <= 'Z') return c - 'A' + 10;
    else throw runtime_error("_get_digit_char: unknown letter");
  }

  ll from_string(string s) const {
    ll ret = 0;
    for (ll i = 0; i < ssize(s); i++) ret += _get_digit_char(s[i]) * pow(ssize(s) - 1 - i);
    return ret;
  }


};

// ---- end digit.cc

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

// @@ !! LIM -- end mark --

int naive(istream& cin, ostream& cout) {
  digit_util du(10);

  auto f = [&](ll n) -> ll {
    auto vec = du.to_vector(n);
    ll ret = 1;
    REP(i, 0, ssize(vec)) ret *= vec[i];
    return ret;
  };

  ll L, R, K; cin >> L >> R >> K;
  ll cnt = 0;
  REP(n, L, R + 1) if (f(n) == K) cnt++;
  cout << cnt << "\n";

  return 0;
}
int body(istream& cin, ostream& cout) {

  digit_util du(10);
  
  auto f = [&](ll a, ll hz0, ll r2, ll r3, ll r5, ll r7) -> ll {
    auto vec = du.to_vector_big_endian(a);
    vector tbl_init(2, vector(2, vector(hz0 + 1, vector(r2 + 1, vector(r3 + 1, vector(r5 + 1, vector(r7 + 1, 0LL)))))));
    auto tbl = tbl_init;
    tbl[1][1][0][0][0][0][0] = 1;
    for (ll t : vec) {
      auto prev = move(tbl);
      tbl = tbl_init;
      REP(eq, 0, 2) REP(az, 0, 2) REP(hz, 0, hz0 + 1) REP(m2, 0, r2 + 1) REP(m3, 0, r3 + 1) REP(m5, 0, r5 + 1) REP(m7, 0, r7 + 1) {
        if (prev[eq][az][hz][m2][m3][m5][m7] == 0) continue;
        REP(d, 0, 10) {
          if (eq and d > t) continue;
          ll new_eq = eq and d == t;
          ll new_az = az and d == 0;
          ll new_m2 = m2, new_m3 = m3, new_m5 = m5, new_m7 = m7;
          ll new_hz = hz;
          if (not new_az) {
            if (hz0 == 1) {
              if (d == 0) {
                new_hz = 1;
              }
            }else {
              ll add_m2 = 0, add_m3 = 0, add_m5 = 0, add_m7 = 0;
              if (d == 0) continue;
              else if (d == 1);
              else if (d == 2) add_m2 = 1;
              else if (d == 3) add_m3 = 1;
              else if (d == 4) add_m2 = 2;
              else if (d == 5) add_m5 = 1;
              else if (d == 6) { add_m2 = 1; add_m3 = 1; }
              else if (d == 7) add_m7 = 1;
              else if (d == 8) add_m2 = 3;
              else if (d == 9) add_m3 = 2;
              new_m2 += add_m2;
              new_m3 += add_m3;
              new_m5 += add_m5;
              new_m7 += add_m7;
              if (new_m2 > r2 or new_m3 > r3 or new_m5 > r5 or new_m7 > r7) continue;
            }
          }
          tbl[new_eq][new_az][new_hz][new_m2][new_m3][new_m5][new_m7] += prev[eq][az][hz][m2][m3][m5][m7];
        }
      }
    }
    ll ret = 0;
    if (hz0 == 1) REP(eq, 0, 2) ret += tbl[eq][0][1][0][0][0][0];
    else REP(eq, 0, 2) ret += tbl[eq][0][0][r2][r3][r5][r7];
    return ret;
  };

  ll L, R, K; cin >> L >> R >> K;
  ll r2 = 0, r3 = 0, r5 = 0, r7 = 0;
  if (K != 0) {
    while (K % 2 == 0) { r2++; K /= 2; }
    while (K % 3 == 0) { r3++; K /= 3; }
    while (K % 5 == 0) { r5++; K /= 5; }
    while (K % 7 == 0) { r7++; K /= 7; }
    if (K != 1) {
      cout << "0\n";
      return 0;
    }
  }
  ll hz0 = K == 0;
  ll x1 = f(R, hz0, r2, r3, r5, r7);
  ll x2 = f(L - 1, hz0, r2, r3, r5, r7);
  cout << x1 - x2 << "\n";



  return 0;
}

