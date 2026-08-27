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
  // @InpVec(N, A) [wYOarfnQ]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [wYOarfnQ]
  set<ll> ss;
  REP(i, 0, N) ss.insert(A[i]);
  
  ll ans = 0;
  ll cur = 0;
  REP(i, 0, N) {
    auto it = ss.lower_bound(cur);
    if (it == ss.end()) {
      it--;
    }else if (it == ss.begin()) {
      ;
    }else {
      ll x = *it;
      ll y = *std::prev(it);
      if (abs(cur - x) < abs(cur - y)) ;
      else it--;
    }
    ans += abs(cur - *it);
    cur = *it;
    ss.erase(it);
  }
  cout << ans << "\n";

  return 0;
}

