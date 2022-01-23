#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

  ll N, M, D; cin >> N >> M >> D;
  vector<ll> R(M + 1);
  REP(i, M + 1) cin >> R[i];
  vector<ll> S(M);
  REP(i, M) cin >> S[i];

  vector<ll> TP(M * 2), TM(M * 2);
  REP(i, M) {
    TP[M - i - 1] = -R[i + 1];
    TP[M + i] = R[i + 1] + 1;
    if (i == 0) {
      TM[M - 1] = S[0];
    }else {
      TM[M - 1 - i] = S[i];
      TM[M - 1 + i] = S[i];
    }
  }
  TM[2 * M - 1] = 0;

  ll x0 = - (D * N + 1) / 2;
  ll xfin = x0 + D + 1;
  using sta = tuple<ll, ll, ll>;
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  ll mark = 0;
  REP(i, N) {
    ll x = x0 + i * D;
    ll j = upper_bound(ALL(TP), x) - TP.begin();
    if (j == M * 2) continue;
    else if (TP[j] == x) {
      if (j == M*2 - 1) continue;
      mark += TM[j];
      pque.emplace(TP[j + 1] - x, TM[j + 1] - TM[j], j + 1);
    }else {
      ll this_mark = j > 0 ? TM[j - 1] : 0;
      mark += this_mark;
      pque.emplace(TP[j] - x, TM[j] - this_mark, j);
    }
  }
  ll ans = mark;
  ll pos = x0;
  while (pos <= xfin and not pque.empty()) {
    auto [p, m, j] = pque.top(); pque.pop();
    pos = x0 + p;
    mark += m;
    ans = max(ans, mark);
    if (j < M*2 - 1) {
      pque.emplace(p + TP[j + 1] - TP[j], TM[j + 1] - TM[j], j + 1);
    }
  }
  cout << ans << endl;

  return 0;
}

