#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

using Vec1 = vector<ll>;
using Vec2 = vector<Vec1>;
using Vec3 = vector<Vec2>;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll X, Y; cin >> X >> Y;
  ll N; cin >> N;
  vector<ll> T(N), H(N);
  for (ll i = 0; i < N; i++) cin >> T.at(i) >> H.at(i);

  Vec3 tbl(N+1, Vec2(X+1, Vec1(Y+1, -1)));
  
  auto getn = [&](const auto& recF, ll n, ll x, ll y) -> ll {
    ll& ret = tbl.at(n).at(x).at(y);
    if (ret == -1) {
      if (n == N || x == 0) {
	ret = 0; 
      }else if (T.at(n) <= x + y) {
	ll val = (T.at(n) - 1 <= y) ? recF(recF, n+1, x-1, y - (T.at(n) - 1)) :
	                              recF(recF, n+1, x - (T.at(n) - y), 0);
	ret = max(recF(recF, n+1, x, y), H.at(n) + val);
      }else {
	ret = recF(recF, n+1, x, y);
      }
    }
    return ret;
  };
  cout << getn(getn, 0, X, Y) << endl;

  return 0;
}

