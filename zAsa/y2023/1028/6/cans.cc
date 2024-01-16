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

  ll M, K; cin >> M >> K;
  if (M == 0) {
    if (K == 0) {
      cout << "0 0\n";
    }else {
      cout << "-1\n";
    }
  }else if (M == 1) {
    if (K == 0) {
      cout << "0 0 1 1\n";
    }else {
      cout << "-1\n";
    }
  }else {
    if (K < (1LL << M)) {
      vector ans(1LL << (M + 1), 0LL);
      ll c = 1;
      REP(i, 0, (1LL << M)) {
        if (i == K) {
          ans[(1LL << M) - 1] = ans[(1LL << (M + 1)) - 1] = K;
        }else {
          ans[(1LL << M) - 1 + c] = ans[(1LL << M) - 1 - c] = i;
          c++;
        }
      }
      REPOUT(i, 0, 1LL << (M + 1), ans[i], " ");
    }else {
      cout << "-1\n";
    }
  }

  return 0;
}

