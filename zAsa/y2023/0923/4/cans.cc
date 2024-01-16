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

  auto f = [&](string s) -> string {
    ll n = SIZE(s);
    ll seq = 0;
    auto rec = vector(26, -1LL);
    REP(i, 0, n) {
      ll d = s[i] - 'a';
      if (rec[d] < 0) rec[d] = seq++;
    }
    string ret;
    REP(i, 0, n) ret.push_back('A' + rec[s[i] - 'a']);
    return ret;
  };

  string S, T; cin >> S >> T;
  cout << (f(S) == f(T) ? "Yes\n" : "No\n");

  return 0;
}

