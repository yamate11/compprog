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
  vector<ll> P(N);
  REP(i, N) {
    cin >> P[i]; P[i]--;
  }
  if (N == 2) {
    if (P[0] == 0) cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
  }
  ll ans = -1;
  if (P[1] == (P[0] + 1) % N) {
    ll cand1 = (N - P[0]) % N;
    ll cand2 = P[0] + 2;
    ans = min(cand1, cand2);
  }else if (P[0] == (P[1] + 1) % N) {
    ll cand1 = P[0] == N-1 ? 1 : (N - (N - 1 - P[0])) + 1;
    ll cand2 = 1 + N - P[N - 1];
    ans = min(cand1, cand2);
  }else assert(0);
  cout << ans << endl;

  return 0;
}

