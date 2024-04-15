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

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [R1a9RhiO]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [R1a9RhiO]

  ll R = 40;
  vector<ll> contr(R);
  ll x0 = 0;
  REP(k, 0, R) {
    ll a = 0;
    REP(i, 0, N) a += A[i] >> k & 1;
    if (a <= N - a) x0 |= 1LL << k;
  }
  auto f = [&](ll x) -> ll {
    ll ret = 0;
    REP(i, 0, N) ret += A[i] ^ x;
    return ret;
  };
  ll ans = f(K);
  ans = max(ans, f(0));
  REP(k, 0, R) {
    if (K >> k & 1) {
      ll maskL = (1LL << k) - 1;
      ll maskH = ((1LL << R) - 1) ^ maskL;
      ll x = ((K & maskH) - (1LL << k)) | (x0 & maskL);
      ans = max(ans, f(x));
    }
  }
  cout << ans << endl;
  

  return 0;
}

