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

  string S; cin >> S;
  ll SET = 1, DICT = 2;
  auto solve = [&]() -> ll {
    if (S[1] == '}')  return DICT;
    ll i = 1;
    ll lev = 1;
    while (true) {
      if (S[i] == '{') lev++;
      else if (S[i] == '}') {
        lev--;
        if (lev == 0) return SET;
      }else {
        if (lev == 1) {
          if (S[i] == ',') return SET;
          else if (S[i] == ':') return DICT;
        }
      }
      i++;
    }
  };
  cout << (solve() == SET ? "set\n" : "dict\n");
  return 0;
}

