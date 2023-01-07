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
  string S; cin >> S;
  vector<ll> ans(N);
  ll prev = -1;
  ll i0 = -1;
  ll cnt = 0;
  REP(i, 0, N) {
    if (S[i] == '1') ans[i] = i;
    else {
      cnt++;
      ans[i] = prev;
      if (prev < 0) {
        i0 = i;
      }
      prev = i;
    }
  }
  if (cnt == 1) cout << -1 << endl;
  else {
    if (cnt > 0) ans[i0] = prev;
    REPOUT(i, 0, N, ans[i] + 1, " ");
  }

  return 0;
}

