#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  CoordCompr cc;
  for (ll i = 0; i < N; i++) cc.add(A[i]);
  for (ll i = 0; i < N; i++) {
    cout << cc.c(A[i]) << "\n";
  }

  return 0;
}

