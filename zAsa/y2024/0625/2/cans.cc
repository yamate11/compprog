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

struct digit_util {
  ll base;
  vector<ll> _pow;

  digit_util(ll base_ = 10) : base(base_), _pow() {
    ll t = 1;
    while (true) {
      _pow.push_back(t);
      if (__builtin_smulll_overflow(t, base, &t)) break;
    }
  }
    
  ll pow_size() { return _pow.size(); }
  ll pow(ll i) { return _pow[i]; }

  ll width(ll x) {
    if (x <= 0) throw runtime_error("digit.width: x <= 0");
    ll ret = 0;
    for (; x != 0; x /= base) ret++;
    return ret;
  }

  ll nd_min(ll i) { return pow(i - 1); }
  ll nd_max(ll i) { return nd_min(i + 1) - 1; }

  ll floor(ll x) { return (x == 0) ? 0 : _pow[width(x) - 1]; }

  ll ceil(ll x) {
    if (x == 0) return 0;
    ll p = _pow[width(x) - 1];
    return (x == p) ? p : (p * base);
  }

  vector<ll> to_vector(ll x) {
    if (x < 0) throw runtime_error("to_vector: x < 0");
    if (x == 0) return vector<ll>{0};
    vector<ll> ret;
    for ( ; x != 0; x /= base) { ret.push_back(x % base); }
    reverse(ret.begin(), ret.end());
    return ret;
  }

  string to_string(ll x, bool upcase = false) {
    char ten = upcase ? 'A' : 'a';
    string ret;
    for (ll d : to_vector(x)) ret.push_back(d < 10 ? '0' + d : ten + (d - 10));
    return ret;
  }

  ll from_vector(const vector<ll>& vec) {
    ll ret = 0;
    for (ll x : vec) ret = ret * base + x;
    return ret;
  }

  ll from_string(string s) {
    vector<ll> vec;
    for (char c : s) {
      ll x;
      if ('0' <= c and c <= '9')      x = c - '0';
      else if ('a' <= c and c <= 'z') x = c - 'a' + 10;
      else if ('A' <= c and c <= 'Z') x = c - 'A' + 10;
      else throw runtime_error("str_to_ll: unknown letter");
      vec.push_back(x);
    }
    return from_vector(vec);
  }

};

// ---- end digit.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  digit_util du;

  auto f = [&](ll x, ll i) -> ll {
    ll p = du.pow(i + 1);
    ll q = p / 2;
    ll y = x / p;
    ll z = x % p;
    if (z >= q) y++;
    return y * p;
  };

  ll x, k; cin >> x >> k;
  REP(i, 0, k) x = f(x, i);
  cout << x << endl;

  return 0;
}

