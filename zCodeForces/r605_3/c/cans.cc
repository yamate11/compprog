#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  string S; cin >> S;
  vector<bool> valid(128);
  for (ll i = 0; i < K; i++) {
    char c; cin >> c;
    valid[c] = true;
  }
  ll ans = 0;
  for (ll i = 0; i < N; ) {
    for ( ; i < N && !valid[S[i]]; i++);
    if (i == N) break;
    ll p = i;
    for ( ; i < N && valid[S[i]]; i++);
    ll len = i - p;
    ans += len * (len + 1) / 2;
  }
  cout << ans << endl;

  return 0;
}

