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
  vector<ll> res(N+1, LLONG_MAX);
  queue<pair<ll, ll>> que;
  que.emplace(0, 0);
  while (true) {
    pair<ll, ll> p = que.front(); que.pop();
    ll n = p.first; ll cnt = p.second;
    if (n == N) {
      cout << cnt << endl;
      return 0;
    }
    if (res.at(n) < cnt) continue;
    auto put = [&] (ll m) -> void {
      if (res.at(m) <= cnt + 1) return;
      res.at(m) = cnt + 1;
      que.emplace(m, cnt + 1);
    };
    put(n+1);
    for (ll k = 6; n + k <= N; k *= 6) put(n+k);
    for (ll k = 9; n + k <= N; k *= 9) put(n+k);
  }

  return 0;
}

