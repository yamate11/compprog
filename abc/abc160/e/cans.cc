#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
  vector<ll> P(A), Q(B), R(C);
  for (ll i = 0; i < A; i++) cin >> P.at(i);
  for (ll i = 0; i < B; i++) cin >> Q.at(i);
  for (ll i = 0; i < C; i++) cin >> R.at(i);
  sort(P.begin(), P.end(), greater<ll>());
  sort(Q.begin(), Q.end(), greater<ll>());
  sort(R.begin(), R.end(), greater<ll>());
  vector<ll> V;
  for (ll i = 0; i < X; i++) V.push_back(P.at(i));
  for (ll i = 0; i < Y; i++) V.push_back(Q.at(i));
  sort(V.begin(), V.end());
  ll lim = min(X+Y, C);
  for (ll i = 0; i < lim; i++) {
    if (V.at(i) < R.at(i)) V.at(i) = R.at(i);
    else break;
  }
  ll ans = 0;
  for (ll v : V) ans += v;
  cout << ans << endl;
  

  return 0;
}

