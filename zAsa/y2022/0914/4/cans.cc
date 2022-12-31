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
  // @InpVec(N, A) [oQCw0mQZ]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [oQCw0mQZ]
  ll lim = 1e5;
  vector<ll> cnt(lim + 1); REP(i, 0, N) cnt[A[i]]++;
  ll even = 0, odd = 0;
  REP(i, 1, lim + 1) if (cnt[i] > 0) {
    if (cnt[i] % 2 == 0) even++;
    else odd++;
  }
  ll ans;
  if (even % 2 == 0) ans = odd + even;
  else ans = odd + even - 1;
  cout << ans << endl;

  return 0;
}

