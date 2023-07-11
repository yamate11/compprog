#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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
    ll N, M; cin >> N >> M;
    // @InpVec(N, A) [xGpCFkzP]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [xGpCFkzP]
    // @InpVec(M, B) [Kh8XJvuT]
    auto B = vector(M, ll());
    for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
    // @End [Kh8XJvuT]
    ll a = accumulate(ALL(A), 0LL);
    ll b = accumulate(ALL(B), 0LL);
    string ans;
    if (a > b) ans = "Tsondu";
    else if (a == b) ans = "Draw";
    else ans = "Tenzing";
    cout << ans << "\n";
                       

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

