#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string S; cin >> S;
  string ans;
  for (ll idx = 0; idx < N; ) {
    for (; idx < N and S[idx] == 'C'; idx++) ans.push_back('C');
    if (idx == N) break;
    ll cnt = 0;
    for (; idx < N and S[idx] != 'C'; idx++) {
      if (S[idx] == 'A') cnt += 2;
      else if (S[idx] == 'B') cnt += 1;
    }
    REP(i, cnt / 2) ans.push_back('A');
    REP(i, cnt % 2) ans.push_back('B');
  }
  cout << ans << endl;

  return 0;
}

