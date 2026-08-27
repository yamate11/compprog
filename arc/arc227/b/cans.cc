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
  // @InpVec(N, A) [yHD1vWES]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [yHD1vWES]
  ranges::sort(A);
  vector<ll> ans;
  vector<ll> stack;
  for (ll idx = 0; idx < N; ) {
    assert(A[idx] >= ssize(ans));
    while (ssize(ans) < A[idx]) {
      if (stack.empty()) {
        cout << "No\n";
        return 0;
      }
      ll a = stack.back(); stack.pop_back();
      ans.push_back(a);
    }
    ans.push_back(A[idx]);
    idx++;
    for ( ; idx < N and A[idx] == A[idx - 1]; idx++) stack.push_back(A[idx]);
  }
  while (not stack.empty()) {
    ll a = stack.back(); stack.pop_back();
    ans.push_back(a);
  }
  cout << "Yes\n";
  REPOUT(i, 0, N, ans[i], " ");

  return 0;
}

