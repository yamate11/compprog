#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a; a--;
    A[i] = a;
  }
  vector<ll> dist(n, 1e10);
  using sta = pair<ll, ll>;
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  dist[0] = 0;
  pque.emplace(0, 0);
  while (!pque.empty()) {
    auto [d, i] = pque.top(); pque.pop();
    if (dist[i] < d) continue;
    vector<ll> nbr;
    if (A[i] > i) nbr.push_back(A[i]);
    if (i - 1 >= 0) nbr.push_back(i - 1);
    if (i + 1 < n)  nbr.push_back(i + 1);
    for (ll j : nbr) {
      if (d + 1 >= dist[j]) continue;
      dist[j] = d + 1;
      pque.emplace(d + 1, j);
    }
  }
  for (ll i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << dist[i];
  }
  cout << endl;


  return 0;
}

