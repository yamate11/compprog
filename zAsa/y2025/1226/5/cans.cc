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

#if DEBUG
  ll N = 2;
#else
  ll N = 50;
#endif
  ll K; cin >> K;
  ll p = K / N;
  ll q = K % N;
  vector<ll> A(N);
  REP(i, 0, N) A[i] = N - 1 + p;
  REP(i, 0, q) {
    REP(j, 0, N) {
      if (j == i) A[j] += N;
      else A[j] -= 1;
    }
  }
  cout << N << endl;
  REPOUT(i, 0, N, A[i], " ");

  return 0;
}

