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

  ll N; cin >> N;
  // @InpMVec(N, ((S, type=string), P)) [MUZwUiwa]
  auto S = vector(N, string());
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) {
    string v1; cin >> v1; S[i] = v1;
    ll v2; cin >> v2; P[i] = v2;
  }
  // @End [MUZwUiwa]
  vector ord(N, 0LL);
  REP(i, 0, N) ord[i] = i;
  sort(ALL(ord), [&](ll i, ll j) -> bool {
    if (S[i] == S[j]) return P[i] > P[j];
    else return S[i] < S[j];
  });
  REPOUT(i, 0, N, ord[i] + 1, "\n");

  return 0;
}

