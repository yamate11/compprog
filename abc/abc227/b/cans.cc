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

  ll N; cin >> N;
  vector<ll> S(N);
  REP(i, N) cin >> S[i];
  vector<bool> poss(1001);
  REP2(a, 1, 1000) REP2(b, 1, 1000) {
    ll s = 4*a*b + 3*a + 3*b;
    if (s <= 1000) poss[s] = true;
    else break;
  }
  ll cnt = 0;
  REP(i, N) if (not poss[S[i]]) cnt++;
  cout << cnt << endl;

  return 0;
}

