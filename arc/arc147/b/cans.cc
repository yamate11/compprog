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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, P, dec=1) [D4Tf2tJM]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [D4Tf2tJM]
  using sta = pair<char, ll>;
  vector<sta> ans;
  auto chg = [&](char c, ll p) -> void {
    ll z = (c == 'A') ? 1 : 2;
    ans.emplace_back(c, p);
    swap(P[p], P[p + z]);
  };
  ll p = 0, q = 1;
  while (true) {
    for (; p < N and P[p] % 2 == 0; p += 2);
    if (p >= N) break;
    for (; q < N and P[q] % 2 == 1; q += 2);
    ll pp = p, qq = q;
    for (; pp + 2 < qq; pp += 2) chg('B', pp);
    for (; qq + 2 < pp; qq += 2) chg('B', qq);
    chg('A', min(pp, qq));
  }
  auto bs = [&](ll sft) -> void {
    ll start = ((N - 1 - sft) % 2 == 0) ? N - 1 : N - 2;
    for (ll i = start; i >= 0; i -= 2) {
      for (ll j = sft; j + 2 <= i; j += 2) {
        if (P[j] > P[j + 2]) chg('B', j);
      }
    }
  };
  bs(0);
  bs(1);
  cout << SIZE(ans) << "\n";
  for (auto [c, t] : ans) cout << c << " " << t + 1 << "\n";

  return 0;
}

