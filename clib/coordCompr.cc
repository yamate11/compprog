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
  
    Adding elements
      void add(ll x)
      void add(const vector<ll>& vec)
  
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

  Notice

    Type T other than ll can be compressed using
      CoordCompr<T>
    if unordered_map<T, int> is defined.  Otherwise, use
      CoordCompr<T, map<T, int>>
    E.g., 
      CoordCompr<string>   --- OK
      CoordCompr<pll>   --- NG
      CoordCompr<pll, map<pll, int>>  --- OK
 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- coordCompr.cc

template<typename T = ll, typename MAP = unordered_map<T, int>>
class CoordCompr {
  bool built;
  MAP mp;
                       // map from an original value to a compressed value
  vector<T> rev;      // vector of original values

  void build() {
    built = true;
    sort(rev.begin(), rev.end());
    rev.erase(unique(rev.begin(), rev.end()), rev.end());
    mp = MAP();
    for (size_t i = 0; i < rev.size(); i++) mp[rev[i]] = i;
  }

public:

  CoordCompr() : built(false) {}
  CoordCompr(const vector<T>& vec) : built(false), rev(vec) {}
  CoordCompr(vector<T>&& vec) : built(false), rev(move(vec)) {}

  void add(const T& x) {
    rev.push_back(x);
    built = false;
  }

  void add(const vector<T>& vec) {
    for (const T& x : vec) rev.push_back(x);
    built = false;
  }

  int c(const T& x) {
    if (! built) build();
    return mp[x];
  }

  T d(int i) {
    if (! built) build();
    return rev[i];
  }

  int size() {
    if (! built) build();
    return rev.size();
  }

};

// @@ !! END ---- coordCompr.cc
