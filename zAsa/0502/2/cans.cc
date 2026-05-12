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
  // @InpVec(N, A) [w8Tj8Mpc]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [w8Tj8Mpc]
  map<ll, ll> mp;
  REP(i, 0, N) mp[A[i]]++;
  ll H = N / 2;
  bool first = true;
  auto check = [&]() -> bool {
    for (auto [x, n] : mp) {
      if (first) {
        first = false;
        if (n > H + 1) return false;
      }else {
        if (n > H) return false;
      }
    }
    return true;
  };
  cout << (check() ? "Yes\n" : "No\n");

  return 0;
}

