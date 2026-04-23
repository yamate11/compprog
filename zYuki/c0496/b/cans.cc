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
  // @InpVec(N, P, dec=1) [YWulLHjw]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [YWulLHjw]
  vector A(N, 0LL);
  REP(i, 0, N) A[P[i]] = i;
  vector<ll> ans;
  REP(i, 0, N) {
    REP(j, 0, N - 1) {
      if (A[j] > A[j + 1]) {
        ans.push_back(j);
        swap(A[j], A[j + 1]);
      }
    }
  }
  ranges::reverse(ans);
  cout << "Yes\n";
  cout << ssize(ans) << endl;
  if (ssize(ans) > 0) {
    REPOUT(i, 0, ssize(ans), ans[i] + 1, "\n");
  }


  return 0;
}

