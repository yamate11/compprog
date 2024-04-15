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
    
    ll s = 0;
    REP(i, 1, N + 1) {
      s += (i * i - (i - 1) * (i - 1)) * i;
    }
    cout << s << " " << 2 * N << "\n";
    REPrev(i, N, 1) {
      cout << 1 << " " << i;
      REP(j, 1, N + 1) cout << " " << j;
      cout << "\n";
      cout << 2 << " " << i;
      REP(j, 1, N + 1) cout << " " << j;
      cout << "\n";
    }
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

