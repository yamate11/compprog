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

  ll big = 10000;

  ll N, M; cin >> N >> M;
  string S; cin >> S;

  ll plain = M;
  ll logo = big;
  ll vmin = big;
  REP(i, 0, N) {
    if (S[i] == '0') {
      plain = M;
      logo = big;
    }else if (S[i] == '1') {
      if (plain > 0) plain--;
      else logo--;
    }else if (S[i] == '2') {
      logo--;
    }else assert(0);
    vmin = min(vmin, logo);
  }
  cout << big - vmin << endl;

  return 0;
}

