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
  ll lim = 2e5;
  vector<ll> cnt(lim + 1);
  REP(i, N) {
    ll a; cin >> a;
    cnt[a]++;
  }
  ll exc = 0;
  REP2(i, 1, lim + 1) {
    ll c = cnt[i];
    exc += c * (c - 1) * (c - 2) / 6;
    exc += c * (c - 1) / 2 * (N - c);
  }
  cout << N * (N - 1) * (N - 2) / 6 - exc << endl;

  return 0;
}

