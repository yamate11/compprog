#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A) [00zOs9xj]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [00zOs9xj]

  map<ll, ll> cnt;
  REP(i, 0, N) cnt[A[i]]++;

  ll tot = 0;
  for (auto [_i, n] : cnt) tot += n * (n - 1) / 2;
  REP(i, 0, N) {
    ll n = cnt[A[i]];
    ll a = tot - (n * (n - 1) / 2) + ((n - 1) * (n - 2) / 2);
    cout << a << "\n";
  }

  return 0;
}

