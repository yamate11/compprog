#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string s; cin >> s;
  char c = 'a';
  ll p = 0;
  ll q = N - 1;
  while (true) {
    while (p < q and s[p] == c) p++;
    if (p == q) break;
    for (ll r = q; r > p; r--) {
      if (s[r] == c) {
        swap(s[p], s[r]);
        q = r - 1;
        p++;
        while (p < q and s[p] == c) p++;
      }
    }
    if (c == 'z') break;
    c++;
  }
  cout << s << endl;
  return 0;
}

