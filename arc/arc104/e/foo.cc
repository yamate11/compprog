#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  CoordCompr  -- coordinate compression (one-dimensional)

  API

    Constructors
      CoordCompr()
      CoordCompr(const vector<ll>& vec)
      CoordCompr(vector<ll>&& vec)
  
    Adding an elment
      void add(ll x)
  
    Compressed value
      int c(ll x)
  
    Decompressed value
      ll d(int i)

    Size
      int size()

  Usage

    vector<ll> vecA(N); cin >> vecA; // or whatever
    CoordCompr cc(move(vecA));       // or just cc(vecA) if you keep vecA
    cc.add(0); cc.add(T);  // or whatever
    int i = cc.c(x1);
    ll x2 = cc.d(i);   // x1 == x2 should hold.
 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- coordCompr.cc

class CoordCompr {
  bool built;
  map<ll, int> mp;     // map from an original value to a compressed value
  vector<ll> rev;      // vector of original values

  void build() {
    built = true;
    sort(rev.begin(), rev.end());
    rev.erase(unique(rev.begin(), rev.end()), rev.end());
    mp = map<ll, int>();
    for (size_t i = 0; i < rev.size(); i++) mp[rev[i]] = i;
  }

public:
  CoordCompr() : built(false) {}
  CoordCompr(const vector<ll>& vec) : built(false), rev(vec) {}
  CoordCompr(vector<ll>&& vec) : built(false), rev(move(vec)) {}

  void add(ll x) {
    rev.push_back(x);
    built = false;
  }

  int c(ll x) {
    if (! built) build();
    return mp[x];
  }

  ll d(int i) {
    if (! built) build();
    return rev[i];
  }

  int size() { return rev.size(); }

};

// @@ !! END ---- coordCompr.cc

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    CoordCompr cc;
    cc.add(0); cc.add(10); cc.add(-10);
    assert(cc.c(0) == 1);
    assert(cc.c(10) == 2);
    assert(cc.c(-10) == 0);
  }
  {
    vector<ll> orig_values({0, -3000, 0, 9, 9, 10, 3, -1234567890123});
    vector<ll> save(orig_values);
    CoordCompr cc(orig_values);
    cc.add(1000);
    assert(cc.c(-3000) == 1);
    assert(cc.c(-1234567890123) == 0);
    assert(cc.c(9) == 4);
    assert(cc.c(1000) == 6);
    assert(cc.d(0) == -1234567890123);
    assert(cc.d(2) == 0);
    assert(cc.d(5) == 10);
    assert(cc.size() == 7);
    assert(orig_values == save);
    CoordCompr cc1(move(orig_values));
    cc1.add(1000);
    assert(cc1.c(-3000) == 1);
    for (ll x : save) assert(cc.c(x) == cc1.c(x));
  }
  


  cout << "Test done." << endl;

}
  
