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
  string S, T; cin >> S >> T;
  ll cnt01 = 0;
  ll cnt10 = 0;
  REP(i, 0, N) {
    if (S[i] == '0' and T[i] == '1') cnt01++;
    if (S[i] == '1' and T[i] == '0') cnt10++;
  }
  if ((cnt01 + cnt10) % 2 != 0) {
    cout << -1 << endl;
    return 0;
  }
  string U;
  ll lim01 = 0, lim10 = 0;
  if (cnt01 > cnt10) lim01 = (cnt01 - cnt10) / 2;
  else if (cnt01 < cnt10) lim10 = (cnt10 - cnt01) / 2;
  REP(i, 0, N) {
    if (S[i] == T[i]) U += "0";
    else if (S[i] == '1' and T[i] == '0') {
      if (cnt10 <= lim10) U += "1";
      else U += "0";
      cnt10--;
    }else if (S[i] == '0' and T[i] == '1') {
      if (cnt01 <= lim01) U += "1";
      else U += "0";
      cnt01--;
    }else assert(0);
  }
  cout << U << endl;
  return 0;
}

