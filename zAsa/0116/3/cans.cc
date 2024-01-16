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
  string S; cin >> S;
  
  ll i = 0;
  string t = "b";
  while (true) {
    if (S == t) {
      cout << i << endl;
      return 0;
    }else if (SIZE(S) < SIZE(t)) {
      cout << -1 << endl;
      return 0;
    }
    i++;
    if (i % 3 == 1) t = "a" + t + "c";
    else if (i % 3 == 2) t = "c" + t + "a";
    else if (i % 3 == 0) t = "b" + t + "b";
    else assert(0);
  }

  return 0;
}

