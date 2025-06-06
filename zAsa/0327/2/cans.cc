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

  string S; cin >> S;
  ll N = ssize(S);
  REP(i, 0, N) {
    ll c = S[i] - '0';
    if (0 <= c and c <= 9) {
      if (i + 1 < N) {
        ll d = S[i + 1] - '0';
        if (0 <= d and d <= 9) {
          cout << c * 10 + d << endl;
          return 0;
        }
      }
      cout << c << endl;
      return 0;
    }
  }

  return 0;
}

