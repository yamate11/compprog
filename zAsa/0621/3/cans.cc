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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  enum kind { OPEN, CLOSE };
  using ev_t = pair<ll, kind>;
  vector<ev_t> ev;
  ll N; cin >> N;
  // @InpMVec(N, (L, R)) [hJdDp9KL]
  auto L = vector(N, ll());
  auto R = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; L[i] = v1;
    ll v2; cin >> v2; R[i] = v2;
  }
  // @End [hJdDp9KL]
  REP(i, 0, N) {
    ev.emplace_back(L[i], OPEN);
    ev.emplace_back(R[i], CLOSE);
  }
  sort(ALL(ev));
  ll ans = 0;
  ll cur = 0;
  for (auto [t, k] : ev) {
    if (k == OPEN) {
      ans += cur;
      cur++;
    }else {
      cur--;
    }
  }
  cout << ans << endl;

  return 0;
}

