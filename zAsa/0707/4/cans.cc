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

  string S; cin >> S;
  vector<ll> C(3);
  for (char c : S) C[c - 'a']++;
  ranges::sort(C);
  bool ans = false;
  if (C[0] == C[2]) ans = true;
  else if (C[1] == C[2]) ans = C[0] >= C[2] - 1;
  else ans = C[0] + C[1] >= 2 * (C[2] - 1);
  cout << (ans ? "YES\n" : "NO\n");

  return 0;
}

