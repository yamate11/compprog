#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(coordCompr)

// ---- inserted library file coordCompr.cc

class CoordCompr {
  bool built;
  unordered_map<ll, int> mp;
                       // map from an original value to a compressed value
  vector<ll> rev;      // vector of original values

  void build() {
    built = true;
    sort(rev.begin(), rev.end());
    rev.erase(unique(rev.begin(), rev.end()), rev.end());
    mp = unordered_map<ll, int>();
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

  void add(const vector<ll>& vec) {
    for (ll x : vec) rev.push_back(x);
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

  int size() {
    if (! built) build();
    return rev.size();
  }

};

// ---- end coordCompr.cc

// @@ !! LIM -- end mark --


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    CoordCompr cc;
    cc.add(0);
    cc.add(vector<ll>({10, -10}));
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
  {
    CoordCompr cc(vector<ll>{0,0,0,10});
    assert(cc.size() == 2);   // Immediately after construction
  }
  


  cout << "Test done." << endl;

}
  
