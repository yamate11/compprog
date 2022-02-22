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

  auto func = [&](ll b) -> ll {
    ll ret = 0;
    ll t = 0;
    for (ll i = b; i + 1 < N; i += 3) {
      t += S[i + 1] - S[i];
      ret = min(ret, t);
    }
    return -ret;
  };


  ll alpha = func(0);
  ll beta = func(1);
  ll gamma = func(2);
  vector<ll> x(N + 2);
  x[0] = alpha;
  x[1] = beta;
  x[2] = S[0] - (alpha + beta);
  if (x[2] < gamma) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  REP2(i, 3, N + 2) x[i] = S[i - 2] - S[i - 3] + x[i - 3];
  REP(i, N + 2) cout << x[i] << " ";
  cout << endl;


  return 0;
}

