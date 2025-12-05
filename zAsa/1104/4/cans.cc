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

  string s; cin >> s;
  ll K; cin >> K;
  REP(i, 0, ssize(s)) {
    if (i == ssize(s) - 1) {
      ll x = s[i] - 'a';
      x = (x + K) % 26;
      s[i] = 'a' + x;
    }else {
      if (s[i] != 'a') {
        ll x = 26 - (s[i] - 'a');
        ll p = min(K, x);
        if (p == x) {
          s[i] = 'a';
          K -= p;
        }
      }
    }
  }
  cout << s << endl;

  return 0;
}

