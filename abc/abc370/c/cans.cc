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

  string S, T; cin >> S >> T;
  vector<string> ans;
  ll N = ssize(S);
  ll i = 0;
  while (true) {
    while (i < N and S[i] <= T[i]) i++;
    if (i == N) break;
    S[i] = T[i];
    ans.push_back(S);
  }
  i--;
  while (true) {
    while (i >= 0 and S[i] >= T[i]) i--;
    if (i < 0) break;
    S[i] = T[i];
    ans.push_back(S);
  }
  cout << ssize(ans) << endl;
  REP(j, 0, ssize(ans)) {
    cout << ans[j] << "\n";
  }

  return 0;
}

