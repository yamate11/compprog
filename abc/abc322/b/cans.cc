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

  ll N, M; cin >> N >> M;
  string S, T; cin >> S >> T;
  bool isPre = T.substr(0, N) == S;
  bool isPost = T.substr(M - N, N) == S;
  ll ans;
  if (isPre and isPost) ans = 0;
  else if (isPre and not isPost) ans = 1;
  else if (not isPre and isPost) ans = 2;
  else if (not isPre and not isPost) ans = 3;
  else assert(0);
  cout << ans << endl;

  return 0;
}

