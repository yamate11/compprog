#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, B, M; cin >> A >> B >> M;
  vector<ll> vecA(A), vecB(B);
  ll minA = (ll)1e9;
  ll minB = (ll)1e9;
  for (ll i = 0; i < A; i++) {
    ll a; cin >> a;
    minA = min(minA, a);
    vecA.at(i) = a;
  }
  for (ll i = 0; i < B; i++) {
    ll b; cin >> b;
    minB = min(minB, b);
    vecB.at(i) = b;
  }
  ll ans = minA + minB;
  for (ll i = 0; i < M; i++) {
    ll x, y, c; cin >> x >> y >> c; x--; y--;
    ll val = vecA.at(x) + vecB.at(y) - c;
    ans = min(ans, val);
  }
  cout << ans << endl;

  return 0;
}

