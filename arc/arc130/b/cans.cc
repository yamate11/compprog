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

  ll H, W, C, Q; cin >> H >> W >> C >> Q;
  vector<bool> row(H), col(W);
  ll nr = 0;
  ll nc = 0;
  vector<ll> TT(Q), NN(Q), CC(Q);
  vector<ll> ans(C + 1);
  REP(q, Q) { cin >> TT[q] >> NN[q] >> CC[q]; NN[q]--;}
  REP2R(q, Q - 1, 0) {
    if (TT[q] == 1) {
      if (row[NN[q]]) continue;
      row[NN[q]] = true;
      nr++;
      ans[CC[q]] += W - nc;
    }else {
      if (col[NN[q]]) continue;
      col[NN[q]] = true;
      nc++;
      ans[CC[q]] += H - nr;
    }
  }
  REP2(c, 1, C + 1) cout << ans[c] << " ";
  cout << endl;

  return 0;
}

