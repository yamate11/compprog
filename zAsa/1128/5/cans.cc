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

  ll N; cin >> N;
  REP(K, 1, N + 10) {
    if (K * (K - 1) == 2 * N) {
      cout << "Yes\n";
      cout << K << "\n";
      vector S(K, vector<ll>());
      ll t = 1;
      REP(i, 0, K) REP(j, i + 1, K) {
        S[i].push_back(t);
        S[j].push_back(t);
        t++;
      }
      REP(i, 0, K) {
        cout << SIZE(S[i]);
        for (ll p : S[i]) cout << " " << p;
        cout << "\n";
      }

      return 0;
    }
  }
  cout << "No\n";

  return 0;
}

