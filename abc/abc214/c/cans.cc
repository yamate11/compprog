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

  using sta = pair<ll, ll>;
  ll N; cin >> N;
  vector<ll> S(N), T(N);
  for (ll i = 0; i < N; i++) cin >> S[i];
  for (ll i = 0; i < N; i++) cin >> T[i];
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  for (ll i = 0; i < N; i++) {
    pque.emplace(T[i], i);
  }
  vector<ll> ans(N, -1);
  while (! pque.empty()) {
    auto [t, i] = pque.top(); pque.pop();
    if (ans[i] >= 0) continue;
    ans[i] = t;
    pque.emplace(t + S[i], (i + 1) % N);
  }
  for (ll i = 0; i < N; i++) {
    cout << ans[i] << "\n";
  }
  

  return 0;
}

