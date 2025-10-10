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

  ll N; cin >> N;
  // @InpVec(N - 1, D) [6nw4D3SA]
  auto D = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) { ll v; cin >> v; D[i] = v; }
  // @End [6nw4D3SA]

  vector<ll> A(N);
  REP(i, 0, N - 1) A[i + 1] = A[i] + D[i];
  REP(i, 0, N) {
    vector<ll> line;
    REP(j, i + 1, N) line.push_back(A[j] - A[i]);
    REPOUT(k, 0, ssize(line), line[k], " ");
  }

  return 0;
}

