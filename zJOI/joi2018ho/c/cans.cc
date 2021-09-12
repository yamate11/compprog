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

  ll N, M; cin >> N >> M;
  vector<string> S(N);
  for (ll i = 0; i < N; i++) cin >> S[i];

  auto get = [&](const auto& vec, ll i) -> ll {
    if (0 <= i && i < (ll)vec.size()) return vec[i];
    return 0;
  };

  ll ans = 0;
  for (ll p = 0; p < N + M - 3; p++) {
    ll len = [&]() -> ll {
      if (p < min(N, M)) return p + 1;
      if (p < max(N, M)) return min(N, M);
      return N + M - p - 1;
    }();
    ll startI = (p < M) ? 0 : p - M + 1;
    vector<ll> wH(len), wV(len);
    for (ll q = 0; q < len; q++) {
      ll i = startI + q;
      ll j = p - i;
      ll hseq = 0, vseq = 0;
      if (j+2 < M && S[i][j] == 'R' && S[i][j+1] == 'G' && S[i][j+2] == 'W') {
        hseq = 1;
      }
      if (i+2 < N && S[i][j] == 'R' && S[i+1][j] == 'G' && S[i+2][j] == 'W') {
        vseq = 1;
      }
      wH[q] = hseq + max(get(wH, q-1), get(wV, q-3));
      wV[q] = vseq + max(get(wH, q-1), get(wV, q-1));
    }
    ll valP = max(wH[len - 1], wV[len - 1]);
    ans += valP;
  }
  cout << ans << endl;

  return 0;
}

