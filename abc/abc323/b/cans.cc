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
  // @InpVec(N, S, type=string) [cTrTwBMR]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [cTrTwBMR]

  vector win(N, 0LL);
  REP(i, 0, N) REP(j, i + 1, N) {
    if (S[i][j] == 'o') win[i]++;
    else win[j]++;
  }
  vector ord(N, 0LL);
  REP(i, 0, N) ord[i] = i;
  sort(ALL(ord),
       [&](ll i, ll j) -> bool {
         if (win[i] != win[j]) return win[i] > win[j];
         return i < j;
       });
  REPOUT(i, 0, N, ord[i] + 1, " ");

  return 0;
}

