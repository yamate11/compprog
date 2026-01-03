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

  ll N, M; cin >> N >> M;
  string S; cin >> S;
  ll hasNo = M;
  ll hasLogo = 0;
  ll vmin = 0;
  REP(i, 0, N) {
    if (S[i] == '0') {
      hasNo = M;
      hasLogo = 0;
    }else if (S[i] == '1') {
      if (hasNo > 0) hasNo--;
      else hasLogo--;
    }else if (S[i] == '2') {
      hasLogo--;
    }else assert(0);
    vmin = min(vmin, hasLogo);
  }
  cout << -vmin << endl;

  return 0;
}

