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
  string S; cin >> S;
  ll Q; cin >> Q;
  bool flipped = false;
  REP(_q, Q) {
    ll t, a, b; cin >> t >> a >> b; a--; b--;
    if (t == 1) {
      ll aa, bb;
      if (flipped) {
        aa = (a + N) % (2 * N);
        bb = (b + N) % (2 * N);
      }else {
        aa = a; bb = b;
      }
      swap(S[aa], S[bb]);
    }else if (t == 2) {
      flipped = not flipped;
    }
  }
  if (flipped) {
    cout << S.substr(N, N) << S.substr(0, N) << endl;
  }else {
    cout << S << endl;
  }

  return 0;
}

