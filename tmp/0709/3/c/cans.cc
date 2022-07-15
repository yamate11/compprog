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

  vector<ll> A(5);
  REP(i, 5) cin >> A[i];
  set<ll> B;
  REP(x, 32) {
    if (__builtin_popcountll(x) != 3) continue;
    ll t = 0;
    REP(i, 5) if (x >> i & 1) t += A[i];
    B.insert(t);
  }
  auto it = B.rbegin();
  it++;
  it++;
  cout << *it << endl;

  return 0;
}

