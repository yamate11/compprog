#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  priority_queue<pair<ll,ll>> pq;
  for (ll i = 0; i < N; i++) {
    ll x; cin >> x;
    if (i < K) {
      pq.emplace(x, i+1);
      if (i == K-1) cout << pq.top().second << endl;
      continue;
    }
    if (x < pq.top().first) {
      pq.pop();
      pq.emplace(x, i+1);
    }
    cout << pq.top().second << endl;
  }
  return 0;
}

