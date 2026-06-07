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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpVec(N, A) [r4DMUxHH]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [r4DMUxHH]
    
    if (accumulate(ALL(A), 0LL) <= 2) {
      cout << 0 << "\n";
      return;
    }

    ll solo = 0;
    ll place = 0;
    ll doubles = 0;
    ll cnt = 0;
    REP(i, 0, N) {
      if (A[i] == 1) solo++;
      else {
        doubles++;
        cnt += A[i];
        if (A[i] >= 4) place += (A[i] - 2) / 2;
      }
    }
    if (doubles == 1) place++;
    cnt += min(solo, place);
    cout << cnt << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

