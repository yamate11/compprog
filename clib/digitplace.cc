/*
  Digit Place   (kuraidori kisuho)

  // 2 <= base <= 10
  DigitPlace dgp10(10);       // base == 10    
  DigitPlace dgp10;           // same as above.
  DigitPlace dgp2(2);         // base == 2.

  cout << dgp10.ll2str(54);   // "54"
     // ll2str(x) returns string representation for x
  cout << dgp10.str2ll("54"); // 54
     // str2ll(s) returns the number whose string rep is s  cout << dgp10.mag(1520);    // 4
     // mag(x) returns the number of digits in x, if x > 0;  returns 0 if x == 0
     // In other words,  base^{mag(x) - 1} <= x < base^{mag(x)}  holds if x > 0.
  cout << dgp10.basepow(4);   // 10000  
     // basepow(e) returns base^{e}.
  dgp10.vecdigits("1729");    // vector<int>{9, 2, 7, 1}
     // vecdigits(x) returns a vector of digits (small to large)

 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- digitplace.cc

struct DigitPlace {
  int base;
  vector<ll> apow;

  DigitPlace(int base_ = 10) : base(base_), apow() { _mk_apow(); }
  ll str2ll(const string& s) { return stoll(s, 0, base); }
  string ll2str(ll x) {
    if (x == 0) return "0";
    string ret;
    for ( ; x > 0; x /= base) ret.push_back('0' + (x % base));
    reverse(ret.begin(), ret.end());
    return ret;
  }
  void _mk_apow() {
    if (not apow.empty()) return;
    for (ll t = 1; true; t *= base) {
      apow.push_back(t);
      if (t > LLONG_MAX / base) break;
    }
  }
  int mag(ll x) {
    if (base == 2) {
      if (x == 0) return 0;
      return 64 - __builtin_clzll(x);
    }
    int ret = 0;
    while (ret < (int)apow.size() and apow[ret] <= x) ret++;
    return ret;
  }
  ll basepow(int e) { return apow[e]; }
  vector<int> vecdigits(ll x) {
    if (x == 0) return {0};
    vector<int> ret;
    while (x > 0) {
      ret.push_back(x % base);
      x /= base;
    }
    return ret;
  }
  
};

// @@ !! END ---- digiplace.cc
