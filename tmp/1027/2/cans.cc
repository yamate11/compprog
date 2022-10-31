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

  auto identify = [&](char c) -> ll {
    if ('a' <= c and c <= 'z') return c - 'a';
    else return c - 'A';
  };

  string S; cin >> S;
  S[0] = 'A' + identify(S[0]);
  REP(i, 1, SIZE(S)) {
    S[i] = 'a' + identify(S[i]);
  }
  cout << S << endl;

  return 0;
}

