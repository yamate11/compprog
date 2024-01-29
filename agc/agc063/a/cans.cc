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

int main() {
  ll N; cin >> N;
  string S; cin >> S;
  ll a = 0, b = 0;
  while (a < N + 1 and S[a] != 'A') a++;
  while (b < N + 1 and S[b] != 'B') b++;
  REP(i, 0, N) {
    if (i % 2 == 0) {
      b++; 
      while (b < N + 1 and S[b] != 'B') b++;
    }else {
      a++;
      while (a < N + 1 and S[a] != 'A') a++;
    }
    cout << (a < b ? "Alice\n" : "Bob\n");
  }

  return 0;
}

