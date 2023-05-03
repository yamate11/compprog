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

  ll N, K; cin >> N >> K;
  ll R, S, P; cin >> R >> S >> P;
  string T; cin >> T;
  ll ans = 0;
  vector<bool> surr(K);
  REP(i, 0, SIZE(T)) {
    ll j = i % K;
    if (i < K or T[i - K] != T[i] or surr[j]) {
      surr[j] = false;
      if (T[i] == 'r') ans += P;
      else if (T[i] == 's') ans += R;
      else ans += S;
    }else {
      surr[j] = true;
    }
  }
  cout << ans << endl;
  return 0;
}

