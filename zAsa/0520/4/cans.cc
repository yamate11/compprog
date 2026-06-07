#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K, M, R; cin >> N >> K >> M >> R;
  // @InpVec(N -1, S) [BYm4KLe3]
  auto S = vector(N -1, ll());
  for (int i = 0; i < N -1; i++) { ll v; cin >> v; S[i] = v; }
  // @End [BYm4KLe3]

  ranges::sort(S, greater<ll>());
  ll x = accumulate(S.begin(), S.begin() + K - 1, 0LL);
  ll req = K * R;
  ll ans;
  if (x >= req) ans = 0;
  else if (K < N and x + S[K - 1] >= req) ans = 0;
  else if (x + M < req) ans = -1;
  else ans = req - x;
  cout << ans << endl;

  return 0;
}

