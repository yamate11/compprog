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
  
  ll i = 0, j = 0;
  ll dup = -1;
  set<ll> ss;
  ll ans = 0;
  while (true) {
    if (dup < 0) {
      ans = max(ans, j - i);
      if (j == N) break;
      if (ss.contains(A[j])) dup = A[j];
      else                   ss.insert(A[j]);
      j++;
    }else {
      if (A[i] == dup)       dup = -1;
      else                   ss.erase(A[i]);
      i++;
    }
  }
  cout << ans << endl;
  return 0;
}

