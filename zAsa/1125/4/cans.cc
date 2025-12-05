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

  ll N, S; cin >> N >> S;
  // @InpMVec(N, (A, B)) [Zy1iUx8i]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [Zy1iUx8i]

  vector<vector<bool>> tbl(N + 1, vector(S + 1, false));
  tbl[0][0] = true;
  REP(i, 0, N) {
    ll a = A[i], b = B[i];
    REP(j, 0, S + 1) if (tbl[i][j]) {
      if (j + a <= S) tbl[i + 1][j + a] = true;
      if (j + b <= S) tbl[i + 1][j + b] = true;
    }
  }
  if (not tbl[N][S]) {
    cout << "No\n";
    return 0;
  }
  string ans;
  ll cur = S;
  REPrev(i, N - 1, 0) {
    if (tbl[i][cur - A[i]]) {
      cur -= A[i];
      ans += 'H';
    }else if (tbl[i][cur - B[i]]) {
      cur -= B[i];
      ans += 'T';
    }else assert(0);
  }
  ranges::reverse(ans);
  cout << "Yes\n";
  cout << ans << endl;
  return 0;
}

