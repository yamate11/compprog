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
  // @InpVec(N, R, type=double) [CX7J4mmf]
  auto R = vector(N, double());
  for (int i = 0; i < N; i++) { double v; cin >> v; R[i] = v; }
  // @End [CX7J4mmf]

  sort(ALL(R), greater<double>());
  ll i = 0;
  double sum = 0;
  while (i + 1 < N) {
    sum += R[i] * R[i] - R[i + 1] * R[i + 1];
    i += 2;
  }
  if (i == N - 1) sum += R[i] * R[i];
  cout << M_PI * sum << endl;

  return 0;
}

