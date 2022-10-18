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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, S, type=(char, int), dec='0') [HhR7u2uF]
  auto S = vector(N, int());
  for (int i = 0; i < N; i++) { char v; cin >> v; v -= '0'; S[i] = v; }
  // @End [HhR7u2uF]
  // @InpVec(N, T, type=(char, int), dec='0') [FXkigEQ6]
  auto T = vector(N, int());
  for (int i = 0; i < N; i++) { char v; cin >> v; v -= '0'; T[i] = v; }
  // @End [FXkigEQ6]
  ll i = 0;
  ll cnt = 0;
  while (i < N) {
    while (i < N and S[i] == T[i]) i++;
    if (i == N) break;
    ll diff = 0;
    while (true) {
      if (i == N) {
        cout << -1 << endl;
        return 0;
      }
      diff += S[i] - T[i];
      if (S[i] == 0) cnt++;
      i++;
      if (diff == 0) break;
    }
  }
  cout << cnt << endl;

  return 0;
}

