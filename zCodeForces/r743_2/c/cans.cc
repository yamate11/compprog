#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    using sta = pair<ll, ll>;
    auto comp = [&](sta x, sta y) -> bool {
      auto [x_round, x_idx] = x;
      auto [y_round, y_idx] = y;
      if (x_round != y_round) return x_round > y_round;
      return x_idx > y_idx;
    };
    priority_queue<sta, vector<sta>, decltype(comp)> pque(comp);

    ll N; cin >> N;
    vector<ll> numR(N + 1);
    vector<vector<ll>> fwd(N + 1);
    ll done = 0;
    ll cnt = 0;
    for (ll i = 1; i <= N; i++) {
      ll k; cin >> k;
      numR[i] = k;
      if (k == 0) {
        pque.emplace(1, i);
        done++;
      }
      for (ll j = 0; j < k; j++) {
        ll x; cin >> x;
        fwd[x].push_back(i);
      }
    }
    while (! pque.empty()) {
      auto [r, idx] = pque.top(); pque.pop();
      cnt = r;
      for (ll y : fwd[idx]) {
        numR[y]--;
        if (numR[y] == 0) {
          done++;
          if (idx < y) pque.emplace(r, y);
          else         pque.emplace(r + 1, y);
        }
      }
    }
    if (done < N) { cout << -1 << "\n"; }
    else { cout << cnt << "\n"; }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

