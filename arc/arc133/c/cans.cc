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

  auto solve = [&]() -> ll {
    ll H, W, K; cin >> H >> W >> K;
    ll sa = 0, sb = 0;
    vector<ll> A(H); REP(i, H) { cin >> A[i]; sa += A[i]; }
    vector<ll> B(W); REP(i, W) { cin >> B[i]; sb += B[i]; }
    ll pa = sa % K, pb = sb % K;
    if (pa != pb) return -1;
    ll ta = 0, tb = 0;
    REP(i, H) ta += ((K - 1) * W - A[i]) % K;
    REP(i, W) tb += ((K - 1) * H - B[i]) % K;
    return (K - 1) * H * W - max(ta, tb);
  };
  cout << solve() << endl;
    

  return 0;
}

