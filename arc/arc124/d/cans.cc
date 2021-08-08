#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector P(N + M, 0LL);
  for (ll i = 0; i < N + M; i++) {
    cin >> P[i];
    P[i]--;
  }
  vector visited(N + M, false);
  ll ans = 0;
  ll fonly = 0;
  ll sonly = 0;
  for (ll i = 0; i < N + M; i++) {
    if (visited[i]) continue;
    ll cnt = 0;
    ll j = i;
    bool first = false;
    bool second = false;
    while (true) {
      cnt++;
      visited[j] = true;
      if (j < N) first = true;
      else       second = true;
      j = P[j];
      if (j == i) break;
    }
    ans += cnt - 1;
    if (cnt >= 2) {
      if (!first) sonly++;
      if (!second) fonly++;
    }
  }
  ans += max(fonly, sonly) * 2;
  cout << ans << endl;

  return 0;
}

