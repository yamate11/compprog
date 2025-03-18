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
  // @InpVec(N, W) [LCYSZgnE]
  auto W = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; W[i] = v; }
  // @End [LCYSZgnE]

  // @InpMVec(N, (L, R)) [BzCvjB1j]
  auto L = vector(N, ll());
  auto R = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; L[i] = v1;
    ll v2; cin >> v2; R[i] = v2;
  }
  // @End [BzCvjB1j]

  vector<pll> LW1(N);
  vector<pll> RW1(N);
  
  REP(i, 0, N) {
    LW1[i] = pll(L[i], W[i]);
    RW1[i] = pll(R[i], W[i]);
  }
  sort(ALL(LW1));
  sort(ALL(RW1));
  ll big = 1e18;

  vector<pll> LW;
  vector<pll> RW;
  {
    ll val = big;
    LW.emplace_back(big, big);
    REPrev(i, N - 1, 0) {
      auto [l, w] = LW1[i];
      if (w < val) {
        LW.emplace_back(l, w);
        val = w;
      }
    }
    reverse(ALL(LW));
    val = big;
    RW.emplace_back(-big, big);
    REP(i, 0, N) {
      auto [r, w] = RW1[i];
      if (w < val) {
        RW.emplace_back(r, w);
        val = w;
      }
    }
  }

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll s, t; cin >> s >> t; s--; t--;
    ll ans;
    if (R[s] < L[t] or R[t] < L[s]) {
      ans = W[s] + W[t];
    }else {
      ll lo = min(L[s], L[t]);
      ll hi = max(R[s], R[t]);
      auto it1 = lower_bound(ALL(RW), pll(lo, -big));
      it1--;
      auto [r1, w1] = *it1;
      ll w0 = w1;
      auto it2 = lower_bound(ALL(LW), pll(hi + 1, -big));
      if (it2 != LW.end()) {
        auto [l2, w2] = *it2;
        w0 = min(w0, w2);
      }
      ans = W[s] + W[t] + w0;
      if ((L[t] <= L[s] and R[s] <= R[t]) or (L[s] <= L[t] and R[t] <= R[s])) {
        // do nothing
      }else {
        ll lo2 = max(L[s], L[t]), hi2 = min(R[s], R[t]);
        auto jt1 = lower_bound(ALL(RW), pll(lo2, -big));
        jt1--;
        auto [rr1, ww1] = *jt1;
        ll ww0 = ww1;
        auto jt2 = lower_bound(ALL(LW), pll(hi2 + 1, -big));
        if (jt2 != LW.end()) {
          auto [ll2, ww2] = *jt2;
          ww0 += ww2;
        }else {
          ww0 = big;
        }
        if (W[s] + W[t] + ww0 < ans) ans = W[s] + W[t] + ww0;
      }
    }
    if (ans >= big) ans = -1;
    cout << ans << "\n";
  }
  return 0;
}

