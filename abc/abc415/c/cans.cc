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
    ll N; cin >> N;
    string S; cin >> S;
    vector<bool> V(1LL << N);
    V[0] = true;
    REP(x, 1, 1LL << N) {
      V[x] = false;
      if (S[x - 1] == '1') V[x] = false;
      else {
        REP(i, 0, N) {
          if (x >> i & 1) {
            ll y = x ^ (1LL << i);
            if (V[y]) {
              V[x] = true;
              break;
            }
          }
        }
      }
    }
    return V[(1LL << N) - 1];
  };

  ll T; cin >> T;
  REP(t, 0, T) {
    cout << (solve() ? "Yes\n" : "No\n");
  }

  return 0;
}

