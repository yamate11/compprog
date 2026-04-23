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

  auto solve = [&]() -> bool {
    auto f = [&](string s) -> string {
      string ret;
      for (char c : s) {
        auto cond = [&]() -> bool {
          ll n = ssize(ret);
          if (n >= 3 and ret[n - 1] == 'x' and ret[n - 2] == 'x' and ret[n - 3] == '(') return true;
          else return false;
        };
        if (c == ')' and cond()) {
          ret.pop_back();
          ret.pop_back();
          ret.pop_back();
          ret += "xx";
        }else {
          ret.push_back(c);
        }
      }
      return ret;
    };


    string A; cin >> A;
    string B; cin >> B;
    string p = f(A);
    string q = f(B);
    return p == q;
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

