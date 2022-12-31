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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, P, dec=0) [Vfrl6UEW]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 0; P[i] = v; }
  // @End [Vfrl6UEW]
  // @InpVec(N, Q, dec=0) [2U2ZmQg0]
  auto Q = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 0; Q[i] = v; }
  // @End [2U2ZmQg0]
  vector<ll> revQ(N + 1);
  REP(i, 0, N) revQ[Q[i]] = i;
  vector<ll> vec{0};
  REP(i, 0, N) {
    vector<ll> mpos;
    for (ll m = P[i]; m <= N; m += P[i]) mpos.push_back(revQ[m]);
    sort(ALL(mpos), greater<ll>());
    for (ll m : mpos) {
      ll idx = upper_bound(ALL(vec), m) - vec.begin();
      if (idx >= SIZE(vec)) vec.push_back(m + 1);
      else vec[idx] = m + 1;
    }
  }
  cout << SIZE(vec) - 1 << endl;

  return 0;
}

