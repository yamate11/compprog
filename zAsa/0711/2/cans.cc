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

  auto check = [&]() -> bool {
    string S; cin >> S;
    string T; cin >> T;
    ll N = ssize(S);
    ll i = 0;
    while (i < N and S[i] - 'a' != T[0] - 'A') i++;
    if (i == N) return false;
    i++;
    while (i < N and S[i] - 'a' != T[1] - 'A') i++;
    if (i == N) return false;
    if (T[2] == 'X') return true;
    i++;
    while (i < N and S[i] - 'a' != T[2] - 'A') i++;
    if (i == N) return false;
    return true;
  };
  cout << (check() ? "Yes\n" : "No\n");

  return 0;
}

