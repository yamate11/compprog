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
  vector A(N, 0LL); REP(i, 0, N) cin >> A[i];
  
  // P(i, j) <-> A[i] < A[i + 1] < ... < A[j]
  ll i = 0, j = 0;
  ll ans = 0;
  ll cond = true;
  while (true) {
    if (cond) {
      ans += j - i + 1;
      j++;
      if (j == N) break;
      cond = A[j - 1] < A[j];
    }else {
      i++;
      cond = i == j;
    }
  }
  cout << ans << endl;
  return 0;
}

