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

int main() {
  auto solve = [&]() -> void {
    ll N; cin >> N;
    cout << N + 1 << " " << N * N << "\n";
  };


  ll T; cin >> T;
  REP(t, 0, T) solve();
}

/*
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll M; cin >> M;
  REP(i, 1, M) {
    ll c = i;
    REP(j, 1, M*M) {
      if (c == 1) {
        cerr << i << " " << j << "\n";
        break;
      }
      c = (c * i) % M;
    }
  }


  return 0;
}

*/
