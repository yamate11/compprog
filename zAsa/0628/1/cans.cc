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

  auto solve = [&]() -> bool {
    string S; cin >> S;
    if (ssize(S) != 8) return false;
    if (not ('A' <= S[0] and S[0] <= 'Z')) return false;
    if (S[1] == '0') return false;
    REP(i, 1, 7) {
      if (not ('0' <= S[i] and S[i] <= '9')) return false;
    }
    if (not ('A' <= S[7] and S[7] <= 'Z')) return false;
    return true;
  };
  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

