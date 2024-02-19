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

  ll N; cin >> N;
  string S; cin >> S;
  if (S[0] == 'B') {
    REP(i, 0, N) {
      if (S[i] == 'A') S[i] = 'B';
      else S[i] = 'A';
    }
  }
  vector T(N, 0LL);
  REP(i, 1, N) T[i] = T[i - 1] + (S[i] == 'A' ? 1 : -1);
  ll ans = 1;
  REP(i, 0, N - 1) {
    if ((T[i] ==  1 and T[i + 1] ==  0) or
        (T[i] ==  0 and T[i + 1] == -1) or
        (T[i] == -1 and T[i + 1] == -2)
        ) ans++;
  }
  cout << ans << endl;

  return 0;
}

