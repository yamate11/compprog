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

  auto solve = [&]() -> void {
    ll N, C; cin >> N >> C; C--;
    // @InpVec(N, S, type=string) [0Ayo12DO]
    auto S = vector(N, string());
    for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
    // @End [0Ayo12DO]

    vector vec(N, vector<ll>());
    REP(i, 0, N) REP(j, 0, N) if (S[i][j] == '#') vec[j].push_back(i);
    vector cur(N, false);
    cur[C] = true;
    REPrev(i, N - 2, 0) {
      auto prev = move(cur);
      cur = vector(N, false);
      REP(j, 0, N) {
        if (prev[j]) {
          REP(d, -1, 2) {
            ll k = j + d;
            if (0 <= k and k < N) {
              if (S[i][k] == '#' and vec[k].back() == i) {
                S[i][k] = '.';
                vec[k].pop_back();
                cur[k] = true;
              }else if (S[i][k] == '.') {
                cur[k] = true;
              }
            }
          }
        }
      }
    }
    string ans(N, '0');
    REP(i, 0, N) if (cur[i]) ans[i] = '1';
    cout << ans << "\n";

  };


  ll T; cin >> T;
  REP(t, 0, T) solve();


  return 0;
}

