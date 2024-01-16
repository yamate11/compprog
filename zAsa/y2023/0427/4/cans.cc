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

  string S; cin >> S;
  ll N = SIZE(S);
  vector<ll> cnt(26);
  REP(i, 0, N) cnt[S[i] - 'a']++;
  sort(ALL(cnt), greater<ll>());
  ll lim1, lim2;
  if (N % 3 == 0) {
    lim1 = N / 3;
    lim2 = N / 3;
  }else if (N % 3 == 1) {
    lim1 = N / 3 + 1;
    lim2 = N / 3;
  }else if (N % 3 == 2) {
    lim1 = N / 3 + 1;
    lim2 = N / 3 + 1;
  }
  if (cnt[0] <= lim1 and cnt[0] + cnt[1] <= lim1 + lim2) {
    cout << "YES\n";
  }else {
    cout << "NO\n";
  }
  

  return 0;
}

