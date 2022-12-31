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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  bool b1 = false, b2 = false, b3 = false, b4 = false;
  REP(i, 0, 4) {
    string s; cin >> s;
    if (s == "H") b1 = true;
    else if (s == "2B") b2 = true;
    else if (s == "3B") b3 = true;
    else if (s == "HR") b4 = true;
  }
  cout <<  (b1 and b2 and b3 and b4 ? "Yes" : "No") << endl;

  return 0;
}

