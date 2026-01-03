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

  ll N; cin >> N;
  vector<vector<ll>> prer(N);
  REP(i, 0, N) {
    ll c; cin >> c;
    REP(j, 0, c) {
      ll p; cin >> p; p--;
      prer[i].push_back(p);
    }
  }
  vector<bool> isin(N, false);
  vector<ll> ans;
  auto f = [&](auto rF, ll n) -> void {
    if (isin[n]) return;
    for (ll j : prer[n]) rF(rF, j);
    ans.push_back(n);
    isin[n] = true;
  };
  f(f, 0);
  REPOUT(i, 0, ssize(ans) - 1, ans[i] + 1, " ");
  

  return 0;
}

