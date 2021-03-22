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

  ll H, W, A, B; cin >> H >> W >> A >> B;
  if (H > W) swap(H, W);
  ll psz = 1LL << (2*H);
  auto cur = vector(psz, vector(A + 1, vector(B + 1, 0LL)));
  cur[0][A][B] = 1;
  auto gettype = [&](ll x, ll i) -> ll {
    return (x >> (2*i)) & 3LL;
  };
  auto sanity = [&](ll x) -> bool {
    bool above = false;
    for (ll i = 0; i < H; i++) {
      ll t = gettype(x, i);
      if (above) {
        if (t != 0) return false;
      }
      above = (t == 3);
    }
    if (above) return false;
    return true;
  };
  auto match = [&](ll x, ll y) -> pair<ll, ll> {
    ll reta = 0;
    ll retb = 0;
    if (gettype(y, H-1) == 3) return {-1, -1};
    for (ll i = 0; i < H; i++) {
      ll tx = gettype(x, i);
      ll ty = gettype(y, i);
      if (ty == 0) {
        if (i > 0 && gettype(y, i-1) == 3) {
        }else if (tx == 2) {
        }else {
          return {-1, -1};
        }
      }else {
        if (i > 0 && gettype(y, i-1) == 3) return {-1, -1};
        else if (tx == 2) return {-1, -1};
      }
      if (ty == 0) ;
      else if (ty == 1) retb++;
      else reta++;
    }
    return {reta, retb};
  };
  for (ll i = 0; i < W; i++) {
    auto prev = move(cur);
    cur = vector(psz, vector(A + 1, vector(B + 1, 0LL)));
    for (ll x = 0; x < psz; x++) {
      if (!sanity(x)) continue;
      for (ll y = 0; y < psz; y++) {
        if (!sanity(y)) continue;
        auto [da, db] = match(x, y);
        if (da < 0) continue;
        for (ll a = da; a <= A; a++) {
          for (ll b = db; b <= B; b++) {
            cur[y][a - da][b - db] += prev[x][a][b];
          }
        }
      }
    }
  }
  ll ans = 0;
  for (ll x = 0; x < psz; x++) {
    ans += cur[x][0][0];
  }
  cout << ans << endl;

  return 0;
}

