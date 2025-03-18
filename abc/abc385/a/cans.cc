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

  auto f = [&]() -> bool {
    vector<ll> v(3);
    REP(i, 0, 3) {
      ll a;
      cin >> a;
      v[i] = a;
    }
    sort(ALL(v));
    if (v[0] == v[1] and v[1] == v[2]) return true;
    if (v[0] + v[1] == v[2]) return true;
    return false;
  };
  cout << (f() ? "Yes\n" : "No\n");

  return 0;
}

