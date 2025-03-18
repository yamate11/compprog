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
  // @InpVec(M, A) [YvMe3xlx]
  auto A = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; A[i] = v; }
  // @End [YvMe3xlx]
  vector<bool> vec(N + 1);
  REP(i, 0, M) vec[A[i]] = true;
  vector<ll> ans;
  REP(i, 1, N + 1) {
    if (not vec[i]) ans.push_back(i);
  }
  cout << ssize(ans) << endl;
  REPOUT(i, 0, ssize(ans), ans[i], " ");

  return 0;
}

