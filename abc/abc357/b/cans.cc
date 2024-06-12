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
  ll num_small = 0;
  ll num_large = 0;
  ll N = ssize(S);
  REP(i, 0, N) {
    if ('a' <= S[i] and S[i] <= 'z') num_small++;
    else num_large++;
  }
  if (num_small < num_large) {
    REP(i, 0, N) {
      if ('a' <= S[i] and S[i] <= 'z') S[i] = S[i] - 'a' + 'A';
    }
  }else {
    REP(i, 0, N) {
      if (not ('a' <= S[i] and S[i] <= 'z')) S[i] = S[i] - 'A' + 'a';
    }
  }
  cout << S << endl;

  return 0;
}

