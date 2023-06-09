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
    ll N; cin >> N;
    // @InpNbrList(N, N - 1, nbr, dec=1) [MprpEbCK]
    auto nbr = vector(N, vector(0, int()));
    for (int i = 0; i < N - 1; i++) {
      int u, v; cin >> u >> v; u -= 1; v -= 1;
      nbr[u].emplace_back(v);
      nbr[v].emplace_back(u);
    }
    // @End [MprpEbCK]
    string S; cin >> S;
    string ans(N, ' ');
    ll seq = 0;
    vector<ll> tol(N);
    vector<ll> st;
    REP(i, 0, N) {
      tol[i] = (SIZE(nbr[i]) - 1) / 2;
      if (tol[i] == 0) st.push_back(i);
    }
    while (true) {
      while (not st.empty()) {
        ll nd = st.back(); st.pop_back();
        ll cntF = 0, cntA = 0;
        for (ll peer : nbr[nd]) {
          if (ans[peer] == ' ') {
            ans[peer] = S[nd];
            cntF++;
            for (ll z : nbr[peer]) {
              if (S[z] != S[nd]) {
                tol[z]--;
                if (tol[z] <= 0) st.push_back(z);
              }
            }
          }else if (ans[peer] == S[nd]) cntF++;
          else cntA++;
        }
        if (cntA > cntF) {
          cout << -1 << "\n";
          return;
        }
      }
      while (seq < N and ans[seq] != ' ') seq++;
      if (seq == N) break;
      ans[seq] = 'B';
      for (ll z : nbr[seq]) {
        if (S[z] == 'W') {
          tol[z]--;
          if (tol[z] <= 0) st.push_back(z);
        }
      }
    }
    cout << ans << "\n";
  };

  ll T; cin >> T;
  REP(i, 0, T) solve();

  return 0;
}

