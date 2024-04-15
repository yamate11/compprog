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

  string S; cin >> S;
  ll N = ssize(S);
  vector cnt(26, 0LL);
  REP(i, 0, N) cnt[S[i] - 'a']++;
  vector A(101, 0LL);
  REP(i, 0, 26) {
    if (cnt[i] > 0) A[cnt[i]]++;
  }
  REP(i, 1, 101) {
    if (A[i] != 0 and A[i] != 2) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  return 0;
}

