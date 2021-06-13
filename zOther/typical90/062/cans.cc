#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector nxt(N + 1, vector<ll>());
  queue<ll> que;
  vector<bool> visited(N + 1);
  for (ll i = 1; i <= N; i++) {
    ll a, b; cin >> a >> b;
    if (a == i || b == i) {
      que.push(i);
      visited[i] = true;
    }
    else {
      nxt[a].push_back(i);
      nxt[b].push_back(i);
    }
  }
  vector<ll> ord;
  while (!que.empty()) {
    ll x = que.front(); que.pop();
    ord.push_back(x);
    for (ll y : nxt[x]) {
      if (visited[y]) continue;
      visited[y] = true;
      que.push(y);
    }
  }
  if ((ll)ord.size() < N) {
    cout << -1 << endl;
    return 0;
  }
  while (!ord.empty()) {
    ll y = ord.back(); ord.pop_back();
    cout << y << "\n";
  }
  

  

  return 0;
}

