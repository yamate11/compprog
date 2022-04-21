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
  if (N == 1) { cout << "Yes\n0 1\n"; return 0; }
  if (K == N or K % 2 == 0) { cout << "No\n"; return 0; }
  vector<ll> ans(1LL << N);
  ll n = K + 1;
  ll mask = (1LL << n) - 1;
  REP(i, 1LL << n) {
    ll x = i ^ (i >> 1);
    ans[i] = i % 2 == 0 ? x : (x ^ mask);
  }
  for (; n < N; n++) {
    ll j0 = 1LL << n;
    ans[j0] = ans[j0 - 1] ^ ((1LL << (K - 1)) - 1) ^ j0;
    REP(i, j0 - 1) ans[j0 + i + 1] = ans[j0 + i] ^ ans[i] ^ ans[i + 1];
  }
  cout << "Yes\n";
  for (ll a : ans) cout << a << " ";
  cout << endl;

  return 0;
}

