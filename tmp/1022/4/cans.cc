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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll T; cin >> T;
  ll x = 0;
  ll y = 0;
  ll cnt = 0;
  ll N = SIZE(S);
  REP(i, 0, N) {
    if (S[i] == 'L') x--;
    else if (S[i] == 'R') x++;
    else if (S[i] == 'U') y++;
    else if (S[i] == 'D') y--;
    else if (S[i] == '?') cnt++;
    else assert(0);
  }
  ll d = abs(x) + abs(y);
  ll vmax = d + cnt;
  ll diff = d - cnt;
  ll vmin;
  if (diff >= 0) vmin = diff;
  else if ((-diff) % 2 == 0) vmin = 0;
  else vmin = 1;
  cout << (T == 1 ? vmax : vmin) << endl;

  return 0;
}

