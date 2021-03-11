#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using Pair = pair<ll, ll>;
  ll N, M; cin >> N >> M;
  vector<vector<ll>> nbr(N);
  vector<ll> A(M), B(M);
  for (ll i = 0; i < M; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr.at(a).push_back(b);
    nbr.at(b).push_back(a);
    A.at(i) = a;
    B.at(i) = b;
  }
  vector<ll> dist0(N, -1);
  queue<Pair> que;
  que.emplace(0, 0);
  while (!que.empty()) {
    ll n, d; tie(n, d) = que.front(); que.pop();
    if (dist0.at(n) >= 0) continue;
    dist0.at(n) = d;
    for (ll m : nbr.at(n)) {
      if (dist0.at(m) >= 0) continue;
      que.emplace(m, d+1);
    }
  }
  ll even = 0; ll odd = 0;
  for (ll i = 0; i < N; i++) {
    if (dist0.at(i) % 2 == 0) even++;
    else                      odd++;
  }
  for (ll i = 0; i < M; i++) {
    if (dist0.at(A.at(i)) % 2 != dist0.at(B.at(i)) % 2) continue;
    cout << N * (N-1) / 2 - M << endl;
    return 0;
  }
  cout << even * odd - M << endl;
  return 0;
}

