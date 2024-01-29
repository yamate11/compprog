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

  auto solve = [&]() -> void {
    ll N, K, M; cin >> N >> K >> M;
    string S; cin >> S;
    ll cycle = 0;
    string ans = "";
    vector<bool> occur(K, false);
    ll k = 0;
    REP(i, 0, M) {
      ll d = S[i] - 'a';
      if (not occur[d]) {
        occur[d] = true;
        k++;
        if (k == K) {
          ans.push_back(S[i]);
          cycle++;
          if (cycle == N) {
            cout << "YES\n";
            return;
          }
          occur = vector<bool>(K, false);
          k = 0;
        }
      }
    }
    REP(d, 0, K) {
      if (not occur[d]) {
        ans.push_back('a' + d);
        break;
      }
    }
    REP(i, cycle + 1, N) ans.push_back('a');
    cout << "NO\n";
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

