#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define InpVec(vec, n) vector<ll> vec(n); REP(i, 0, (n)) cin >> vec[i]
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

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
  vector<ll> A(N), B(N);
  CoordCompr cc;
  REP(i, 0, N) {
    cin >> A[i];
    cc.add(A[i]);
  }
  REP(i, 0, N) B[i] = cc.c(A[i]);
  ll sz = cc.size();
  vector<ll> lastpos(sz, -1);
  vector<ll> F(N, -1);
  REP(i, 0, 2*N) {
    ll j = i % N;
    if (not (B[j] == sz - 1 or lastpos[B[j] + 1] < 0 or F[j] >= 0)) F[j] = lastpos[B[j] + 1];
    lastpos[B[j]] = j;
  }
  ll n;
  for (n = N - 1; B[n] != 0; n--);
  REP(i, 0, sz - 1) {
    ll m = n % N;
    if (m < F[m]) n += F[m] - m;
    else          n += F[m] - m + N;
  }
  cout << (n + N - 1) / N << endl;
  

  return 0;
}

