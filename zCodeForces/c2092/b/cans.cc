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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    string A, B; cin >> A >> B;
    ll n1 = 0, n2 = 0;
    REP(i, 0, N) {
      if (A[i] == '0') {
        if (i % 2 == 0) n1++;
        else            n2++;
      }
      if (B[i] == '0') {
        if (i % 2 == 0) n2++;
        else            n1++;
      }
    }
    bool ok;
    if (N % 2 == 0) ok = n1 * 2 >= N and n2 * 2 >= N;
    else ok = n1 * 2 >= N and n2 * 2 >= N - 1;
    cout << (ok ? "YES\n" : "NO\n");

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

