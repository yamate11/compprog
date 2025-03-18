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
  string S, T; cin >> S >> T;
  ll cnt = 0;
  ll pending = 0;
  bool safe = true;
  bool hasA = false;
  REP(i, 0, N) {
    if (S[i] == 'A' and T[i] == 'A') {
      hasA = true;
    }else if (S[i] == 'B' and T[i] == 'B') {
      safe = true;
    }else if (S[i] == 'A' and T[i] == 'B') {
      if (pending > 0) {
        cnt++;
        pending--;
        safe = true;
      }else if (hasA) {
        cnt++;
      }else {
        cout << -1 << endl;
        return 0;
      }
    }else if (S[i] == 'B' and T[i] == 'A') {
      pending++;
      safe = false;
      hasA = true;
    }
  }
  if (pending > 0) {
    if (safe) cnt += pending;
    else {
      cout << -1 << endl;
      return 0;
    }
  }


  cout << cnt << endl;

  return 0;
}

