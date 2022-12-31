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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<string> names{"Do", "Re", "Mi", "Fa", "So", "La", "Si"};
  vector<ll> pos{0,2,4,5,7,9,11};
  string kb = "WBWBWWBWBWBW";
  kb = kb + kb + kb;
  string S; cin >> S;
  REP(i, 0, 7) {
    ll p = pos[i];
    if (kb.substr(p, 20) == S) {
      cout << names[i] << endl;
      return 0;
    }
  }
  assert(0);

  return 0;
}

