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
  // @InpMVec(M, ((A, dec=1), (B, dec=1))) [xEMVqEuL]
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
  }
  // @End [xEMVqEuL]

  vector fwd(N, vector<ll>());
  vector nbwd(N, 0LL);
  REP(i, 0, M) {
    fwd[A[i]].push_back(B[i]);
    nbwd[B[i]]++;
  }
  priority_queue<ll, vector<ll>, greater<ll>> pque;
  REP(i, 0, N) if (nbwd[i] == 0) pque.push(i);
  vector<ll> ans;
  while (not pque.empty()) {
    ll i = pque.top(); pque.pop();
    ans.push_back(i);
    for (ll j : fwd[i]) {
      if (--nbwd[j] == 0) pque.push(j);
    }
  }
  REPOUT(i, 0, ssize(ans), ans[i] + 1, " ");

  return 0;
}

