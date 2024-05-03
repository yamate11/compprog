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

    // @InpVec(N, C, dec=1) [PoWunwAi]
    auto C = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; C[i] = v; }
    // @End [PoWunwAi]

    vector<ll> cnt(N);
    REP(i, 0, N) cnt[C[i]]++;

    ll ns = 0; REP(i, 0, N) if (cnt[i] > 0) ns++;

    vector<ll> ans;
    if (ns <= 2 or 2 * ns - 2 > N) {
      REP(i, 0, N) REP(j, 0, cnt[i]) ans.push_back(i);
    }else {
      vector<ll> single;
      vector<ll> dup;
      vector<ll> parent(N, -1LL);
      vector<vector<ll>> children(N, vector<ll>());

      REP(i, 0, N) {
        if (cnt[i] == 1) single.push_back(i);
        else if (cnt[i] >= 2) dup.push_back(i);
      }

      ll x = dup.back(); dup.pop_back();
      ll nx = cnt[x];
      while (not single.empty()) {
        ll b = single.back(); single.pop_back();
        parent[b] = x;
        children[x].push_back(b);
        nx--;
        if (nx == 1) {
          if (dup.empty()) {
            assert(ssize(single) <= 1);
            if (ssize(single) == 1) {
              b = single.back();
              parent[b] = x;
              children[x].push_back(b);
            }
            break;
          }
          single.push_back(x);
          x = dup.back(); dup.pop_back();
          nx = cnt[x];
        }
      }
      while (not dup.empty()) {
        ll b = x;
        x = dup.back(); dup.pop_back();
        parent[b] = x;
        children[x].push_back(b);
      }
      auto dfs = [&](auto rF, ll a) -> void {
        ll t = 0;
        for (ll c : children[a]) {
          ans.push_back(a);
          t++;
          rF(rF, c);
        }
        for (; t < cnt[a]; t++) ans.push_back(a);
      };
      dfs(dfs, x);
    }
    REPOUT(i, 0, ssize(ans), ans[i] + 1, " ");
  };


  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

