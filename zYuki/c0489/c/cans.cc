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
    string S; cin >> S;
    ll i = 0;
    while (i < N) {
      if (S[i] != 'C') break;
      S[i] = 'A';
      i++;
      if (i == N) break;
      if (S[i] == 'C') break;
      S[i]++;
      if (S[i] == 'B') break;
      i++;
    }
    cout << S << "\n";
  };

  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

