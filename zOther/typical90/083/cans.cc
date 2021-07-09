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

  ll N, M; cin >> N >> M;
  auto nbr = vector(N + 1, vector<ll>());
  for (ll i = 1; i <= N; i++) nbr[i].push_back(i);
  for (ll i = 0; i < M; i++) {
    ll a, b; cin >> a >> b;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  ll thr = sqrt(M);
  vector<bool> busy(N + 1);
  for (ll i = 1; i <= N; i++) {
    if ((ll)nbr[i].size() >= thr) busy[i] = true;
  }
  vector busy_nbr(N + 1, vector<ll>());
  for (ll i = 1; i <= N; i++) {
    for (ll p : nbr[i]) if (busy[p]) busy_nbr[i].push_back(p);
  }
  vector<ll> BC(N + 1, 1);
  using sta = pair<ll, ll>;
  vector<sta> Ord(N + 1, sta(0, 1));
  ll Q; cin >> Q;
  for (ll t = 1; t <= Q; t++) {
    ll x, y; cin >> x >> y;
    if (busy[x]) {
      cout << BC[x] << "\n";
    }else {
      ll t0 = 0;
      ll col0 = 1;
      for (ll p : nbr[x]) {
        auto [rt, rc] = Ord[p];
        if (t0 < rt) {
          t0 = rt;
          col0 = rc;
        }
      }
      cout << col0 << "\n";
    }
    Ord[x] = sta(t, y);
    for (ll p : busy_nbr[x]) BC[p] = y;
  }

  return 0;
}

