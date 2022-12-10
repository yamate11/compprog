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
  // @InpVec(N, A) [S05OVCP6]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [S05OVCP6]
  ll base = 0;
  vector<ll> diff;
  REP(i, 0, N) diff.push_back(i);
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x; cin >> x;
      base = x;
      for (ll d : diff) A[d] = 0;
      diff = vector<ll>();
    }else if (tp == 2) {
      ll i, x; cin >> i >> x; i--;
      A[i] += x;
      diff.push_back(i);
    }else if (tp == 3) {
      ll i; cin >> i; i--;
      cout << base + A[i] << "\n";
    }
  }


  return 0;
}

