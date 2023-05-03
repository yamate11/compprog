#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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

  ll N, W; cin >> N >> W;
  // @InpMVec(N, (S, T, P)) [hbGW16i5]
  auto S = vector(N, ll());
  auto T = vector(N, ll());
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; S[i] = v1;
    ll v2; cin >> v2; T[i] = v2;
    ll v3; cin >> v3; P[i] = v3;
  }
  // @End [hbGW16i5]

  ll lim = 2e5;
  vector<ll> diff(lim + 1);
  REP(i, 0, N) {
    diff[S[i]] += P[i];
    diff[T[i]] -= P[i];
  }
  ll cur = 0;
  REP(i, 0, lim + 1) {
    cur += diff[i];
    if (cur > W) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  return 0;
}

