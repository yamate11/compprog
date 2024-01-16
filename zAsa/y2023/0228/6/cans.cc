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

  ll N; cin >> N;
  vector<string> S(N);
  REP(i, 0, N) cin >> S[i];
  vector<ll> nx(N), cs(N);
  REP(i, 0, N) {
    for (char c : S[i]) {
      if (c == 'X') nx[i]++;
      else cs[i] += c - '0';
    }
  }
  vector<ll> ord(N); REP(i, 0, N) ord[i] = i;
  sort(ALL(ord), [&](ll i, ll j) -> bool { return cs[i] * nx[j] < cs[j] * nx[i]; });
  ll ans = 0, tmp = 0;
  REP(i, 0, N) {
    for (char c : S[ord[i]]) {
      if (c == 'X') tmp++;
      else ans += tmp * (c - '0');
    }
  }
  cout << ans << endl;
  return 0;
}

