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

  ll N, P; cin >> N >> P;
  string S; cin >> S;
  reverse(ALL(S));
  if (P == 2 or P == 5) {
    ll ans = 0;
    REP(i, 0, N) {
      if ((S[i] - '0') % P == 0) {
        ans += N - i;
      }
    }
    cout << ans << endl;
  }else {
    vector cnt(P, 0LL);
    cnt[0]++;
    ll cur = 0;
    ll pow = 1;
    REP(i, 0, N) {
      cur = (cur + (S[i] - '0') * pow) % P;
      cnt[cur]++;
      pow = pow * 10 % P;
    }
    ll ans = 0;
    REP(i, 0, P) {
      ans += cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans << endl;
  }

  return 0;
}

