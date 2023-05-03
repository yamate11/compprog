#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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
  // @InpVec(N, A, dec=1) [3AmdJOcA]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [3AmdJOcA]
  ll Q; cin >> Q;
  // @InpMVec(Q, (L, R)) [DAz81lNO]
  auto L = vector(Q, ll());
  auto R = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; L[i] = v1;
    ll v2; cin >> v2; R[i] = v2;
  }
  // @End [DAz81lNO]
  ll W = 1000;
  using sta = tuple<ll, ll, ll>;
  vector<sta> vq(Q);
  vector<ll> ans(Q);
  REP(i, 0, Q) vq[i] = sta(L[i] - 1, R[i], i);
  sort(ALL(vq),
       [&](const sta& p1, const sta& p2) -> bool {
         const auto& [a1, b1, i1] = p1;
         const auto& [a2, b2, i2] = p2;
         ll z1 = a1 / W;
         ll z2 = a2 / W;
         if (z1 != z2) return z1 < z2;
         return b1 < b2;
       });
  vector<ll> cnt(N);
  ll cl = 0, cr = 0;
  ll cans = 0;
  auto f = [&](ll i, ll d) -> void {
    if (d == +1) if (++cnt[A[i]] % 2 == 0) cans++;
    if (d == -1) if (cnt[A[i]]-- % 2 == 0) cans--;
  };
  for (const auto& [l, r, i] : vq) {
    while (cl < l) f(cl++, -1);
    while (l < cl) f(--cl, +1);
    while (cr < r) f(cr++, +1);
    while (r < cr) f(--cr, -1);
    ans[i] = cans;
  }
  REPOUT(i, 0, Q, ans[i], "\n");

  return 0;
}

