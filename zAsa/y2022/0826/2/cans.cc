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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll p = 0;
  REP(i, 0, SIZE(S)) {
    if (p == 0 and (S[i] == 'I' or S[i] == 'i')) p++;
    else if (p == 1 and (S[i] == 'C' or S[i] == 'c')) p++;
    else if (p == 2 and (S[i] == 'T' or S[i] == 't')) p++;
  }
  if (p == 3) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}

