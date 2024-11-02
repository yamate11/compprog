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

  // @InpVec(12, S, type=string) [0VTDAxOP]
  auto S = vector(12, string());
  for (int i = 0; i < 12; i++) { string v; cin >> v; S[i] = v; }
  // @End [0VTDAxOP]

  ll cnt = 0;
  REP(i, 0, 12) {
    if (ssize(S[i]) == i + 1) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

