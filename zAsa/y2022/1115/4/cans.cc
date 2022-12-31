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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s; cin >> s;
  ll N = SIZE(s);
  ll K; cin >> K;
  REP(i, 0, N) {
    if (i == N - 1) {
      char c = 'a' + (((s[i] - 'a') + K) % 26);
      s[i] = c;
    }else if (s[i] == 'a') {
      continue;
    }else {
      ll t = 'z' + 1 - s[i];
      if (t <= K) {
        s[i] = 'a';
        K -= t;
      }
    }
  }
  cout << s << endl;

  return 0;
}

