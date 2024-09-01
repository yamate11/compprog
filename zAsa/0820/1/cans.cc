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
  // @InpVec(N, A) [sP2rMWAW]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [sP2rMWAW]

  vector<ll> ans;
  ll prev = A[0];
  ans.push_back(prev);
  REP(i, 1, N) {
    if (prev < A[i]) {
      REP(j, prev + 1, A[i]) ans.push_back(j);
    }else {
      REPrev(j, prev - 1, A[i] + 1) ans.push_back(j);
    }
    prev = A[i];
    ans.push_back(prev);
  }
  REPOUT(i, 0, ssize(ans), ans[i], " ");

  return 0;
}

