#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, X; cin >> N >> M >> X;
  vector<ll> C(N);
  vector A(N, vector<ll>(M));
  for (ll i = 0; i < N; i++) {
    cin >> C.at(i);
    for (ll j = 0; j < M; j++) cin >> A.at(i).at(j);
  }
  ll ans = LLONG_MAX;
  vector<ll> skill(M);
  auto dfs = [&](const auto& cmpF, ll n, ll cost) -> void {
    if (n == N) {
      ll ok = true;
      for (ll j = 0; j < M; j++) {
	if (skill.at(j) < X) {
	  ok = false;
	  break;
	}
      }
      if (ok && cost < ans) ans = cost;
    }else {
      cmpF(cmpF, n+1, cost);
      for (ll j = 0; j < M; j++) {
	skill.at(j) += A.at(n).at(j);
      }
      cmpF(cmpF, n+1, cost + C.at(n));
      for (ll j = 0; j < M; j++) {
	skill.at(j) -= A.at(n).at(j);
      }
    }
  };
  dfs(dfs, 0, 0);

  if (ans == LLONG_MAX) {
    cout << -1 << endl;
  }else {
    cout << ans << endl;
  }

  return 0;
}

