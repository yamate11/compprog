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

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, R) [CMRRyzhc]
  auto R = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; R[i] = v; }
  // @End [CMRRyzhc]
  sort(ALL(R));
  vector<ll> S(N + 1);
  REP(i, 0, N) S[i + 1] = S[i] + R[i];
  REP(_q, 0, Q) {
    ll x; cin >> x;
    ll i = upper_bound(ALL(S), x) - S.begin();
    cout << i - 1 << "\n";
  }

  return 0;
}

