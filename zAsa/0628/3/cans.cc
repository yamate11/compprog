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
  // @InpVec(N, A) [MeFYnbYb]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [MeFYnbYb]

  auto f = [&](ll i, bool b) -> ll {
    auto g = [&](ll x, ll y) -> bool {
      if (x == y) return true;
      return b == (x < y);
    }; 
    while (i + 1 < N and g(A[i], A[i + 1])) i++;
    return i + 1;
  };

  ll i = 0;
  ll cnt = 0;
  while (true) {
    cnt++;
    i = max(f(i, true), f(i, false));
    if (i >= N) {
      cout << cnt << endl;
      return 0;
    }
  }

  return 0;
}

