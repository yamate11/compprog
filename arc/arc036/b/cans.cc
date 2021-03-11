#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> h(N);
  for (ll i = 0; i < N; i++) cin >> h.at(i);
  ll ans = 0;
  ll s = 0;
  while (true) {
    ll t = s;
    while (t+1 < N && h.at(t) < h.at(t+1)) t++;
    ll u = t;
    while (u+1 < N && h.at(u) > h.at(u+1)) u++;
    ans = max(ans, u - s + 1);
    if (u+1 == N) break;
    s = u;
  }
  cout << ans << endl;


  return 0;
}

