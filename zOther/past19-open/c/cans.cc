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

  string N; cin >> N;
  ll k = ssize(N);

  auto f = [&](string& s) -> bool {
    REP(i, 0, k - 1) {
      if (abs(s[i] - s[i + 1]) >= 2) return false;
    }
    return true;
  };

  bool ans = false;
  auto check = [&]() -> bool {
    if (f(N)) return true;
    REP(i, 0, k) {
      string s = N;
      REP(d, 0, 10) {
        if (i == 0 and d == 0) continue;
        s[i] = (char)('0' + d);
        if (f(s)) return true;
      }
    }
    return false;
  };
  ans = check();
  cout << (ans ? "Yes\n" : "No\n");
  

  return 0;
}

