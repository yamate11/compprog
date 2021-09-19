#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(f:updMaxMin)

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll X, Y; cin >> X >> Y;
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; i++) cin >> A[i] >> B[i];
  
  const ll big = 1e10;
  auto cur_init = vector(X + 1, vector(Y + 1, big));
  auto cur = cur_init;
  cur[0][0] = 0;
  for (ll i = 0; i < N; i++) {
    auto prev = move(cur);
    cur = cur_init;
    for (ll x = 0; x <= X; x++) {
      for (ll y = 0; y <= Y; y++) {
        if (prev[x][y] < 0) continue;
        updMin(cur[x][y], prev[x][y]);
        ll newX = min(x + A[i], X);
        ll newY = min(y + B[i], Y);
        updMin(cur[newX][newY], prev[x][y] + 1);
      }
    }
  }
  ll ans = cur[X][Y];
  if (ans >= big) ans = -1;
  cout << ans << endl;

  return 0;
}

