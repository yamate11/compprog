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
  // @InpVec(N, A) [suoxxkjP]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [suoxxkjP]
  ll M; cin >> M;
  // @InpVec(M, B) [5H1NJ5Bs]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [5H1NJ5Bs]
  ll L; cin >> L;
  // @InpVec(L, C) [dUboDwKM]
  auto C = vector(L, ll());
  for (int i = 0; i < L; i++) { ll v; cin >> v; C[i] = v; }
  // @End [dUboDwKM]
  ll Q; cin >> Q;
  // @InpVec(Q, X) [LJwq7ieS]
  auto X = vector(Q, ll());
  for (int i = 0; i < Q; i++) { ll v; cin >> v; X[i] = v; }
  // @End [LJwq7ieS]

  map<ll, vector<ll>> mp;
  REP(i, 0, Q) mp[X[i]].push_back(i);
  vector<bool> ans(Q, false);
  REP(i, 0, N) REP(j, 0, M) REP(k, 0, L) {
    ll x = A[i] + B[j] + C[k];
    auto it = mp.find(x);
    if (it != mp.end()) {
      for (ll m : it->second) {
        ans[m] = true;
      }
    }
  }
  REPOUT(i, 0, Q, ans[i] ? "Yes" : "No", "\n");

  return 0;
}

