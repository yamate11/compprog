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

  ll N, M; cin >> N >> M;
  // @InpVec(N, S, type=string) [aCB9Tace]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [aCB9Tace]
  vector mark(N, 0LL);
  REP(j, 0, M) {
    ll zero = 0, one = 0;
    REP(i, 0, N) {
      if (S[i][j] == '0') zero++;
      else one++;
    }
    if (zero == 0 or one == 0) {
      REP(i, 0, N) mark[i]++;
    }else if (zero < one) {
      REP(i, 0, N) if (S[i][j] == '0') mark[i]++;
    }else if (zero > one) {
      REP(i, 0, N) if (S[i][j] == '1') mark[i]++;
    }
  }
  ll vmax = *max_element(ALL(mark));
  vector<ll> ans;
  REP(i, 0, N) if (mark[i] == vmax) ans.push_back(i);
  REPOUT(i, 0, ssize(ans), ans[i] + 1, " ");

  return 0;
}

