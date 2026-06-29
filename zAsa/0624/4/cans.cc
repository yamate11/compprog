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
  ll len = ssize(S);
  while (len > 0) {
    if      (len >= 5 and S.substr(len - 5, 5) == "dream")   len -= 5;
    else if (len >= 7 and S.substr(len - 7, 7) == "dreamer") len -= 7;
    else if (len >= 5 and S.substr(len - 5, 5) == "erase")   len -= 5;
    else if (len >= 6 and S.substr(len - 6, 6) == "eraser")  len -= 6;
    else {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}

