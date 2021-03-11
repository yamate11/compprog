#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll N = S.size();
  ll X = 0;
  for (ll i = 0; i < N; i++) if (S.at(i) == 'o') X |= (1LL << i);
  auto shift = [&] (ll x, ll s) -> ll{
    return ((x << s) & ((1LL << N) - 1)) | (x >> (N - s));
  };
  ll vmin = N;
  for (ll y = 0; y < (1LL << N); y++) {
    ll cov = 0;
    for (ll i = 0; i < N; i++) if ((y >> i) & 1)  cov |= shift(X, i);
    if (cov == (1LL << N) - 1) vmin = min<ll>(vmin, __builtin_popcountll(y));
  }
  cout << vmin << endl;

  return 0;
}

