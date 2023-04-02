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

  ll N, X; cin >> N >> X;
  // @InpVec(N, A) [q8hfcdup]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [q8hfcdup]
  sort(ALL(A));
  if (X == 0) {
    cout << "Yes\n";
    return 0;
  }
  if (X < 0) X = -X;
  ll i = 0;
  ll j = 0;
  while (true) {
    while (j < N and A[j] - A[i] < X) j++;
    if (j == N or A[j] - A[i] > X) {
      ;
    }else {
      cout << "Yes\n";
      return 0;
    }
    if (j == N) break;
    while (i < N and A[j] - A[i] > X) i++;
    if (i == N or A[j] - A[i] < X) {
      ;
    }else {
      cout << "Yes\n";
      return 0;
    }
    if (i == N) break;
  }
  cout << "No\n";

  return 0;
}

