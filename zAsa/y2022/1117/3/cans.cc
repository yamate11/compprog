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
  vector<ll> ans(N);
  vector<ll> X(N), Y(N);
  ll prev = -1;
  REP(i, 0, N) {
    if (S[i] == 'R') prev = i;
    else X[i] = prev;
  }
  REPrev(i, N - 1, 0) {
    if (S[i] == 'L') prev = i;
    else Y[i] = prev;
  }
  REP(i, 0, N) {
    if (S[i] == 'R') {
      if ((Y[i] - i) % 2 == 0) ans[Y[i]]++;
      else ans[Y[i] - 1]++;
    }else {
      if ((i - X[i]) % 2 == 0) ans[X[i]]++;
      else ans[X[i] + 1]++;
    }
  }
  REPOUT(i, 0, N, ans[i], " ");

  return 0;
}

