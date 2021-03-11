#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N);
  ll lim = 0;
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
    lim = max(lim, A[i]);
  }
  vector<ll> cnt(lim + 1), R1(lim + 1), R2(lim + 1);
  for (ll i = 0; i < N; i++) {
    ll x = A[i];
    if (cnt[x] == 0) R1[x] = i;
    else if (cnt[x] == 1) R2[x] = i;
    cnt[x]++;
  }
  ll vmin = LLONG_MAX;
  ll ans1 = -1, ans2 = -1;
  auto upd = [&](ll v, ll x, ll y) -> void {
    if (vmin > v) {
      vmin = v;
      ans1 = R1[x];
      ans2 = x == y ? R2[y] : R1[y];
    }
  };
  for (ll k = 1; k <= lim; k++) {
    ll x = 0;
    for (ll p = k; p <= lim; p += k) {
      if (cnt[p] == 0) continue;
      else if (x > 0) {
        upd(x * p / k, x, p);
        break;
      }else if (cnt[p] >= 2) {
        upd(p * p / k, p, p);
        break;
      }else {
        x = p;
      }
    }
  }
  if (ans1 > ans2) swap(ans1, ans2);
  cout << ans1 + 1 << " " << ans2 + 1 << endl;

  return 0;
}

