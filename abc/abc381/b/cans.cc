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

  auto f = [&]() -> bool {
    string S; cin >> S;
    ll N = ssize(S);
    if (N % 2 != 0) return false;
    set<char> ss;
    REP(i, 0, N / 2) {
      ll j = 2 * i;
      ll k = 2 * i + 1;
      if (S[j] != S[k]) return false;
      if (ss.contains(S[j])) return false;
      ss.insert(S[j]);
    }
    return true;
  };
  cout << (f() ? "Yes\n" : "No\n");

  return 0;
}

