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

  ll L, N1, N2; cin >> L >> N1 >> N2;
  // @InpMVec(N1, (V1, L1)) [FMQaRIbO]
  auto V1 = vector(N1, ll());
  auto L1 = vector(N1, ll());
  for (int i = 0; i < N1; i++) {
    ll v1; cin >> v1; V1[i] = v1;
    ll v2; cin >> v2; L1[i] = v2;
  }
  // @End [FMQaRIbO]
  // @InpMVec(N2, (V2, L2)) [nGiHunHd]
  auto V2 = vector(N2, ll());
  auto L2 = vector(N2, ll());
  for (int i = 0; i < N2; i++) {
    ll v1; cin >> v1; V2[i] = v1;
    ll v2; cin >> v2; L2[i] = v2;
  }
  // @End [nGiHunHd]

  using ev_t = tuple<ll, ll, ll>;
  vector<ev_t> ev;
  ev.emplace_back(0, 1, 0);
  ll t = 0;
  REP(i, 0, N1) {
    ev.emplace_back(t, 1, V1[i]);
    t += L1[i];
  }
  assert(t == L);
  t = 0;
  REP(i, 0, N2) {
    ev.emplace_back(t, 2, V2[i]);
    t += L2[i];
  }
  assert(t == L);
  ev.emplace_back(L, 1, 0);
  ranges::sort(ev);
  ll cur1 = 0, cur2 = 0;
  ll ans = 0;
  REP(i, 1, ssize(ev)) {
    auto [to, jo, vo] = ev[i - 1];
    auto [tn, jn, vn] = ev[i];
    if (cur1 == cur2) ans += tn - to;
    if (jn == 1) cur1 = vn;
    else cur2 = vn;
  }
  cout << ans << endl;
  return 0;
}

