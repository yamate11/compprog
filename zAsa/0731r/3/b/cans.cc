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
  vector<ll> cnt(N);
  ll maxm = 0;
  ll grp = 0;
  ll acc = 0;
  REP(i, 0, N) {
    if (S[i] == 'R') {
      ll j = 0;
      while (i - (j + 1) >= 0 and S[i - (j + 1)] == 'A') j++;
      ll k = 0;
      while (i + (k + 1) < N and S[i + (k + 1)] == 'C') k++;
      ll m = min(j, k);
      if (m > 0) {
        cnt[m]++;
        grp++;
        acc += m;
      }
      maxm = max(maxm, m);
    }
  }
  if (grp * 2 <= acc) {
    cout << grp * 2 << endl;
  }else {
    cout << acc << endl;
  }

  return 0;
}

