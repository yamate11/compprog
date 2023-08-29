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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector vec(N, vector(37, false));
  vector vn(N, 0LL);
  REP(i, 0, N) {
    ll c; cin >> c;
    vn[i] = c;
    REP(j, 0, c) {
      ll a; cin >> a;
      vec[i][a] = true;
    }
  }
  ll X; cin >> X;
  ll k = 100;
  REP(i, 0, N) {
    if (vec[i][X]) k = min(k, vn[i]);
  }
  if (k == 100) {
    cout << 0 << endl;
    return 0;
  }
  vector<ll> ans;
  REP(i, 0, N) {
    if (vec[i][X] and vn[i] == k) ans.push_back(i);
  }
  cout << SIZE(ans) << endl;
  REPOUT(i, 0, SIZE(ans), ans[i] + 1, " ");

  return 0;
}

