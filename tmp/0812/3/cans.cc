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

#define EXISTS_C(x, coll, cond) \
  ([&](){for (auto x: coll) if (cond) return true; return false;}())

bool solve() {
  string S; cin >> S;
  vector<string> choice{"", "A"};
  return EXISTS_C(t1, choice,
         EXISTS_C(t2, choice,
         EXISTS_C(t3, choice,
         EXISTS_C(t4, choice,
                  S == t1 + "KIH" + t2 + "B" + t3 + "R" + t4))));
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

