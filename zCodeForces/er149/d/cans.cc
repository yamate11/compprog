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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N; cin >> N;
    string S; cin >> S;
    vector<ll> col(N);
    ll v = 0;
    bool b1 = false, b2 = false;
    REP(i, 0, N) {
      if (v == 0) {
        if (S[i] == '(') {
          b1 = true;
          col[i] = 1;
          v++;
        }
        else {
          b2 = true;
          col[i] = 2;
          v--;
        }
      }else {
        col[i] = col[i - 1];
        if (S[i] == '(') v++;
        else v--;
      }
    }
    if (v != 0) {
      cout << -1 << "\n";
    }else {
      if (not b1 or not b2) {
        cout << 1 << "\n";
        REPOUT(i, 0, N, 1, " ");
      }else {
        cout << 2 << "\n";
        REPOUT(i, 0, N, col[i], " ");
      }
    }
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

