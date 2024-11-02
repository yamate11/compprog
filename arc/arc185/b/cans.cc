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

  auto solve = [&]() -> bool {
    ll N; cin >> N;
    // @InpVec(N, A) [6uI0TY7G]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [6uI0TY7G]
    ll s = accumulate(ALL(A), 0LL);
    ll x = s / N;
    ll y = s % N;
    vector<ll> B(N, x);
    REP(i, N - y, N) B[i]++;
    ll t = 0;
    REP(i, 0, N) {
      t += B[i] - A[i];
      if (t < 0) return false;
    }
    return true;

  };

  ll T; cin >> T;
  REP(t, 0, T) cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

