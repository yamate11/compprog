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
  ll pending = 0;
  string ans;
  REP(i, 0, N + 1) {
    if (i == N or S[i] == 'C') {
      REP(j, 0, pending / 2) ans.push_back('A');
      if (pending % 2 != 0) ans.push_back('B');
      if (S[i] == 'C') ans.push_back('C');
      pending = 0;
    }else if (S[i] == 'A') pending += 2;
    else if (S[i] == 'B') pending++;
    else assert(0);
  }
  cout << ans << endl;

  return 0;
}

