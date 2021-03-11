#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, Q; cin >> N >> M >> Q;
  vector color(N, 0LL);
  vector nbr(N, vector<ll>());
  for (ll i = 0; i < M; i++) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr.at(u).push_back(v);
    nbr.at(v).push_back(u);
  }
  for (ll i = 0; i < N; i++) cin >> color.at(i);

  for (ll q = 0; q < Q; q++) {
    ll t; cin >> t;
    if (t == 1) {
      ll x; cin >> x; x--;
      cout << color.at(x) << "\n";
      for (ll i : nbr.at(x)) color.at(i) = color.at(x);
    }else {
      ll x, y; cin >> x >> y; x--;
      cout << color.at(x) << "\n";
      color.at(x) = y;
    }
  }

  return 0;
}

