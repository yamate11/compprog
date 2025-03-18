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

  ll M; cin >> M;
  vector<ll> A;
  while (M > 0) {
    A.push_back(M % 3);
    M /= 3;
  }
  ll sz = ssize(A);
  vector<ll> ans;
  REP(i, 0, sz) {
    REP(j, 0, A[i]) {
      ans.push_back(i);
    }
  }
  ll N = ssize(ans);
  cout << N << endl;
  REPOUT(i, 0, N, ans[i], " ");

  return 0;
}

