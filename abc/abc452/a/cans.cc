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

  ll m, d; cin >> m >> d;
  bool b = false;
  if (m == 1 and d == 7) b = true;
  if (m == 3 and d == 3) b = true;
  if (m == 5 and d == 5) b = true;
  if (m == 7 and d == 7) b = true;
  if (m == 9 and d == 9) b = true;
  cout << (b ? "Yes\n" : "No\n");


  return 0;
}

