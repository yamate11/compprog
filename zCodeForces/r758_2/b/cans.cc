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

  auto solve = [&]() -> vector<ll> {
    ll N, A, B; cin >> N >> A >> B;
    vector<ll> v;
    if (abs(A - B) > 1) return v;
    if (A + B > N - 2) return v;
    v.resize(N);
    v[0] = 0;
    ll x = 1;
    ll shift = 0;
    if (A > B) {
      REP(i, A) {
        v[2*i + 1] = x;
        v[2*i + 2] = -x;
        x++;
      }
      REP2(i, 2*A + 1, N) {
        v[i] = -x;
        x++;
      }
      shift = x - 1 + 1;
    }
    else if (A == B) {
      REP(i, A) {
        v[2*i + 1] = x;
        v[2*i + 2] = -x;
        x++;
      }
      shift = (x - 1) + 1;
      REP2(i, 2*A + 1, N) {
        v[i] = x;
        x++;
      }
    }else if (A < B) {
      REP(i, B) {
        v[2*i + 1] = -x;
        v[2*i + 2] = x;
        x++;
      }
      shift = (x-1) + 1;
      REP2(i, 2*B + 1, N) {
        v[i] = x;
        x++;
      }
    }
    REP(i, N) v[i] += shift;
    return v;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    auto v = solve();
    if (SIZE(v) == 0) cout << "-1\n";
    else {
      for (ll a : v) cout << a << " ";
      cout << "\n";
    }
  }

  return 0;
}

