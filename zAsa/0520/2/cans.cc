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

// @@ !! LIM(digit forall)

// ---- inserted library file digit.cc

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

  digit_util(ll base_ = 10) : base(base_), _pow(_make_pow(base_)) {}
    
  ll pow_size() const { return _pow.size(); }
  ll pow(ll i) const {
    if (i < 0 or ssize(_pow) <= i) return -1;
    return _pow[i];
  }

  ll width(ll x) const {
    if (x < 0) return -1;
    if (base == 2) return bit_width((unsigned long long)x);
    if (x == 0) return 0;
    ll ret = 0;
    for (; x != 0; x /= base) ret++;
    return ret;
  }

  ll nd_min(ll i) const { return i < 0 ? -1 : i == 0 ? 0 : pow(i - 1); }
  ll nd_max(ll i) const { return i < 0 ? -1 : i == 0 ? 0 : nd_min(i + 1) - 1; }

  ll floor(ll x) const { return (x < 0) ? -1 : x == 0 ? 0 : _pow[width(x) - 1]; }

  ll ceil(ll x) const {
    if (x < 0) return -1;
    if (x == 0) return 0;
    ll p = _pow[width(x) - 1];
    return (x == p) ? p : (p * base);
  }

  ll log(ll x) const { return (x <= 0) ? -1 : width(x) - 1; }

  ll d_at(ll x, ll i) const {
    if (x < 0) return -1;
    if (x == 0) return 0;
    if (i < 0) i += width(x);
    return (x / pow(i)) % base;
  }

  ll d_sub(ll x, ll pos, ll len) const {
    if (x < 0) return -1;
    if (x == 0) return 0;
    ll w = width(x);
    if (pos < 0) pos += w;
    if (len < 0) { len = -len; pos = pos - len + 1; }
    if (pos < 0) { len += pos; pos = 0; }
    if (pos + len > w) len = w - pos;
    return (x % pow(pos + len)) / pow(pos);
  }

  vector<ll> to_vector(ll x) const {
    if (x < 0) return vector<ll>{};
    if (x == 0) return vector<ll>{0};
    vector<ll> ret;
    ret.reserve(width(x));
    for ( ; x != 0; x /= base) { ret.push_back(x % base); }
    return ret;
  }

  string to_string(ll x, bool upcase = false) const {
    if (x < 0) return string();
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

  ll from_vector(const vector<ll>& vec) const {
    ll ret = 0;
    for (ll i = 0; i < ssize(vec); i++) ret += vec[i] * pow(i);
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

// ---- inserted library file forall.cc

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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  digit_util du(10);
  ll N; cin >> N;
  ll ans = 0;
  if (N < 10) ans = N;
  else {
    ll w = du.width(N);
    if (FORALL(i, 0, w - 1, du.d_at(N, i) == 9)) {
      ans = 9 * (w - 1) + du.d_at(N, w - 1);
    }else {
      ans = 9 * (w - 1) + du.d_at(N, w - 1) - 1;
    }
  }
  cout << ans << endl;
  return 0;
}

