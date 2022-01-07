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

  ll l, r; cin >> l >> r;
  string s; cin >> s;
  string s1 = s.substr(0, l - 1);
  string s2 = s.substr(l - 1, r - l + 1);
  reverse(ALL(s2));
  string s3 = s.substr(r);
  cout << s1 + s2 + s3 << endl;

  return 0;
}

