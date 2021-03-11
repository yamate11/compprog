#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, K; cin >> N >> M >> K;
  vector<ll> A(N), B(M), SA(N+1), SB(M+1);
  for (ll i = 0; i < N; i++) {
    cin >> A.at(i);
    SA.at(i+1) = SA.at(i) + A.at(i);
  }
  for (ll i = 0; i < M; i++) {
    cin >> B.at(i);
    SB.at(i+1) = SB.at(i) + B.at(i);
  }
  ll ans = 0;
  ll i = 0;
  while (i < N && SA.at(i+1) <= K) i++;
  if (SA.at(i) > K) i--;
  ll j = 0;
  while (true) {
    while (j < M && SA.at(i) + SB.at(j) <= K) j++;
    if (SA.at(i) + SB.at(j) > K) j--;
    ans = max(ans, i + j);
    if (i == 0) break;
    i--;
  }
  cout << ans << endl;

  return 0;
}

