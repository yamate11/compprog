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

  ll N; cin >> N;
  vector<string> S(N, string(N, ' '));
  REP(i, 1, N + 1) {
    ll j = N + 1 - i;
    if (i <= j) {
      char c = (i % 2 == 0) ? '.' : '#';
      REP(k, i, j + 1) REP(l, i, j + 1) {
        S[k - 1][l - 1] = c;
      }
    }
  }
  REP(i, 0, N) {
    cout << S[i] << "\n";
  }

  return 0;
}

