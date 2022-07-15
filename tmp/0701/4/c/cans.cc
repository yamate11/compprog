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

  string s; cin >> s;
  ll K; cin >> K;
  ll N = SIZE(s);
  REP(i, N) {
    if (i == N - 1) {
      char z = 'a' + (s[i] - 'a' + K) % 26;
      s[N - 1] = z;
    }else if (s[i] != 'a') {
      ll c = 26 - (s[i] - 'a');
      if (c <= K) {
        s[i] = 'a';
        K -= c;
      }
    }
  }
  cout << s << endl;

  return 0;
}

