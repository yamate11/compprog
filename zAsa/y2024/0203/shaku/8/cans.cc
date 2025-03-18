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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N); REP(i, 0, N) cin >> A[i];
  vector<ll> S(2*N + 1, 0LL);
  REP(i, 0, N) S[i + 1] = S[i] + A[i];
  REP(i, 0, N) S[N + i + 1] = S[N + i] + A[i];

  ll i = 0, j = 1, k = 2;
  ll ans = 0;
  while (true) {

    auto f = [&](ll p, ll q) -> ll { return S[q] - S[p]; };
    auto g = [&]() -> ll {
      if (f(j, k) < f(k, i + N)) {
        while (f(j, k) < f(k, i + N)) k++;
        k--;
      }else {
        while (f(j, k) > f(k, i + N)) k--;
      }
      if (min(f(j, k), f(k, i + N)) < min(f(j, k + 1), f(k + 1, i + N))) k++;
      return min(f(j, k), f(k, i + N));
    };

    ll a = f(i, j);
    ll b = g();
    ans = max(ans, min(a, b));
    if (a < b) {
      j++;
    }else {
      i++;
      if (i == N) break;
    }
  }
  
  cout << ans << endl;

  return 0;
}

