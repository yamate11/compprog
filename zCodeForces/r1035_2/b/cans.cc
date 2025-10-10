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
    ll n; cin >> n;
    ll px, py, qx, qy; cin >> px >> py >> qx >> qy;
    ll dx = qx - px, dy = qy - py;
    ll dd = dx * dx + dy * dy;
    // @InpVec(n, A) [Ytv7vYmn]
    auto A = vector(n, ll());
    for (int i = 0; i < n; i++) { ll v; cin >> v; A[i] = v; }
    // @End [Ytv7vYmn]
    sort(ALL(A));
    ll a = A[n - 1];
    ll b = accumulate(ALL(A), 0LL) - a;
    auto check1 = [&]() -> bool {
      if (a - b <= 0) return true;
      return (a - b) * (a - b) <= dd;
    };
    bool cond1 = check1();
    bool cond2 = dd <= (a + b) * (a + b);
    if (cond1 and cond2) cout << "Yes\n";
    else cout << "No\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

