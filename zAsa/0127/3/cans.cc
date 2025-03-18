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

  vector<string> S(3);
  REP(i, 0, 3) {
    cin >> S[i];
    reverse(ALL(S[i]));
  }
  ll i = 0;
  while (true) {
    if (S[i].empty()) {
      cout << (char)('A' + i) << endl;
      return 0;
    }
    ll j = S[i].back() - 'a';
    S[i].pop_back();
    i = j;
  }
  

  return 0;
}

