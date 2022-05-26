#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N; cin >> N;
    ll va = 0;
    REP(i, N) {
      ll a; cin >> a;
      va = max(va, a);
    }
    ll M; cin >> M;
    ll vb = 0;
    REP(i, M) {
      ll b; cin >> b;
      vb = max(vb, b);
    }
    if (va > vb) cout << "Alice\nAlice\n";
    else if (va < vb) cout << "Bob\nBob\n";
    else cout << "Alice\nBob\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

