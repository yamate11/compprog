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
  vector<ll> ans;
  if (N == 1) {
    REP(j, 0, K) ans.push_back(1);
  }else if (N % 2 == 0) {
    ans.push_back(N / 2);
    REPrev(i, N, 1) {
      if (i != N / 2) {
        REP(j, 0, K)  ans.push_back(i);
      }else {
        REP(j, 0, K - 1) ans.push_back(i);
      }
    }
  }else {
    ll m = (N + 1) / 2;
    REP(j, 0, K) ans.push_back(m);
    ans.push_back(m - 1);
    REPrev(i, N, 1) {
      if (i == m) {
      }else if (i == m - 1) {
        REP(j, 0, K - 1) ans.push_back(i);
      }else {
        REP(j, 0, K) ans.push_back(i);
      }
    }
  }
  REPOUT(i, 0, ssize(ans), ans[i], " ");

  return 0;
}

