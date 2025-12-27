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
  // @InpVec(N, A) [dpyaYWOY]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [dpyaYWOY]

  vector<ll> ans;
  REP(i, 0, N - 1) {
    if (A[i] < A[i + 1]) {
      REP(j, A[i], A[i + 1]) ans.push_back(j);
    }else {
      REPrev(j, A[i], A[i + 1] + 1) ans.push_back(j);
    }
  }
  ans.push_back(A[N - 1]);
  REPOUT(i, 0, ssize(ans), ans[i], " ");

  return 0;
}

