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

// @@ !! LIM(digit perm f:updMaxMin)

// ---- inserted library file digit.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/digit.cc

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

// ---- inserted library file perm.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/perm.cc

template <bool dup, typename T>
struct IntPermBase {
  int n;
  int r;
  vector<int> vec;
  bool started;
  vector<T> mapping;

  bool start_check() {
    if constexpr (dup) { if (not ((1 <= n and 0 <= r) or (n == 0 and r == 0))) return false; }
    else { if (not (0 <= n and 0 <= r and r <= n)) return false; }
    started = true;
    vec.resize(r, 0);
    return true;
  }

  bool finish() {
    vec.resize(0);
    started = false;
    return false;
  }

  IntPermBase(int n_, int r_) : n(n_), r(r_), started(false) {
    if (n >= 0) {
      mapping = vector<T>(n);
      for (int i = 0; i < n; i++) {
        if constexpr (is_integral<T>::value) mapping[i] = (T)i;
        else mapping[i] = T();
      }
    }
  }
  IntPermBase(int n_, int r_, vector<T> mp) : n(n_), r(r_), started(false), mapping(move(mp)) {
    if (ssize(mapping) != n) throw runtime_error("IntPermBase: incorrect mapping length");
  }

  T at(int i) const { return mapping[vec[i]]; }

  T operator[](int i) const { return at(i); }

  void set_mapping(auto f) {
    for (int i = 0; i < n; i++) mapping[i] = f(i);
  }

  vector<T> vec_view() const {
    vector<T> res;
    for (int i = 0; i < r; i++) res.push_back(mapping[vec[i]]);
    return res;
  }
};

template<typename T = int>
struct IntPerm : IntPermBase<false, T> {
  using Base = IntPermBase<false, T>;
  using Base::vec, Base::r, Base::n, Base::started;

  vector<vector<int>> cands;
  vector<int> cidx;

  bool start_check() {
    if (not IntPermBase<false, T>::start_check()) return false;
    iota(vec.begin(), vec.end(), 0);
    cands.resize(r);
    cidx.resize(r);
    for (int i = 0; i < r; i++) {
      for (int j = n - 1; j >= i; j--) cands[i].push_back(j);
      cidx[i] = n - i - 1;
    }
    return true;
  }

  bool finish() {
    cands.resize(0);
    cidx.resize(0);
    return IntPermBase<false, T>::finish();
  }

  IntPerm(int n_, int r_) : IntPermBase<false, T>(n_, r_) {}
  IntPerm(int n_, int r_, vector<T> mp) : IntPermBase<false, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    int i = r - 1;
    for (; i >= 0 and cidx[i] == 0; i--);
    if (i < 0) return finish();
    vec[i] = cands[i][--cidx[i]];
    for (int j = i + 1; j < r; j++) {
      if (j == i + 1) {
        cands[j].resize(0);
        for (int k = 0; k < (int)cands[i].size(); k++) {
          if (k == cidx[i]) continue;
          cands[j].push_back(cands[i][k]);
        }
      }else {
        cands[j] = cands[j - 1];
        cands[j].pop_back();
      }
      cidx[j] = n - j - 1;
      vec[j] = cands[j][cidx[j]];
    }
    return true;
  }
};

template<typename T = int>
struct IntComb : IntPermBase<false, T> {
  using Base = IntPermBase<false, T>;
  using Base::vec, Base::r, Base::n, Base::started, Base::finish;

  bool start_check() {
    if (not IntPermBase<false, T>::start_check()) return false;
    iota(vec.begin(), vec.end(), 0);
    return true;
  }

  IntComb(int n_, int r_) : IntPermBase<false, T>(n_, r_) {}
  IntComb(int n_, int r_, vector<T> mp) : IntPermBase<false, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    int i = r - 1;
    for (; i >= 0 and vec[i] == n - r + i; i--);
    if (i < 0) return finish();
    vec[i]++;
    for (int j = i + 1; j < r; j++) vec[j] = vec[j - 1] + 1;
    return true;
  }
};

template<typename T = int>
struct IntDupPerm : IntPermBase<true, T> {
  using Base = IntPermBase<true, T>;
  using Base::vec, Base::r, Base::n, Base::started, Base::finish, Base::start_check;

  IntDupPerm(int n_, int r_) : IntPermBase<true, T>(n_, r_) {}
  IntDupPerm(int n_, int r_, vector<T> mp) : IntPermBase<true, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    for (int i = r - 1; i >= 0; vec[i--] = 0) if (++vec[i] < n) return true;
    return finish();
  }
};

template<typename T = int>
struct IntDupComb : IntPermBase<true, T> {
  using Base = IntPermBase<true, T>;
  using Base::vec, Base::r, Base::n, Base::started, Base::finish, Base::start_check;

  IntDupComb(int n_, int r_) : IntPermBase<true, T>(n_, r_) {}
  IntDupComb(int n_, int r_, vector<T> mp) : IntPermBase<true, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    int i = r - 1;
    for (; i >= 0 and vec[i] == n - 1; i--);
    if (i < 0) return finish();
    vec[i]++;
    for (int j = i + 1; j < r; j++) vec[j] = vec[i];
    return true;
  }
};

struct IDCBoxBall {
  int box;
  int ball;
  IntDupComb<> idc;
  vector<int> numBalls;
  IDCBoxBall(int box_, int ball_) : box(box_), ball(ball_), idc(box, ball) {}
  bool get() {
    bool b = idc.get();
    if (not b) return false;
    numBalls = vector<int>(box);
    for (int i = 0; i < ball; i++) numBalls[idc.at(i)]++;
    return true;
  }
  int at(int i) const { return numBalls[i]; }
  int operator[](int i) const { return at(i); }
  vector<int> vec_view() const { return numBalls; }
};


template<typename INT>
struct IntDirProd {
  vector<INT> lim;
  int r;
  vector<INT> vec;
  bool started;

  IntDirProd(const vector<INT>& lim_) : lim(lim_), r(lim.size()), started(false) {}

  int at(int i) const { return vec[i]; }
  int operator[](int i) const { return at(i); }

  const vector<INT>& vec_view() const { return vec; }

  bool start_check() {
    for (int i = 0; i < r; i++) if (lim[i] == 0) return false;
    started = true;
    vec.resize(r, 0);
    return true;
  }

  bool finish() {
    vec.resize(0);
    started = false;
    return false;
  }

  bool get() {
    if (not started) return start_check();
    for (int i = r - 1; i >= 0; vec[i--] = 0) if (++vec[i] < lim[i]) return true;
    return finish();
  }
};

template<typename INT>
struct IntPartition {
  INT n;
  vector<INT> vec;
  bool started = false;
  IntPartition(INT n_) : n(n_) {}
  
  bool get() {
    if (not started) {
      started = true;
      vec = vector<INT>(n, 1);
      return true;
    }else if (ssize(vec) == 1) {
      started = false;
      return false;
    }else {
      ll b = vec.back(); vec.pop_back();
      ll a = vec.back(); vec.pop_back();
      ll c = a + b;
      ll a1 = a + 1;
      while (c - a1 >= a1) {
        vec.push_back(a1);
        c -= a1;
      }
      vec.push_back(c);
      return true;
    }
  }

  INT at(int i) const { return vec[i]; }
  const vector<INT>& vec_view() const { return vec; }
};

// ---- end perm.cc

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  digit_util du(10);
  ll big = 1LL << 60;

  auto solve = [&]() -> void {
    ll A, N; cin >> A >> N;

    auto f = [&](ll w) -> void {
      vector<ll> vec(w);
      REP(x
    };

    // @InpVec(N, D) [5Wfg7evh]
    auto D = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; D[i] = v; }
    // @End [5Wfg7evh]
    ll w = du.width(A);
    ll ans = big;
    f(w);
    f(w - 1);
    if (A < du.pow(17)) f(w + 1);
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

