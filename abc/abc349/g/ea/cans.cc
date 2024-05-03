#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
#include <atcoder/dsu>
using namespace atcoder;
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
  // @InpVec(N, A) [nSmkeEsM]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [nSmkeEsM]

  ll K = countr_zero(bit_floor((u64)N)) + 1;
  vector uf(K, dsu(2 * N));
  
  auto mymerge = [&](ll a, ll b, u64 m) -> void {
    auto sub = [&](auto rF, u64 t, ll p, ll q) -> void {
      if (uf[t].leader(p) == uf[t].leader(q)) return;
      uf[t].merge(p, q);
      if (t > 0) {
        rF(rF, t - 1, p, q);
        rF(rF, t - 1, p + (1LL << (t - 1)), q + (1LL << (t - 1)));
      }
    };

    if (m == 0) return;
    u64 s = bit_floor(m);
    u64 t = countr_zero(s);
    if (s == m) {
      sub(sub, t, a, b);
    }else {
      sub(sub, t, a, b);
      sub(sub, t, a + m - s, b + m - s);
    }
  };
  
  REP(i, 0, N) uf[0].merge(i, 2*N - 1 - i);
  REP(i, 0, N) mymerge(i + 1, 2*N - i - 1 + 1, A[i]);
  vector diff(N, vector<ll>());
  REP(i, 0, N) {
    ll a = i - A[i] - 1;
    ll b = i + A[i] + 1;
    if (0 <= a and b < N) {
      ll la = uf[0].leader(a);
      ll lb = uf[0].leader(b);
      if (la == lb) {
        cout << "No\n";
        return 0;
      }
      diff[la].push_back(lb);
      diff[lb].push_back(la);
    }
  }

  auto gp = uf[0].groups();
  vector<ll> igp(2*N);
  REP(i, 0, ssize(gp)) for (ll x : gp[i]) igp[x] = i;

  vector<ll> ans(2*N, -1LL);
  vector<bool> used(N, false);
  REP(i, 0, N) {
    if (ans[i] >= 0) continue;
    ll ld = uf[0].leader(i);
    for (ll j : diff[ld]) if (ans[j] >= 0) used[ans[j]] = true;
    ll c = 0;
    for (; used[c]; c++);
    for (ll j : diff[ld]) if (ans[j] >= 0) used[ans[j]] = false;
    for (ll z : gp[igp[i]]) ans[z] = c;
  }
  cout << "Yes\n";
  REPOUT(i, 0, N, ans[i] + 1, " ");

  return 0;
}

