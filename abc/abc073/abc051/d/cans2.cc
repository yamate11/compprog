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
  vector<bool> used(M);
  using Tuple = tuple<ll, ll, ll>;
  vector<vector<Tuple>> nbr(N);
  for (ll i = 0; i < M; i++) {
    ll a, b, c; cin >> a >> b >> c; a--; b--;
    nbr.at(a).emplace_back(c, b, i);
    nbr.at(b).emplace_back(c, a, i);
  }
  ll big = 1000 * 1000;
  for (ll i = 0; i < N; i++) {
    priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;
    vector<ll> dist(N, big);
    pq.emplace(0, i, -1);
    dist.at(i) = 0;
    while(!pq.empty()) {
      ll j, c, k; tie(c, j, k) = pq.top(); pq.pop();
      if (dist.at(j) < c) continue;
      if (k >= 0) used.at(k) = true;
      for (Tuple t : nbr.at(j)) {
	ll j1, c1, k1; tie(c1, j1, k1) = t;
	if (dist.at(j1) < dist.at(j) + c1) continue;
	dist.at(j1) = dist.at(j) + c1;
	pq.emplace(dist.at(j) + c1, j1, k1);
      }
    }
  }
  ll cnt = 0;
  for (ll i = 0; i < M; i++) if (!used.at(i)) cnt++;
  cout << cnt << endl;

  return 0;
}

