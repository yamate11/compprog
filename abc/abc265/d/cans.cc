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

  ll N, P, Q, R; cin >> N >> P >> Q >> R;
  // @InpVec(N, A) [a1TMBH8p]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [a1TMBH8p]

  vector S(N + 1, 0LL);
  REP(i, 0, N) S[i + 1] = S[i] + A[i];


  auto search = [&](ll a, ll& b, ll Z) -> bool {
    while (b <= N and S[b] - S[a] < Z) b++;
    return b <= N and S[b] - S[a] == Z;
  };

  ll y = 0, z = 0, w = 0;
  REP(x, 0, N) {
    if (y <= x) y = x + 1;
    if (not search(x, y, P)) continue;
    if (not search(y, z, Q)) continue;
    if (not search(z, w, R)) continue;
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
  return 0;
}

