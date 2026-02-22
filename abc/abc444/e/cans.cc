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

  ll N, D; cin >> N >> D;
  // @InpVec(N, A) [QrUNi7Ln]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [QrUNi7Ln]

  set<ll> ss;
  auto check = [&](ll x) -> bool {
    auto it = ss.lower_bound(x);
    if (it != ss.end()) {
      if (*it - x < D) return false;
    }
    if (it != ss.begin()) {
      if (x - *prev(it) < D) return false;
    }
    return true;
  };
  ll j = 0;
  ll ans = 0;
  REP(i, 0, N) {
    while (j < N and check(A[j])) {
      ss.insert(A[j]);
      j++;
    }
    ans += j - i;
    ss.erase(A[i]);
  }
  cout << ans << endl;
  return 0;
}

