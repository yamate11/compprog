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
    ll N, L, R; cin >> N >> L >> R; L--;
    // @InpVec(N, A) [WRjr6cbP]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [WRjr6cbP]

    sort(A.begin() + L, A.begin() + R, greater<ll>());
    sort(A.begin() + 0, A.begin() + L);
    sort(A.begin() + R, A.begin() + N);


    auto f = [&](ll p, ll q) -> ll {
      ll s = 0;
      REP(i, 0, R - L) {
        if (p + i < q and A[p + i] < A[L + i]) s += A[p + i];
        else s += A[L + i];
      }
      return s;
    };

    ll x = f(R, N);
    ll y = f(0, L);
    cout << min(x, y) << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

