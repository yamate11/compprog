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
  string S; cin >> S;
  ll R, M; cin >> R >> M;
  assert(R == 0 and M == 1);
  ll cnt1 = 0;
  ll cnt2 = 0;
  for (char c : S) {
    if (c == '(') cnt1++;
    else cnt2++;
  }
  if (N % 2 != 0) {
    cout << -1 << endl;
  }else {
    ll ans = abs(cnt1 - cnt2) / 2;
    cout << ans << endl;
  }


  return 0;
}

