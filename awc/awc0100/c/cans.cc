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

// @@ !! LIM(digit)

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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  digit_util du(2);

  ll N, L, Q; cin >> N >> L >> Q;
  vector<string> S(N);
  REP(i, 0, N) {
    string s; cin >> s;
    S[i] = s;
  }

  REP(q, 0, Q) {
    ll m; cin >> m;
    string ans(L, '0');
    REP(j, 0, m) {
      ll c; cin >> c; c--;
      REP(k, 0, L) {
        if (S[c][k] == '1') ans[k] = '1';
      }
    }
    cout << ans << "\n";
  }
  

  return 0;
}

