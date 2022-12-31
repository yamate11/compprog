#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

// excl 以外の2つの長方形を，向きを固定して入れられるか?
bool solve2(ll X, ll Y, ll excl) {
  REP(i, 0, 3) if (i != excl) X -= (A[i] + Y - 1) / Y;
  return X >= 0;
}

bool solve1(ll X, ll Y) {
  REP(i, 0, 3) {
    Y -= (A[i] + X - 1) / X;  // i番目の長方形を，片方の辺に沿って置く．
    if (Y <= 0) return false;
    // 残りの2つの長方形を残り領域に置けるか?
    if (solve2(X, Y, i) or solve2(Y, X, i)) return true;
  }
  return false;
}

bool solve() {
    ll X, Y; cin >> X >> Y;
    vector<ll> A(3); REP(i, 0, 3) cin >> A[i];
    // 両向きを試す
    return solve1(X, Y) or solve1(Y, X);
}

int main() {
  cout << (solve() ? "Yes\n" : "No\n");
  return 0;
}

