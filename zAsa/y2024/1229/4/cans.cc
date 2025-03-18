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
  // @InpVec(2*N, A) [xhzCoRVa]
  auto A = vector(2*N, ll());
  for (int i = 0; i < 2*N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [xhzCoRVa]

  vector<ll> ans;
  auto op = [&](ll i) {
    swap(A[i], A[i + 1]);
    ans.emplace_back(i);
  };
  REP(i, 0, N) {
    ll j = 2 * i;
    ll k = 2 * i + 1;
    ll m = 2 * i + 2;
    if (m == 2*N) {
      if (A[j] > A[k]) op(j);
    }else {
      if (A[j] < A[k]) {
        if (A[k] < A[m]) op(k);
      }else {
        if (A[j] > A[m]) op(j);
        else op(k);
      }
    }
  }
  cout << ssize(ans) << endl;
  REPOUT(i, 0, ssize(ans), ans[i] + 1, " ");
  return 0;
}

