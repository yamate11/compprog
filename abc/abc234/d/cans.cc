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
  vector<ll> P(N);
  REP(i, N) cin >> P[i];
  priority_queue<ll, vector<ll>, greater<ll>> pque;
  REP(i, K) pque.emplace(P[i]);
  REP2(i, K, N) {
    ll t = pque.top();
    cout << t << "\n";
    if (P[i] < t) continue;
    pque.emplace(P[i]);
    pque.pop();
  }
  ll t = pque.top();
  cout << t << "\n";

  return 0;
}

