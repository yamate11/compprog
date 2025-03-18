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

  vector<ll> v(4);
  REP(i, 0, 4) cin >> v[i];
  sort(ALL(v));
  bool ans = false;
  if (v[0] != v[1] and v[1] == v[2] and v[2] == v[3]) ans = true;
  if (v[0] == v[1] and v[1] == v[2] and v[2] != v[3]) ans = true;
  if (v[0] == v[1] and v[1] != v[2] and v[2] == v[3]) ans = true;
  cout << (ans ? "Yes\n" : "No\n");

  return 0;
}

