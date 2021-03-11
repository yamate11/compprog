#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, D, A; cin >> N >> D >> A;
  vector<pair<ll, ll>> xh(N);
  for (ll i = 0; i < N; i++) {
    ll x, h; cin >> x >> h;
    xh.at(i) = make_pair(x, h);
  }
  sort(xh.begin(), xh.end());

  vector<ll> rec(N);
  ll j = 0;
  ll cnt = 0;
  ll eff = 0;
  for (ll i = 0; i < N; i++) {
    for ( ; j < i && xh.at(i).first - xh.at(j).first > 2*D; j++) {
      eff -= rec.at(j);
    }
    ll rem = xh.at(i).second - eff * A;
    ll amt = rem <= 0 ? 0 : (rem + (A-1)) / A;
    rec.at(i) = amt;
    eff += amt;
    cnt += amt;
  }
  cout << cnt << endl;

  return 0;
}

