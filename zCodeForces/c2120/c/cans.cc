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
    ll N, M; cin >> N >> M;
    M -= N;
    if (not (0 <= M and M <= N * (N - 1) / 2)) {
      cout << "-1\n";
      return ;
    }
    vector<ll> rec;
    ll s = 0;
    REPrev(i, N - 1, 0) {
      if (s + i < M) {
        rec.push_back(i);
        s += i;
      }else {
        rec.push_back(M - s);
        if (M - s > 0) rec.push_back(0);
        REP(j, 1, i + 1) if (j != M - s) rec.push_back(j);
        break;
      }
    }
    cout << rec[0] + 1 << "\n";
    REP(i, 0, ssize(rec) - 1) cout << rec[i] + 1 << " " << rec[i + 1] + 1 << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

