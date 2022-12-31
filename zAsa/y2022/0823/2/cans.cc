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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> bool {
    ll N; cin >> N;
    auto t = vector(N+1, ll());
    auto x = vector(N+1, ll());
    auto y = vector(N+1, ll());
    for (int i = 1; i <= N; i++) {
      ll v1; cin >> v1; t[i] = v1;
      ll v2; cin >> v2; x[i] = v2;
      ll v3; cin >> v3; y[i] = v3;
    }
    REP(i, 1, N+1) {
      if ((x[i] + y[i]) % 2 != t[i] % 2) return false;
      if (abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]) > t[i] - t[i - 1]) return false;
    }
    return true;
  };

  cout << (solve() ? "Yes\n" : "No\n");
    
  


  return 0;
}

