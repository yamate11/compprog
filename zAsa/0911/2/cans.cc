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

  ll N, X, Y, Z; cin >> N >> X >> Y >> Z;
  // @InpVec(N, A) [HmxJB9KS]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [HmxJB9KS]
  // @InpVec(N, B) [fSizLE7P]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [fSizLE7P]

  vector<bool> Q(N, false);
  vector<ll> ord(N);
  REP(i, 0, N) ord[i] = i;
  sort(ALL(ord), [&](ll x, ll y) -> bool {
    if (A[x] != A[y]) return A[x] > A[y];
    return x < y;
  });
  REP(i, 0, X) Q[ord[i]] = true;
  REP(i, 0, N) ord[i] = i;
  sort(ALL(ord), [&](ll x, ll y) -> bool {
    if (Q[x] != Q[y]) return not Q[x];
    if (B[x] != B[y]) return B[x] > B[y];
    return x < y;
  });
  REP(i, 0, Y) {
    assert(Q[ord[i]] == false);
    Q[ord[i]] = true;
  }
  sort(ALL(ord), [&](ll x, ll y) -> bool {
    if (Q[x] != Q[y]) return not Q[x];
    if (A[x] + B[x] != A[y] + B[y]) return A[x] + B[x] > A[y] + B[y];
    return x < y;
  });
  REP(i, 0, Z) {
    assert(Q[ord[i]] == false);
    Q[ord[i]] = true;
  }
  REP(i, 0, N) {
    if (Q[i]) cout << i + 1 << "\n";
  }

  return 0;
}

