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
  // @InpVec(N, S, type=string) [lmkE3sji]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [lmkE3sji]

  auto f = [&](char c) -> char {
    if (c < 'd') return '2';
    if (c < 'g') return '3';
    if (c < 'j') return '4';
    if (c < 'm') return '5';
    if (c < 'p') return '6';
    if (c < 't') return '7';
    if (c < 'w') return '8';
    return '9';
  };

  string ans;
  REP(i, 0, N) {
    ans += f(S[i][0]);
  }
  cout << ans << endl;

  return 0;
}

