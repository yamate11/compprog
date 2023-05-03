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
  ll cmax = 0;
  ll c = 0;
  REP(i, 0, N + 1) {
    if (i < N and S[i] == 'o') c++;
    else {
      cmax = max(cmax, c);
      c = 0;
      if (i == N) break;
    }
  }
  if (cmax == 0 or cmax == N) {
    cout << -1 << endl;
  }else {
    cout << cmax << endl;
  }

  return 0;
}

