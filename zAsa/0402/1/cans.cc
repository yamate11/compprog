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
  ll tak = 0, aok = 0;
  REP(i, 0, N) {
    if (S[i] == 'T') tak++;
    else aok++;
  }
  string ans;
  if (tak > aok) ans = "T";
  else if (tak < aok) ans = "A";
  else {
    ll tak2 = 0, aok2 = 0;
    REP(i, 0, N) {
      if (S[i] == 'T') tak2++;
      else aok2++;
      if (tak2 == tak) {
        ans = "T";
        break;
      }else if (aok2 == aok) {
        ans = "A";
        break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}

