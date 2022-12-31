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

  string A; cin >> A;
  ll n = SIZE(A);
  vector<ll> cnt(26);
  for (char c : A) cnt[c - 'a']++;
  ll t = 0;
  REP(i, 0, 26) t += cnt[i] * (cnt[i] - 1) / 2;
  cout << 1 + n * (n - 1) / 2 - t << endl;

  return 0;
}

