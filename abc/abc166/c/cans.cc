#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> H(N);
  for (ll i = 0; i < N; i++) cin >> H.at(i);
  vector<bool> good(N, true);
  for (ll i = 0; i < M; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    if (H.at(a) <= H.at(b)) good.at(a) = false;
    if (H.at(a) >= H.at(b)) good.at(b) = false;
  }
  ll cnt = 0;
  for (ll i = 0; i < N; i++) {
    if (good.at(i)) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

