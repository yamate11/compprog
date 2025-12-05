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
  string S, T; cin >> S >> T;
  ll cnt = 0;
  REP(i, 0, N) if (S[i] != T[i]) cnt++;
  if (cnt % 2 != 0) {
    cout << -1 << endl;
    return 0;
  }
  string ans;
  ll diffS = 0, diffT = 0;
  REP(i, 0, N) {
    if (S[i] == T[i]) ans += '0';
    else if (diffS * 2 == cnt) ans += S[i];
    else if (diffT * 2 == cnt) ans += T[i];
    else {
      ans += '0';
      if (S[i] == '0') diffT++;
      else if (T[i] == '0') diffS++;
      else assert(0);
    }
  }
  cout << ans << endl;
  return 0;
}

