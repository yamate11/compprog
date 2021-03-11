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
  vector<vector<ll>> nbr(N);
  for (ll i = 0; i < M; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr.at(a).push_back(b);
    nbr.at(b).push_back(a);
  }
  vector<ll> dist(N, -1);
  vector<ll> mark(N, 0);
  using Tuple = tuple<ll, ll, ll>; // dist, this, orig
  queue<Tuple> que;
  for (ll i : nbr.at(0)) {
    que.emplace(1, i, 0);
  }
  while (!que.empty()) {
    auto [dis, t, orig] = que.front(); que.pop();
    if (dist.at(t) >= 0) continue;
    mark.at(t) = orig;
    dist.at(t) = dis;
    for (ll i : nbr.at(t)) {
      if (dist.at(i) < 0) {
	que.emplace(dis+1, i, t);
      }
    }
  }
  cout << "Yes\n";
  for (ll i = 1; i < N; i++) {
    cout << mark.at(i) + 1 << "\n";
  }

  return 0;

}

