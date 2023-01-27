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
  N += 100000;
  N --;
  string s = to_string(N);
  string t(9, ' ');
  t[0] = s[0];
  t[1] = s[0];
  t[2] = s[1];
  t[3] = s[2];
  t[4] = s[3];
  t[5] = s[3];
  t[6] = s[4];
  t[7] = s[5];
  t[8] = s[4];
  cout << t << endl;

  return 0;
}

