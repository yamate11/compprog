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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    string S; cin >> S;
    REP(i, 1, N - 1) if (S[i - 1] == '1' and S[i + 1] == '1') S[i] = '1';
    ll cmax = 0;
    REP(i, 0, N) if (S[i] == '1') cmax ++;
    REP(i, 1, N - 1) if (S[i - 1] == '1' and S[i + 1] == '1') S[i] = '0';
    ll cmin = 0;
    REP(i, 0, N) if (S[i] == '1') cmin ++;
    cout << cmin << " " << cmax << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

