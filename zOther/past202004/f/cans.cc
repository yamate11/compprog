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
  using Pair = pair<ll, ll>;
  vector<Pair> AB;
  for (ll i = 0; i < N; i++) {
    ll a, b; cin >> a >> b;
    AB.emplace_back(a, b);
  }
  sort(AB.begin(), AB.end());
  priority_queue<ll> pq;

  ll sum = 0;
  ll iab = 0;
  for (ll day = 1; day <= N; day++) {
    while (iab < N && AB.at(iab).first == day) {
      pq.push(AB.at(iab).second);
      iab++;
    }
    ll e = pq.top(); pq.pop();
    sum += e;
    cout << sum << "\n";
  }

  return 0;
}

