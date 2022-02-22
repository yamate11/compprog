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
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  const ll nd = 30;
  vector<ll> num1(nd), eff1(nd);
  REP(k, nd) REP(i, N) if (A[i] >> k & 1) num1[k]++;
  REP(k, nd) eff1[k] = ((N - num1[k]) - num1[k]) * (1LL << k);
  ll sum = accumulate(ALL(A), 0LL);
  ll vmax = 0;
  REP(i, N) {
    ll v = 0;
    REP(k, nd) if (A[i] >> k & 1) v += eff1[k];
    vmax = max(vmax, v);
  }
  cout << sum + vmax << endl;

  return 0;
}

