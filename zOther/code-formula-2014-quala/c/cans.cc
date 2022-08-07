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

  ll N, K; cin >> N >> K;
  vector A(N, vector(K, 0LL));
  REP(i, N) REP(j, K) cin >> A[i][j];
  set<ll> selected;
  ll numSel = 0;
  REP(i, N) {
    set<ll> cur_selected;
    ll prefer = numSel;
    REP(j, K) {
      REP(p, i + 1) {
        if (prefer >= K) break;
        if (selected.find(A[p][j]) == selected.end() and cur_selected.find(A[p][j]) == cur_selected.end()) {
          cur_selected.insert(A[p][j]);
          prefer++;
          numSel++;
        }
        if (numSel >= K) break;
      }
      if (prefer >= K or numSel >= K) break;
      prefer += N - (i + 1);
    }
    for (ll a : cur_selected) {
      cout << a << " ";
      selected.insert(a);
    }
    cout << "\n";
  }
  

  return 0;
}

