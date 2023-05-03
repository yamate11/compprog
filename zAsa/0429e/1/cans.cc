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

  auto f = [&](string s) -> pair<ll, string> {
    ll num = 0;
    string stack;
    for (char c : s) {
      stack.push_back(c);
      ll k = SIZE(stack);
      if (k >= 3) {
        string t = stack.substr(k - 3, 3);
        if (t == "ABC" or t == "BCA" or t == "CAB") {
          num++;
          stack.resize(k - 3);
        }
      }
    }
    return {num, move(stack)};
  };

  ll N; cin >> N;
  string S, T; cin >> S >> T;
  auto [ns, ms] = f(S);
  auto [nt, mt] = f(T);
  cout << (ns == nt and ms == mt ? "YES" : "NO") << endl;

  return 0;
}

