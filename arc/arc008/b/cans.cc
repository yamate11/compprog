#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:nnDivCeil)
// --> f:nnDivCeil
// ---- inserted function nnDivCeil from util.cc
// Natural Number Division and Ceiling
ll nnDivCeil(ll x, ll y) {
  return (x + (y - 1)) / y;
}
// ---- end nnDivCeil
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  string name; cin >> name;
  string kit ; cin >> kit;

  vector<ll> vName(128), vKit(128);
  for (ll i = 0; i < N; i++) vName.at(name.at(i))++;
  for (ll i = 0; i < M; i++) vKit.at(kit.at(i))++;
  ll ans = 0;
  for (char c = 'A'; c <= 'Z'; c++) {
    if (vName.at(c) == 0) continue;
    if (vKit.at(c) == 0) {
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans, nnDivCeil(vName.at(c), vKit.at(c)));
  }
  cout << ans << endl;

  return 0;
}

