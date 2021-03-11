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
  ll K = 1 << N;
  using ElemT = tuple<ll, ll, ll>;
  vector<vector<ElemT>> winner(N+1);
  vector<ElemT>& v1 = winner.at(N);
  for (ll i = 0; i < K; i++) {
    ll a; cin >> a;
    v1.emplace_back(a, i, -1);
  }
  for (ll n = N-1; n >= 0; n--) {
    vector<ElemT>& v = winner.at(n);
    const vector<ElemT>& w = winner.at(n+1);
    for (ll i = 0; i < (1 << n); i++) {
      ll x = i << 1 | 0;
      ll y = i << 1 | 1;
      ll ax, wx, lx; tie(ax, wx, lx) = w.at(x);
      ll ay, wy, ly; tie(ay, wy, ly) = w.at(y);
      if (ax > ay) {
	v.emplace_back(ax, wx, wy);
      }else {
	v.emplace_back(ay, wy, wx);
      }
    }
  }
  vector<ll> ans(K);
  for (ll n = 0; n <= N-1; n++) {
    for (ll i = 0; i < (1 << n); i++) {
      ll z = get<2>(winner.at(n).at(i));
      ans.at(z) = N - n;
    }
  }
  ll ww = get<1>(winner.at(0).at(0));
  ans.at(ww) = N;

  for (ll i = 0; i < K; i++) { cout << ans.at(i) << "\n"; }
  return 0;
}

