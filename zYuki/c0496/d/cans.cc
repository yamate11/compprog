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

  ll N, M; cin >> N >> M;
  // @InpVec(2*N + 1, A) [xQyIAWDi]
  auto A = vector(2*N + 1, ll());
  for (int i = 0; i < 2*N + 1; i++) { ll v; cin >> v; A[i] = v; }
  // @End [xQyIAWDi]
  // @InpVec(M, S) [JILFusTG]
  auto S = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; S[i] = v; }
  // @End [JILFusTG]

  vector<bool> mem(N + 1, false);
  REP(i, 0, M) mem[S[i]] = true;
  vector<ll> cands = S;
  ll ans = ssize(cands);
  while (not cands.empty()) {
    ll t = cands.back(); cands.pop_back();
    for (ll a : S) {
      ll x = A[a + t];
      if (not mem[x]) {
        mem[x] = true;
        cands.push_back(x);
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}

