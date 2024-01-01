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

  ll N, A, B; cin >> N >> A >> B;
  // @InpMVec(N, ((S, type=string), D)) [LmKuCmZy]
  auto S = vector(N, string());
  auto D = vector(N, ll());
  for (int i = 0; i < N; i++) {
    string v1; cin >> v1; S[i] = v1;
    ll v2; cin >> v2; D[i] = v2;
  }
  // @End [LmKuCmZy]

  ll cur = 0;
  REP(i, 0, N) {
    ll sign = (S[i] == "East") ? 1 : -1;
    ll x = D[i];
    if (x < A) x = A;
    if (x > B) x = B;
    cur += sign * x;
  }
  if (cur == 0) cout << 0 << endl;
  else if (cur > 0) cout << "East " << cur << endl;
  else cout << "West " << -cur << endl;

  return 0;
}

