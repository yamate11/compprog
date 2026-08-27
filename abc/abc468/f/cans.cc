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
  // @InpVec(N, P, dec=1) [WlVuiK2j]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [WlVuiK2j]

  ll x = -1;
  ll cnt1 = 0;
  vector<ll> Q;
  REP(i, 0, N) {
    if (P[i] > x) {
      x = P[i];
      cnt1++;
    } else {
      Q.push_back(P[i]);
    }
  }
  vector<ll> vec;
  for (ll q : Q) {
    ll j = ranges::lower_bound(vec, q) - vec.begin();
    if (j == ssize(vec)) vec.push_back(q);
    else vec[j] = q;
  }
  ll ans = cnt1 + ssize(vec);
  cout << ans << endl;

  return 0;
}

