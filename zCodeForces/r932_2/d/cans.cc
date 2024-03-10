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
    ll N, C; cin >> N >> C;
    // @InpVec(N, S) [NTAQOZlu]
    auto S = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; S[i] = v; }
    // @End [NTAQOZlu]

    ll tot = (C + 1) * (C + 2) / 2;
    for (ll p : S) tot -= C + 1 - p;
    ll seen_odd = 0, seen_even = 0;
    REP(i, 0, N) {
      ll num_odd = S[i] / 2;
      ll num_even = S[i] - num_odd;
      ll passed_even = num_even - seen_even;
      ll passed_odd  = num_odd  - seen_odd;
      if (S[i] % 2 == 0) tot -= passed_even;
      else               tot -= passed_odd;
      if (S[i] % 2 == 0) seen_even++;
      else               seen_odd++;
    }
    cout << tot << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

