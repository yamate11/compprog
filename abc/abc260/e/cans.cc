#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

  ll N, M; cin >> N >> M;
  vector<ll> A(N), B(N);
  using sta = tuple<ll, ll, ll>;
  vector<sta> event;
  enum {EVA, EVB};
  REP(i, N) {
    ll a, b; cin >> a >> b; a--; b--;
    A[i] = a;
    B[i] = b;
    event.emplace_back(a, i, EVA);
    event.emplace_back(b, i, EVB);
  }
  sort(ALL(event));
  ll farest = *max_element(ALL(A));
  ll idx = 0;
  vector<ll> imos(M + 1);
  REP(i, M) {
    imos[1]++;
    imos[farest - i + 1]--;
    // bool here = false;
    while (idx < SIZE(event)) {
      auto [t, j, tp] = event[idx];
      if (i < t) break;
      // here = true;
      if (tp == EVA) {
        farest = max(farest, B[j]);
      }else if (tp == EVB) {
        farest = M;
      }
      idx++;
    }
    // if (here) continue;
  }
  ll x = 0;
  REP2(i, 1, M + 1) {
    x += imos[i];
    ll a = M - i + 1 - x;
    cout << a << " ";
  }
  cout << endl;

  return 0;
}

