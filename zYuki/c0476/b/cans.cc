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

  ll N; cin >> N;
  // @InpVec(N, P, dec=1) [HPfewXxb]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [HPfewXxb]

  vector<bool> tops(N, true);
  REP(i, 0, N) if (P[i] >= 0) tops[P[i]] = false;
  vector<bool> ans(N, false);
  REP(i, 0, N) {
    if (tops[i]) {
      ll x = P[i];
      if (x >= 0) {
        ll y = P[x];
        if (y >= 0) ans[y] = true;
      }
    }
  }
  ll cnt = 0;
  REP(i, 0, N) if (ans[i]) cnt++;
  cout << cnt << endl;

  return 0;
}

