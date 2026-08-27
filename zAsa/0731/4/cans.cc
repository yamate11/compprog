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

  string atc = "atcoder";

  ll T; cin >> T;
  REP(t, 0, T) {
    string S; cin >> S;
    auto f = [&]() -> ll {
      if (atc < S) return 0;
      else {
        assert(S[0] == 'a');
        if (ssize(S) == 1) return -1;
        else {
          if (S[1] > 'a') return 1;
          else {
            REP(i, 2, ssize(S)) {
              if (S[i] > 't') return i - 1;
              if (S[i] > 'a') return i;
            }
            return -1;
          }
        }
      }
    };
    cout << f() << "\n";
  }
  return 0;
}

