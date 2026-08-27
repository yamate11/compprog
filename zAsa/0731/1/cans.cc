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

  vector judge(128, false);
  judge['A'] = true;
  judge['C'] = true;
  judge['G'] = true;
  judge['T'] = true;

  ll ans = 0;
  string S; cin >> S;
  ll N = ssize(S);
  ll j = 0;
  for (ll i = 0; i < N; i = j + 1) {
    for (j = i; j < N and judge[S[j]]; j++);
    ans = max(ans, j - i);
  }
  cout << ans << endl;
  return 0;
}

