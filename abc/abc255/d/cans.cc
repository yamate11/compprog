#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using pll = pair<ll, ll>;
  ll N, Q; cin >> N >> Q;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  sort(ALL(A));
  vector<ll> ans(Q);
  vector<pll> XI;
  REP(i, Q) {
    ll x; cin >> x;
    XI.emplace_back(x, i);
  }
  sort(ALL(XI));
  auto [x0, i0] = XI[0];
  ll vL = 0, vG = 0;
  ll numL = 0;
  REP(i, N) {
    if (A[i] < x0) { vL += x0 - A[i]; numL++; }
    else           { vG += A[i] - x0; }
  }
  ans[i0] = vL + vG;
  ll j = numL;
  REP2(z, 1, Q) {
    auto [xprev, iprev] = XI[z - 1];
    auto [xx, ii] = XI[z];
    ll cnt = 0;
    vL += j * (xx - xprev);
    while (j < N and A[j] < xx) {
      vG -= A[j] - xprev;
      vL += xx - A[j];
      cnt++;
      j++;
    }
    vG -= (N - j) * (xx - xprev);
    ans[ii] = vL + vG;
  }
  for (ll a : ans) cout << a << "\n";
  return 0;
}

