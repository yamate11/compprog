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
    // @InpVec(2*N, B) [qdcgUP8J]
    auto B = vector(2*N, ll());
    for (int i = 0; i < 2*N; i++) { ll v; cin >> v; B[i] = v; }
    // @End [qdcgUP8J]
    sort(ALL(B));
    ll x = accumulate(ALL(B), 0LL);
    ll y = accumulate(B.begin(), B.begin() + N - 1, 0LL);
    ll z = x - 2*y;
    vector ans(2*N + 1, 0LL);
    ans[0] = B[2*N - 1];
    ans[1] = z;
    ans[2] = B[N - 1];
    REP(i, 0, N - 1) {
      ans[3 + 2 * i] = B[i];
      ans[3 + 2 * i + 1] = B[N + i];
    }
    REPOUT(i, 0, 2*N + 1, ans[i], " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

