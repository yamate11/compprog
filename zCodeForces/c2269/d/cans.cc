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

#if 0  
  vector<ll> vec{0, 3, 6, 9, 12, 15};
  REP(i, 0, 6) {
    REP(j, 0, 6) {
      cout << ((vec[i]) ^ (vec[j])) << "  ";
    }
    cout << "\n";
  }

  return 0;
#endif

  vector<ll> tmp{0, 3, 5, 6, 9, 10, 12, 15};
  vector<bool> good(16, false);
  for (ll i : tmp) good[i] = true;

  auto solve = [&]() -> void {
    ll N, Q; cin >> N >> Q;
    // @InpVec(N, A) [YfFYWTiF]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [YfFYWTiF]
    vector<ll> ans;
    ll cnt = 0;
    REP(i, 0, N) if (good[A[i]]) cnt++;
    ans.push_back(cnt);
    REP(_q, 0, Q) {
      ll p, x; cin >> p >> x; p--;
      if (good[A[p]]) cnt--;
      A[p] = x;
      if (good[A[p]]) cnt++;
      ans.push_back(cnt);
    }
    REPOUT(i, 0, ssize(ans), ans[i], " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

