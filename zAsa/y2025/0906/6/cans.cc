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
  vector<pll> AB;
  REP(i, 0, N) {
    ll a, b; cin >> a >> b;
    AB.emplace_back(a, b);
  }
  sort(ALL(AB),
       [&](const pll& p, const pll& q) -> bool {
         const auto& [pa, pb] = p;
         const auto& [qa, qb] = q;
         ll p_s = pa < pb ? -1 : pa == pb ? 0 : 1;
         ll q_s = qa < qb ? -1 : qa == qb ? 0 : 1;
         if (p_s != q_s) return p_s < q_s;
         if (p_s == -1) return pa < qa;
         if (p_s == 0) return false;
         if (p_s == 1) return pb > qb;
         assert(false);
       });
  ll ans = 0;
  ll cur = 0;
  for (auto [a, b] : AB) {
    ans = max(ans, cur + a);
    cur += a - b;
  }
  cout << ans << endl;
  return 0;
}

