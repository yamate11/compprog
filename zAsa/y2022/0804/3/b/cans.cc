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

  ll N; cin >> N;
  vector<ll> K(N);
  REP2(i, 1, N) cin >> K[i];
  vector<ll> A(N);
  ll p = 1, q = 0;
  while (true) {
    while (p + 1 < N and K[p] >= K[p + 1]) p++;
    for (; q < p; q++) A[q] = K[q + 1];
    if (p + 1 == N) {
      A[N - 1] = A[N - 2];
      break;
    }
    while (p + 1 < N and K[p] <= K[p + 1]) p++;
    for (; q < p; q++) A[q] = K[q];
    if (p + 1 == N) {
      A[N - 1] = K[N - 1];
      break;
    }
  }
  for (ll a : A) cout << a << " ";
  cout << endl;

  return 0;
}

