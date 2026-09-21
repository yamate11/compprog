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

  ll N, M; cin >> N >> M;
  // @InpVec(N, S) [iDOqJ9Nh]
  auto S = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; S[i] = v; }
  // @End [iDOqJ9Nh]
  ranges::sort(S);
  priority_queue<ll, vector<ll>, greater<ll>> pque;
  set<pll> A;
  set<pll> B;
  REP(i, 0, N - 1) {
    A.emplace(i, S[i + 1] - S[i]);
    B.emplace(S[i + 1] - S[i], i);
  }
  ll big = 1LL << 60;
  A.emplace(-big, 0); A.emplace(big, 0);
  ll ans = 0;
  REP(j, 0, M) {
    auto [v0, i0] = *B.begin();
    ans += v0;
    auto it0 = A.find(pll(i0, v0));
    auto [ip, vp] = *std::prev(it0);
    auto [in, vn] = *std::next(it0);
    if (ip >= 0) {
      A.erase(std::prev(it0));
      B.erase(pll(vp, ip));
    }
    if (in < N) {
      A.erase(std::next(it0));
      B.erase(pll(vn, in));
    }
    A.erase(it0);
    B.erase(B.begin());
    if (ip >= 0 and in < N) {
      ll new_v = vp + vn - v0;
      A.emplace(i0, new_v);
      B.emplace(new_v, i0);
    }
  }
  cout << ans << "\n";
  return 0;
}

