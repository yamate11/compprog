#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
using ull = unsigned long long;

/*
  Digit Util   (Kuraidori Kisuho)

  digit_util du;      // base == 10
  digit_util du1(3);  // base == 3
  digit_util du2(16); // base == 16
  
  du.pow(3)  // 1000
  du.pow(18) // 1000000000000000000
  du.pow_size() // 19, meaning du.pow(i) is valid for i from 0 to 18
  du.width(5678) // 4, meaning 5678 has 4 digits
  du.width(0) // 0, a particular value
  du.floor(1234) // 1000, the largest power of 10 that does not exceed 1234
  du.ceil(1234) // 10000, the smallest power of 10 that does not fall below 1234
  du.to_vector(1234) // vector<ll>{1, 2, 3, 4}
  du.to_string(1234) // "1234"
  du.from_vector(vector<ll>{1, 2, 3, 4}) // 1234
  du.from_string("1234") // 1234
 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- digit.cc

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
    if (x < 0) throw runtime_error("digit.width: x < 0");
    ll ret = 0;
    for (; x != 0; x /= base) ret++;
    return ret;
  }

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

// @@ !! END ---- digit.cc

// @@ !! LIM()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    digit_util du;
    assert(du.pow_size() == 19);
    assert(du.pow(0) == 1);
    assert(du.pow(1) == 10);
    assert(du.pow(6) == 1000000);
    assert(du.pow(18) == 1000000000000000000);
    assert(du.width(0) == 0);
    assert(du.width(1) == 1);
    assert(du.width(2) == 1);
    assert(du.width(9) == 1);
    assert(du.width(10) == 2);
    assert(du.width(99) == 2);
    assert(du.width(100) == 3);
    assert(du.width(123456789012345678) == 18);
    assert(du.width(1000000000000000000) == 19);
    assert(du.floor(0) == 0);
    assert(du.floor(123) == 100);
    assert(du.floor(1000) == 1000);
    assert(du.ceil(0) == 0);
    assert(du.ceil(123) == 1000);
    assert(du.ceil(1000) == 1000);
    assert(du.to_string(0) == "0");
    assert(du.to_string(1) == "1");
    assert(du.to_string(123) == "123");
    assert(du.from_string("0") == 0);
    assert(du.from_string("230") == 230);
    assert(du.from_string("00230") == 230);
    assert(du.to_vector(0) == vector<ll>{0});
    assert(du.to_vector(1) == vector<ll>{1});
    assert(du.to_vector(123) == (vector<ll>{1, 2, 3}));
    assert(du.from_vector(vector<ll>{0}) == 0);
    assert(du.from_vector((vector<ll>{2, 3, 0})) == 230);
    assert(du.from_vector((vector<ll>{0, 0, 2, 3, 0})) == 230);
  }

  {
    digit_util du(3);
    assert(du.pow(0) == 1);
    assert(du.pow(4) == 81);
    assert(du.width(80) == 4);
    assert(du.floor(80) == 27);
    assert(du.ceil(80) == 81);
    assert(du.to_string(83) == "10002");
    assert(du.from_string("10002") == 83);
  }

  {
    digit_util du(16);
    assert(du.pow(0) == 1);
    assert(du.pow(4) == 65536);
    assert(du.width(100) == 2);
    assert(du.floor(100) == 16);
    assert(du.ceil(100) == 256);
    assert(du.to_string(254) == "fe");
    assert(du.to_string(254, true) == "FE");
    assert(du.from_string("1af") == 256 + 10 * 16 + 15);
    assert(du.from_string("1AF") == 256 + 10 * 16 + 15);
  }

  cerr << "ok\n";

  return 0;
}
