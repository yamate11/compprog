#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  enum { RUN, MAINT };
  ll N, M; cin >> N >> M;
  vector<ll> X(N), Y(N);
  vector<ll> stat(N, -1);           // start_date or -1
  using sta = pair<ll, ll>;
  vector<vector<sta>> high_ev(M);   // { train_id, start_date }
  REP(i, N) cin >> X[i] >> Y[i];
  vector<ll> op(M), K(M);
  REP(i, M) { cin >> op[i] >> K[i]; K[i]--; }
  const ll border = 450;
  vector low_ev(border, vector(border, 0LL));

  ll num_maint = 0;
  vector<ll> ans(M);
  REP(m, M) {
    REP2(c, 2, border) num_maint += low_ev[c][m % c];
    for (auto [k, m0] : high_ev[m]) {
      if (stat[k] != m0) continue;
      ll cycle = X[k] + Y[k];
      ll nxt = -1;
      if ((m - m0) % cycle == 0) {
        num_maint--;
        nxt = m + X[k];
      }else {
        num_maint++;
        nxt = m + Y[k];
      }
      if (nxt < M) high_ev[nxt].emplace_back(k, m0);
    }
    {
      ll k = K[m];
      ll cycle = X[k] + Y[k];
      if (op[m] == 1) {
        stat[k] = m;
        ll nxt = m + X[k];
        if (cycle < border) {
          low_ev[cycle][m % cycle] --;
          low_ev[cycle][nxt % cycle] ++;
        }else {
          if (nxt < M) high_ev[nxt].emplace_back(k, m);
        }
      }else if (op[m] == 2) {
        ll m0 = stat[k];
        ll res = (m - m0) % cycle;
        if (res >= X[k]) num_maint--;
        if (cycle < border) {
          low_ev[cycle][m0 % cycle] ++;
          low_ev[cycle][(m0 + X[k]) % cycle] --;
        }
        stat[k] = -1;
      }
    }
    ans[m] = num_maint;
  }
  REP(m, M) cout << ans[m] << "\n";
  return 0;
}

