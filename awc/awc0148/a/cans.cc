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

  ll N, D, K; cin >> N >> D >> K;
  vector cnt(N, 0LL);
  REP(i, 0, D) {
    ll m; cin >> m;
    REP(j, 0, m) {
      ll s; cin >> s; s--;
      cnt[s]++;
    }
  }
  vector<ll> ans;
  REP(i, 0, N) if (cnt[i] >= K) ans.push_back(i);
  if (ssize(ans) == 0) {
    cout << "-1\n";
  }else {
    REPOUT(i, 0, ssize(ans), ans[i] + 1, " ");
  }

  return 0;
}

