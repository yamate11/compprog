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

  ll N, K; cin >> N >> K;
  vector<ll> mark(N);
  REP(i, N) {
    ll p, q, r; cin >> p >> q >> r;
    mark[i] = p + q + r;
  }
  auto cp = mark;
  sort(ALL(cp), greater<ll>());
  ll b = cp[K - 1];
  REP(i, N) {
    if (mark[i] + 300 >= b) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}

