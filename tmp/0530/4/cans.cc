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

  ll N, K, M, R; cin >> N >> K >> M >> R;
  vector<ll> S(N - 1); REP(i, N-1) cin >> S[i];
  sort(ALL(S), greater<ll>());
  ll v = 0; REP(i, K - 1) v += S[i];
  ll req = K * R - v;
  if (K < N and v + S[K-1] >= K * R) cout << "0\n";
  else if (req < 0) cout << "0\n";
  else if (req > M) cout << "-1\n";
  else cout << req << "\n";
  

  return 0;
}

