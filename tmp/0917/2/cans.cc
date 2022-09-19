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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> bool {
    string S; cin >> S;
    ll N = SIZE(S);
    ll pre = 0, post = 0;
    for (pre = 0; pre < N and S[pre] == 'a'; pre++);
    for (post = 0; post < N and S[N - post - 1] == 'a'; post++);
    if (pre == N) return true;
    if (pre > post) return false;
    ll p = pre;
    ll q = N - post - 1;
    while (p < q) {
      if (S[p] != S[q]) return false;
      p++;
      q--;
    }
    return true;
  };
  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

