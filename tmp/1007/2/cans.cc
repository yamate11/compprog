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

  string S; cin >> S;
  ll N = SIZE(S);
  
  string prev = "";
  ll cnt = 0;
  ll i = 0;
  while (i < N) {
    for (ll j : {1, 2, 3}) {
      string cand = S.substr(i, j);
      if ((i + j == N) or
          (prev != cand and (N - (i + j) >= 4 or cand != S.substr(i + j)))) {
        i += j;
        prev = cand;
        cnt++;
        break;
      }
    }
  }
  cout << cnt << endl;

  return 0;
}

