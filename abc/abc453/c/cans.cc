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
  vector<ll> L(N);
  REP(i, 0, N) {
    cin >> L[i];
    L[i] *= 2;
  }
  ll ans = 0;
  REP(x, 0, 1LL << N) {
    ll cur = 1;
    ll cnt = 0;
    REP(i, 0, N) {
      ll new_pos;
      if (x >> i & 1) {
        new_pos = cur + L[i];
      }else {
        new_pos = cur - L[i];
      }
      if ((cur > 0) != (new_pos > 0)) cnt++;
      cur = new_pos;
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}

