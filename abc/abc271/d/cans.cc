#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, S; cin >> N >> S;
  // @InpMVec(N, (A, B)) [Nq6obyYm]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [Nq6obyYm]
  vector tbl(N + 1, vector<bool>(S + 1));
  tbl[0][0] = true;
  REP(i, 0, N) {
    REP(j, 0, S) {
      if (not tbl[i][j]) continue;
      if (j + A[i] <= S) tbl[i + 1][j + A[i]] = true;
      if (j + B[i] <= S) tbl[i + 1][j + B[i]] = true;
    }
  }
  if (tbl[N][S]) {
    cout << "Yes\n";
    vector<char> ans(N);
    ll g = S;
    REPrev(i, N-1, 0) {
      if (g - A[i] >= 0 and tbl[i][g - A[i]]) {
        ans[i] = 'H';
        g = g - A[i];
      }else {
        ans[i] = 'T';
        g = g - B[i];
      }
    }
    REPOUT(i, 0, N, ans[i], "");
  }else {
    cout << "No\n";
  }

  return 0;
}

