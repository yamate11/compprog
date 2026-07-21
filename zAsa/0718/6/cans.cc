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
    ll N; cin >> N;
    string S; cin >> S;
    vector fwd(N, vector<ll>());
    vector bwd(N, vector<ll>());
    REP(i, 0, N - 1) {
      if (S[i] == 'R') {
        fwd[i].push_back(i + 1);
        bwd[i + 1].push_back(i);
      }else {
        fwd[i + 1].push_back(i);
        bwd[i].push_back(i + 1);
      }
    }
    auto func = [&](auto rF, ll x, const auto& wd, auto& tbl) -> ll {
      ll& r = tbl[x];
      if (r < 0) {
        r = 0;
        for (ll peer : wd[x]) r += 1 + rF(rF, peer, wd, tbl);
      }
      return r;
    };
    vector tblF(N, -1LL);
    auto funcF = [&](ll x) -> ll { return func(func, x, fwd, tblF); };
    vector tblB(N, -1LL);
    auto funcB = [&](ll x) -> ll { return func(func, x, bwd, tblB); };

    vector<ll> diff(N + 1, 0LL);
    REP(i, 0, N) {
      ll nf = funcF(i);
      ll nb = funcB(i);
      diff[nb]++;
      diff[N - nf]--;
    }
    vector<ll> ans = diff;
    REP(i, 1, N + 1) ans[i] += ans[i - 1];
    REPOUT(i, 0, N, ans[i], " ");

  };


  ll T; cin >> T;
  REP(t, 0, T) solve();
    

  return 0;
}

