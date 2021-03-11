#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll big = 1e12;
  ll N, M; cin >> N >> M;
  using Pair = pair<ll, ll>;
  vector<Pair> xy;
  for (ll i = 0; i < N; i++) {
    ll x, y; cin >> x >> y;
    xy.emplace_back(x, y);
  }
  for (ll i = 0; i < M; i++) {
    ll a; cin >> a;
    xy.emplace_back(a, big);
  }
  sort(xy.begin(), xy.end());
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  ll cnt = 0;
  for (ll i = 0; i < (ll)xy.size(); i++) {
    ll u, v; tie(u, v) = xy.at(i);
    if (v < big) pq.push(v);
    else {
      while (!pq.empty()) {
	ll y = pq.top(); pq.pop();
	if (y < u) continue;
	cnt++;
	break;
      }
    }
  }
  cout << cnt << endl;

  return 0;
}

