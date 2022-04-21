#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector rec(N + 1, vector<ll>());
  REP(i, N) {
    rec[A[i]].push_back(i);
  }
  ll Q; cin >> Q;
  REP(_q, Q) {
    ll L, R, X; cin >> L >> R >> X; L--; 
    auto& vec = rec[X];
    ll p = lower_bound(ALL(vec), R) - vec.begin();
    ll q = lower_bound(ALL(vec), L) - vec.begin();
    cout << p - q << "\n";
  }


  return 0;
}

