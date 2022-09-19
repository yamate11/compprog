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

  ll N; cin >> N;
  vector<bool> P(N);
  vector<ll> T(N);
  vector A(N, vector<ll>());
  REP(i, 0, N) {
    ll t, k; cin >> t >> k;
    T[i] = t;
    A[i].resize(k);
    REP(j, 0, k) {
      ll a; cin >> a; a--;
      A[i][j] = a;
    }
  }
  auto f = [&](auto rF, ll i) -> ll {
    if (P[i]) return 0;
    ll ret = T[i];
    for (ll a : A[i]) ret += rF(rF, a);
    P[i] = true;
    return ret;
  };
  cout << f(f, N - 1) << endl;

  return 0;
}

